#ifndef SRC_TC275_GPIO_GPIO_H_
#define SRC_TC275_GPIO_GPIO_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "IfxPort_PinMap.h"
#include "IfxPort.h"
#include "gpioMap.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
/* gpio 모드 */
#define INPUT       0x10     /* input pull-up */
#define OUTPUT      0x80     /* output push-pull */

/* gpio 핀 state */
#define HIGH        IfxPort_State_high
#define LOW         IfxPort_State_low
#define TOGGLED     IfxPort_State_toggled

/* gpio 타입 */
#define gpio_t      IfxPort_Pin

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
extern void setPinMode(gpio_t pin, uint8 mode);

/*********************************************************************************************************************/
/*------------------------------------------Inline Function Implementation-------------------------------------------*/
/*********************************************************************************************************************/
static inline void setPinInput(gpio_t pin)
{
    setPinMode(pin, INPUT);
}

static inline void setPinOutput(gpio_t pin)
{
    setPinMode(pin, OUTPUT);
}

static inline void setPinState(gpio_t pin, uint32 state)
{
    pin.port->OMR.U = (state << pin.pinIndex);
}

static inline void setPinHigh(gpio_t pin)
{
    setPinState(pin, HIGH);
}

static inline void setPinLow(gpio_t pin)
{
    setPinState(pin, LOW);
}

static inline void togglePin(gpio_t pin)
{
    setPinState(pin, TOGGLED);
}

static inline boolean getPinState(gpio_t pin)
{
    return IfxPort_getPinState(pin.port, pin.pinIndex);
}

#endif /* SRC_TC275_GPIO_GPIO_H_ */
