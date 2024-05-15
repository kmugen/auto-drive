/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "taskScheduler.h"
#include "stm.h"
#include "encoder.h"
#include "uart.h"
#include <stdio.h>
#include "motor.h"
#include "lpf.h"
#include "pid.h"
#include "commonMacros.h"
#include "observer.h"
#include "gpio.h"
#include "pinSettings.h"
#include "ultrasonic.h"

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
 typedef struct
{
        uint32 cnt_1ms;
        uint32 cnt_10ms;
        uint32 cnt_100ms;
}TestCnt;

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
TestCnt stTestCnt;

float32 w_ref_1;
float32 w_ref_lpf_1;
float32 w_ref_lpf_prev_1;

float32 w_ref_2;
float32 w_ref_lpf_2;
float32 w_ref_lpf_prev_2;

float32 w_1;
float32 w_lpf_1;
float32 w_lpf_prev_1;

float32 w_2;
float32 w_lpf_2;
float32 w_lpf_prev_2;

float32 encPos_1;
float32 prev_encPos_1;
float32 w_err_1;

float32 encPos_2;
float32 prev_encPos_2;
float32 w_err_2;

float32 v_in_1;
float32 v_in_2;

float32 g_dist;

float32 tmp;
float32 tmp_prev;

float32 tmp_lpf;
float32 tmp_lpf_prev;
boolean buzzer_on = FALSE;

char str[40];
/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
static void Task1ms(void);
static void Task10ms(void);
static void Task100ms(void);

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void appNoTask(void)
{
    countEncTicks();
}

static void Task1ms(void)
{
    static float32 w_ss_1 = -200 * PI;
    static float32 w_ss_2 = 930;

    if (stTestCnt.cnt_1ms < 2000 || stTestCnt.cnt_1ms >= 17000)
    {
        w_ref_1 = 50.0;
        w_ref_2 = 50.0;
    }
    else if (stTestCnt.cnt_1ms < 7000)
    {
        w_ref_1 = (w_ss_1 - 50) / 5 * (stTestCnt.cnt_1ms - 2000) / 1000 + 50;
        w_ref_2 = (w_ss_2 - 50) / 5 * (stTestCnt.cnt_1ms - 2000) / 1000 + 50;
    }
    else if (stTestCnt.cnt_1ms < 12000)
    {
        w_ref_1 = w_ss_1;
        w_ref_2 = w_ss_2;
    }
    else if (stTestCnt.cnt_1ms < 17000)
    {
        w_ref_1 = (w_ss_1 - 50) / 5 * (17000 - stTestCnt.cnt_1ms) / 1000 + 50;
        w_ref_2 = (w_ss_2 - 50) / 5 * (17000 - stTestCnt.cnt_1ms) / 1000 + 50;
    }
////
////    w_ref_lpf_1 = lowPassFilter(w_ref_1, w_ref_lpf_prev_1);
////    w_ref_lpf_prev_1 = w_ref_lpf_1;
////
    w_ref_lpf_2 = lowPassFilter(w_ref_2, w_ref_lpf_prev_2, 0.001);
    w_ref_lpf_prev_2 = w_ref_lpf_2;
//
//    encPos_1 = getEncPos(ENC1);
//    w_1 = (encPos_1 - prev_encPos_1) * 1000;
//    prev_encPos_1 = encPos_1;
//
//    encPos_2 = getEncPos(ENC2);
//    w_2 = (encPos_2 - prev_encPos_2) * 1000;
//    prev_encPos_2 = encPos_2;
//
    w_2 = getWHat(MOTOR2);
//    tmp = lowPassFilter(tmp, tmp_prev, 0.001);
//    tmp_prev = tmp;
//
//    w_lpf_1 = lowPassFilter(w_1, w_lpf_prev_1);
//    w_lpf_prev_1 = w_lpf_1;
//
    w_lpf_2 = lowPassFilter(w_2, w_lpf_prev_2, 0.001);
    w_lpf_prev_2 = w_lpf_2;
//    tmp_lpf = lowPassFilter(tmp, tmp_lpf_prev, 0.001);
//    tmp_lpf_prev = tmp_lpf;
//
    if (w_ref_lpf_2 != 0)
    {
//    w_err_1 = w_ref_lpf_1 - w_lpf_1;
    w_err_2 = w_ref_lpf_2 - w_lpf_2;
//      w_err_2 = w_ref_lpf_2 - tmp_lpf;
//
//    v_in_1 = -1 * pidController(MOTOR1, w_err_1, w_ref_lpf_1);
    v_in_2 = pidController(MOTOR2, w_err_2, w_ref_lpf_2);
//    v_in_2 = w_ref_lpf_2 / 920 * 12;
//    if (v_in_1 < 0)
//    {
//        v_in_1 = 0;
//    }
//    if (v_in_1 > 12)
//    {
//        v_in_1 = 12;
//    }
//
//    if (v_in_2 < 0)
//    {
//        v_in_2 *= -1;
//        setPinLow(PIN_MOTOR2_DIR);
//    }
//    else
//    {
//        setPinHigh(PIN_MOTOR2_DIR);
//    }
    if (v_in_2 < 0)
    {
        v_in_2 = 0;
    }
    if (v_in_2 > 12)
    {
        v_in_2 = 12;
    }
    }
//    if (stTestCnt.cnt_1ms >= 15000)
//    {
//        v_in = 0;
//    }

    encPos_1 = getEncPos(MOTOR1);
    observeMotor(MOTOR2, v_in_1, encPos_1);

    encPos_2 = getEncPos(MOTOR2);
    observeMotor(MOTOR2, v_in_2, encPos_2);


    // setMotorPower(v_in_1 / 12, v_in_2 / 12);
    setMotorPower(0, v_in_2 / 12);

//    if (buzzer_on == TRUE) {
//        togglePin(PIN_BUZZER);
//    }
//    else
//    {
//        setPinLow(PIN_BUZZER);
//    }

    stTestCnt.cnt_1ms++;
}

