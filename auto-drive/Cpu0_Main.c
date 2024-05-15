#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "encoder.h"
#include "uart.h"
#include "stm.h"
#include "taskScheduler.h"
#include "motor.h"
#include "buzzer.h"
#include "ultrasonic.h"

IfxCpu_syncEvent g_cpuSyncEvent = 0;

void core0_main(void)
{
    IfxCpu_enableInterrupts();
    
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    initEncoder();
    initMotor();
//    initBuzzer();
//    initUltrasonic();
    _init_uart3();
    initStm();

    IfxCpu_enableInterrupts();
    while(1)
    {
        appNoTask();
        taskScheduler();
    }
}
