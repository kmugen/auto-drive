/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "motor.h"
#include "gpio.h"
#include "pinSettings.h"
#include "pwmTom.h"
#include "commonMacros.h"

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void initMotor(void)
{
    // 모터 방향, 브레이크, 파워 핀 설정
    setPinOutput(PIN_MOTOR1_DIR);
    setPinLow(PIN_MOTOR1_DIR);

    setPinOutput(PIN_MOTOR2_DIR);
    setPinHigh(PIN_MOTOR2_DIR);

    setPinOutput(PIN_MOTOR1_BRAKE);
    setPinLow(PIN_MOTOR1_BRAKE);

    setPinOutput(PIN_MOTOR2_BRAKE);
    setPinLow(PIN_MOTOR2_BRAKE);

    initTomPwm(&PIN_MOTOR1_POWER, 0);
    initTomPwm(&PIN_MOTOR2_POWER, 0);
}
