#include "taskScheduler.h"
#include "stm.h"
#include "Ifx_Types.h"

typedef struct
{
        uint32 cnt_100us;
        uint32 cnt_1ms;
        uint32 cnt_10ms;
        uint32 cnt_100ms;
}TestCnt;

static void Task100us(void);
static void Task1ms(void);
static void Task10ms(void);
static void Task100ms(void);

TestCnt stTestCnt;

static void Task100us(void)
{
    stTestCnt.cnt_100us++;
}

static void Task1ms(void)
{
    stTestCnt.cnt_1ms++;
}

static void Task10ms(void)
{
    stTestCnt.cnt_10ms++;
}

static void Task100ms(void)
{
    stTestCnt.cnt_100ms++;
}

void taskScheduler(void)
{
    if(schedulingInfo.f_100us == 1)
    {
        schedulingInfo.f_100us = 0;
        Task100us();
    }

    if(schedulingInfo.f_1ms == 1)
    {
        schedulingInfo.f_1ms = 0;
        Task1ms();
    }

    if(schedulingInfo.f_10ms == 1)
    {
        schedulingInfo.f_10ms = 0;
        Task10ms();
    }

    if(schedulingInfo.f_100ms == 1)
    {
        schedulingInfo.f_100ms = 0;
        Task100ms();
    }
}
