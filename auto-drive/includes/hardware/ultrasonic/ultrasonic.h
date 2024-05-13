#ifndef INCLUDES_HARDWARE_ULTRASONIC_ULTRASONIC_H_
#define INCLUDES_HARDWARE_ULTRASONIC_ULTRASONIC_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxStm.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
 
/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
extern void initUltrasonic(void);
extern void trigUltrasonic(void);
extern float32 getUsDist(void);

#endif /* INCLUDES_HARDWARE_ULTRASONIC_ULTRASONIC_H_ */
