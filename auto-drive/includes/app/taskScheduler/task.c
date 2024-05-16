/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "task.h"
#include "commonMacros.h"
#include "pid.h"
#include "observer.h"
#include "lpf.h"
#include "encoder.h"
#include "pinSettings.h"
#include "gpio.h"
#include "ultrasonic.h"
#include "motor.h"
#include "uart.h"
#include "switch.h"
#include "dial.h"
#include <stdio.h>

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/


/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void taskMotorCtrl(float32 w_ref, uint8 motor_on, uint8 dir)
{
    float32 w_ref_1;
    float32 w_ref_2;

    if (dir == FORWARD)
    {
        w_ref_1 = -w_ref;
        w_ref_2 = w_ref;
    }
    else if (dir == LEFT)
    {
        w_ref_1 = -w_ref;
        w_ref_2 = w_ref * 1.5;
    }
    else if (dir == RIGHT)
    {
        w_ref_1 = -w_ref * 1.50;
        w_ref_2 = w_ref;
    }

    float32 w_1;
    float32 w_lpf_1;
    static float32 w_lpf_prev_1;

    float32 w_2;
    float32 w_lpf_2;
    static float32 w_lpf_prev_2;

    float32 encPos_1;
    float32 w_err_1;

    float32 encPos_2;
    float32 w_err_2;

    float32 v_in_1;
    float32 v_in_2;

    encPos_1 = getEncPos(MOTOR1);
    w_1 = getWHat(MOTOR1);

    encPos_2 = getEncPos(MOTOR2);
    w_2 = getWHat(MOTOR2);

    w_lpf_1 = lowPassFilter(w_1, w_lpf_prev_1, 0.001);
    w_lpf_prev_1 = w_lpf_1;

    w_lpf_2 = lowPassFilter(w_2, w_lpf_prev_2, 0.001);
    w_lpf_prev_2 = w_lpf_2;

    if (w_ref_2 != 0)
    {
        w_err_1 = w_ref_1 - w_lpf_1;
        w_err_2 = w_ref_2 - w_lpf_2;

        v_in_1 = -1 * pidController(MOTOR1, w_err_1, w_ref_1);
        v_in_2 = pidController(MOTOR2, w_err_2, w_ref_2);

        if (v_in_1 < 0)
        {
            v_in_1 = 0;
        }
        if (v_in_1 > 12)
        {
            v_in_1 = 12;
        }

        if (v_in_2 < 0)
        {
            v_in_2 = 0;
        }
        if (v_in_2 > 12)
        {
            v_in_2 = 12;
        }

        if (motor_on == FALSE)
        {
            v_in_1 = v_in_2 = 0;
        }
    }
    else
    {
        v_in_1 = v_in_2 = 0;
    }


    observeMotor(MOTOR1, v_in_1, encPos_1);

    observeMotor(MOTOR2, v_in_2, encPos_2);

    setMotorPower(v_in_1 / 12, v_in_2 / 12);
}

void taskBuzzerCtrl(uint8 buzzer_on, uint8 motor_on)
{
    if (motor_on == TRUE)
    {
        if (buzzer_on == TRUE) {
            togglePin(PIN_BUZZER);
        }
        else
        {
            setPinLow(PIN_BUZZER);
        }
    }
}

void taskUltrasonic(float32 *w_ref, float32 *dist, uint8 motor_on)
{
    static float32 dist_prev;

    if (motor_on == TRUE)
    {
        trigUltrasonic();

        *dist = getUsDist();
        *dist = lowPassFilter(*dist, dist_prev, 0.01);
        dist_prev = *dist;

        if (*dist < 10)
        {
            *w_ref = 0;
        }
    }
}

void taskBuzzerMode(uint32 time_100ms, float32 dist, uint8 *buzzer_on)
{
    if (dist < 10)
    {
        *buzzer_on = TRUE;
    }
    else if (dist < 15)
    {
        *buzzer_on = (time_100ms % 2 == 0) ? TRUE : FALSE;
    }
    else if (dist < 20)
    {
        *buzzer_on = (time_100ms % 3 == 0) ? TRUE : FALSE;
    }
    else if (dist < 25)
    {
        *buzzer_on = (time_100ms % 5 == 0) ? TRUE : FALSE;
    }
    else
    {
        *buzzer_on = FALSE;
    }
}

void taskBluetooth(uint8 *bt_on, uint8 *motor_on, uint32 time_100ms, float32 *w_ref, float32 *w_ref_1, float32 *w_ref_2, uint8 *dir)
{
    if (g_bt_cmd == 'P')
    {
        *bt_on = FALSE;
        g_bt_cmd = '\0';
    }
    else if (g_bt_cmd == 'A')
    {
        *bt_on = TRUE;
        g_bt_cmd = '\0';
    }

    if (*bt_on == TRUE)
    {
        if (g_bt_cmd == 'T')
        {
            *w_ref = ((*w_ref + 100) > 900) ? 900 : *w_ref + 100;
            g_bt_cmd = '\0';
        }
        else if (g_bt_cmd == 'X')
        {
            *w_ref = ((*w_ref - 100) < 0) ? 0 : *w_ref - 100;
            g_bt_cmd = '\0';
        }
        else if (g_bt_cmd == 'C')
        {
            *motor_on = TRUE;
            g_bt_cmd = '\0';
        }
        else if (g_bt_cmd == 'S')
        {
            *motor_on = FALSE;
            g_bt_cmd = '\0';
        }
        else if (g_bt_cmd == 'F')
        {
            *dir = FORWARD;
            g_bt_cmd = '\0';
        }
        else if (g_bt_cmd == 'L')
        {
            *dir = LEFT;
            g_bt_cmd = '\0';
        }
        else if (g_bt_cmd == 'R')
        {
            *dir = RIGHT;
            g_bt_cmd = '\0';
        }
    }

    char str[30];
    static float32 a1, a2, a3, a4, a5, a6, a7, a8, a9;

    a1 = getEncPos(ENC2);
    a3 = (a1 - a2) * 10;
    a2 = a1;
    a4 = lowPassFilter(a3, a5, 0.1);
    a5 = a4;

    a1 = getEncPos(ENC1);
    a6 = (a1 - a7) * 10;
    a7 = a1;
    a8 = lowPassFilter(a6, a9, 0.1);
    a9 = a8;

    sprintf(str, "%.1f %.1f %.1f %.1f\r\n", (float32)time_100ms/10, *w_ref, a4, a8);
    for (int i =0;i < 30; i++)
    {
        _out_uart3(str[i]);
    }
}

void taskSW(uint8 bt_on, uint8 *motor_on)
{
    if ((bt_on == FALSE) && (getSW() == TRUE))
    {
        *motor_on = !*motor_on;
    }
}

void taskDial(uint8 bt_on, uint8 motor_on, float32 dist, float32 *w_ref)
{
    if (bt_on == FALSE)
    {
        if ((motor_on == TRUE) && (dist > 10))
        {
            *w_ref = getWRef();
            setPinHigh(PIN_LED);
        }
        else
        {
            *w_ref = 0;
            setPinLow(PIN_LED);
        }
    }
}
