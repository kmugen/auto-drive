#ifndef SRC_APP_OBSERVER_OBSERVER_H_
#define SRC_APP_OBSERVER_OBSERVER_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
extern float32 g_theta_h[2];
extern float32 g_w_h[2];
extern float32 g_i_h[2];

extern float32 g_int_theta_h[2];
extern float32 g_int_w_h[2];
extern float32 g_int_i_h[2];

extern float32 theta_tilde;
/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
 
/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
extern void observeMotor(uint8 chn, float32 v_in, float32 theta);

extern float32 getThetaHat(uint8 chn);

extern float32 getWHat(uint8 chn);

extern float32 getIHat(uint8 chn);

#endif /* SRC_APP_OBSERVER_OBSERVER_H_ */
