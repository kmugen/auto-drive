/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "pid.h"
#include "commonMacros.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
const float32 t_s = 0.001;

const float32 K_p_chA = 0.5;
const float32 K_i_chA = 0.1;
const float32 K_d_chA = 1;

const float32 K_p_chB = 0.5;
const float32 K_i_chB = 0.1;
const float32 K_d_chB = 1;

float32 g_prev_err_chA;
float32 g_prev_int_err_chA;

float32 g_prev_err_chB;
float32 g_prev_int_err_chB;

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
float32 pidController(uint8 channel, float32 err, float32 w_ref)
{
    float32 ret;
    if (channel == MOTOR1)
    {
        g_prev_int_err_chA = g_prev_int_err_chA + err * t_s;
        if (g_prev_int_err_chA > 10)
        {
            g_prev_int_err_chA = 10;
        }
        ret = (err * K_p_chA) + (g_prev_int_err_chA * K_i_chA) + ((err - g_prev_err_chA) / t_s * K_d_chA);

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
