/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "pid.h"
#include "commonMacros.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
const float32 t_s = 0.001;

/*
 * K_p_chA, K_p_chB : 비례 gain
 * K_i_chA, K_i_chB : 적분 gain
 * K_d_chA, K_d_chB : 미분 gain
 */
const float32 K_p_chA = 2;
const float32 K_i_chA = 0;
const float32 K_d_chA = 0;

const float32 K_p_chB = 2;
const float32 K_i_chB = 0;
const float32 K_d_chB = 0;

float32 g_prev_err_chA;
float32 g_prev_int_err_chA;

float32 g_prev_err_chB;
float32 g_prev_int_err_chB;

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/

// PID Control System
float32 pidController(uint8 channel, float32 err, float32 w_ref)
{
    /*
     * channel : 왼쪽, 오른쪽 모터를 정하는 변수
     * err : 제어 에러
     * w_ref : 목표 값
     */

    float32 ret;
    if (channel == MOTOR1)
    {
        g_prev_int_err_chA = g_prev_int_err_chA + err * t_s;
        ret = ((err * K_p_chA) + (g_prev_int_err_chA * K_i_chA)) + ((err - g_prev_err_chA) / t_s * K_d_chA);

        g_prev_err_chA = err;
    }
    else
    {
        g_prev_int_err_chB = g_prev_int_err_chB + err * t_s;
        ret = ((err * K_p_chB) + (g_prev_int_err_chB * K_i_chB)) + ((err - g_prev_err_chA) / t_s * K_d_chA);

        g_prev_err_chB = err;
    }

    return ret;
}
