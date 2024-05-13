/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "ultrasonic.h"
#include "pinSettings.h"
#include "gpio.h"
#include "extIrq.h"
#include "delay.h"
#include "IfxStm.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
uint64 g_cnt_r = 0;
uint64 g_cnt_f = 0;
float32 g_dist_prev;

/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
IFX_INTERRUPT(ISR_US_R, 0, 140);
void ISR_US_R(void)
{
    g_cnt_r = getCurStmTicks();
}

IFX_INTERRUPT(ISR_US_F, 0, 141);
void ISR_US_F(void)
{
    g_cnt_f = getCurStmTicks() - g_cnt_r;
}

void initUltrasonic(void)
{
    setPinOutput(PIN_US_TRIG);
    initExtIrq(PIN_US_ECHO_R, risingEdgeDetection, 140);
    initExtIrq(PIN_US_ECHO_F, fallingEdgeDetection, 141);
}

void trigUltrasonic(void)
{
    setPinLow(PIN_US_TRIG);
    delayUs(2);
    setPinHigh(PIN_US_TRIG);
    delayUs(10);
    setPinLow(PIN_US_TRIG);
}

float32 getUsDist(void)
{
    float32 dist = (g_cnt_f / IfxStm_getFrequency(&MODULE_STM0) * 1000000 / 58.8235);
    if (dist > 250)
    {
        dist = g_dist_prev;
    }
    else
    {
        g_dist_prev = dist;
    }
    return dist;
}
