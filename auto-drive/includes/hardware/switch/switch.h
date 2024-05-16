#ifndef INCLUDES_HARDWARE_SWITCH_SWITCH_H_
#define INCLUDES_HARDWARE_SWITCH_SWITCH_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"
#include "gpio.h"
#include "pinSettings.h"

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
static void initSwitch(void)
{
    setPinInput(PIN_SW);
}

extern uint8 getSW(void);

#endif /* INCLUDES_HARDWARE_SWITCH_SWITCH_H_ */