static void Task10ms(void)
{
    static float32 a1, a2, a3, a4, a5, a6, a7;
    //
        a1 = getEncPos(ENC2);
        a3 = (a1 - a2) * 100;
        a2 = a1;
        a4 = lowPassFilter(a3, a5, 0.01);
        a5 = a4;
        a6 = getWHat(MOTOR2);
        a6 = lowPassFilter(a6, a7, 0.01);
        a7 = a6;
    sprintf(str, "%.2f %.1f %.1f\r\n", (float32)stTestCnt.cnt_10ms/100, w_ref_lpf_2, a3);
    for (int i =0;i < 20; i++)
    {
        _out_uart3(str[i]);
    }
    stTestCnt.cnt_10ms++;
}

static void Task100ms(void)
{

//


//    trigUltrasonic();
//    static float32 dist_prev;
//    g_dist = getUsDist();
//    g_dist = lowPassFilter(g_dist, dist_prev);
//    dist_prev = g_dist;
//
//    if (g_dist < 10)
//    {
//        buzzer_on = TRUE;
//    }
//    else if (g_dist < 15)
//    {
//        if (stTestCnt.cnt_100ms % 2 == 0)
//        {
//            buzzer_on = TRUE;
//        }
//        else
//        {
//            buzzer_on = FALSE;
//        }
//    }
//    else if (g_dist < 20)
//    {
//        if (stTestCnt.cnt_100ms % 3 == 0)
//        {
//            buzzer_on = TRUE;
//        }
//        else
//        {
//            buzzer_on = FALSE;
//        }
//    }
//    else if (g_dist < 25)
//    {
//        if (stTestCnt.cnt_100ms % 5 == 0)
//        {
//            buzzer_on = TRUE;
//        }
//        else
//        {
//            buzzer_on = FALSE;
//        }
//    }
//    else
//    {
//        buzzer_on = FALSE;
//    }
    stTestCnt.cnt_100ms++;
}

void taskScheduler(void)
{
    if(schedulingInfo.f_1ms == 1)
    {
        schedulingInfo.f_1ms = 0;
        Task1ms();

        if(schedulingInfo.f_10ms == 1)
        {
            schedulingInfo.f_10ms = 0;
            Task10ms();
        }

        if(schedulingInfo.f_100ms == 1)
        {
            schedulingInfo.f_100ms = 0;
            Task100ms();
        }
    }
}
