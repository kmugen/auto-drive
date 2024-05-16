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

}

void taskBuzzerCtrl(uint8 buzzer_on, uint8 motor_on);
void taskUltrasonic(float32 *w_ref, float32 *dist, uint8 motor_on);
void taskBuzzerMode(uint32 time_100ms, float32 dist, uint8 *buzzer_on);
void taskBluetooth(uint8 *bt_on, uint8 *motor_on, uint32 time_100ms, float32 *w_ref, uint8 *dir);
void taskSW(uint8 bt_on, uint8 *motor_on);
void taskDial(uint8 bt_on, uint8 motor_on, float32 dist, float32 *w_ref);
