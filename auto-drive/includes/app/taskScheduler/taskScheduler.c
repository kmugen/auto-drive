/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "taskScheduler.h"
#include "stm.h"
#include "commonMacros.h"
#include "task.h"
#include "Ifx_Types.h"
#include "encoder.h"

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
 typedef struct
{
        uint32 cnt_1ms;
        uint32 cnt_10ms;
        uint32 cnt_100ms;
}TestCnt;

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
TestCnt stTestCnt;

float32 g_w_ref;

float32 g_w_ref_1;
float32 g_w_ref_2;

float32 g_dist;

uint8 g_motor_on = TRUE;

uint8 g_bt_on = FALSE;
boolean g_buzzer_on = FALSE;

uint8 g_dir = FORWARD;

char str[40];
/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
static void Task1ms(void);
static void Task10ms(void);
static void Task100ms(void);

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void appNoTask(void)
{
    countEncTicks();
}

static void Task1ms(void)
{
    taskMotorCtrl(g_w_ref, g_motor_on, g_dir);

    taskBuzzerCtrl(g_buzzer_on, g_motor_on);

    stTestCnt.cnt_1ms++;
}

static void Task10ms(void)
{
    taskUltrasonic(&g_w_ref, &g_dist, g_motor_on);

    stTestCnt.cnt_10ms++;
}

static void Task100ms(void)
{
    taskBuzzerMode(stTestCnt.cnt_100ms, g_dist, &g_buzzer_on);

    taskBluetooth(&g_bt_on, &g_motor_on, stTestCnt.cnt_100ms, &g_w_ref, &g_dir);

    taskSW(g_bt_on, &g_motor_on);

    taskDial(g_bt_on, g_motor_on, g_dist, &g_w_ref);


    stTestCnt.cnt_100ms++;
}

void taskScheduler(void)
{
    if(schedulingInfo.f_1ms == 1)
    {
        schedulingInfo.f_1ms = 0;
        Task1ms();

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
}
