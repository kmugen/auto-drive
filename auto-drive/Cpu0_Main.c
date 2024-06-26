#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Ifx_Types.h"
#include "gpio.h"
#include "pinSettings.h"
#include "encoder.h"
#include "uart.h"
#include "stm.h"
#include "taskScheduler.h"
#include "motor.h"
#include "buzzer.h"
#include "ultrasonic.h"
#include "switch.h"
#include "adc.h"
#include "dial.h"

IfxCpu_syncEvent g_cpuSyncEvent = 0;


void core0_main(void)
{
    IfxCpu_enableInterrupts();
    
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);

    // 모듈과 하드웨어들 초기화
    initEncoder();
    initMotor();
    initBuzzer();
    initUltrasonic();
    initSwitch();
    initDial();
    setPinOutput(PIN_LED);
    _init_uart3();
    initStm();

    IfxCpu_enableInterrupts();
    while(1)
    {
        appNoTask();        // 항상 수행하는 태스크
        taskScheduler();    // 주기적으로 수행하는 태스크

    }
}

