/**********************************************************************************************************************
 * \file task.h
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

#ifndef INCLUDES_APP_TASKSCHEDULER_TASK_H_
#define INCLUDES_APP_TASKSCHEDULER_TASK_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

/**
 * @ brief : 관측기로 각속도를 계산하여 w_ref와 w_h 사이의 오차를 regulation하는 pi 제어를 수행
 *
 * @ param float32 w_ref  : 목표 각속도
 * @ param uint8 motor_on : 모터 on/off 모드
 * @ param uint8 dir      : 좌/우, 직진을 가리키는 방향
 *
 * @ return 없음
 */
extern void taskMotorCtrl(const float32 w_ref, const uint8 motor_on, const uint8 dir);

/**
 * @ brief : 모터가 동작하는 중에, 부저가 켜지면, 1000hz의 부저 출력
 *
 * @ param uint8 buzzer_on : 부저 on/off 모드
 * @ param uint8 motor_on  : 모터 on/off 모드
 *
 * @ return 없음
 */
extern void taskBuzzerCtrl(const uint8 buzzer_on, const uint8 motor_on);

/**
 * @ brief : 모터 동작 중에, 초음파 센서로 거리를 측정하여, 10cm 이하의 거리에 장애물이 감지되면 목표 속도를 0으로 설정
 *
 * @ param float32 *w_ref : 목표 각속도
 * @ param float32 *dist  : 초음파 센서 거리
 * @ param uint8 motor_on : 모터 on/off 모드
 *
 * @ return 없음
 */
extern void taskUltrasonic(float32 *w_ref, const float32 *dist, const uint8 motor_on);

/**
 * @ brief : 장애물 거리 기반으로 부저 on/off 모드를 조작하여 부저 주파수 결정
 *
 * @ param uint32 time_100ms : 0.1s 단위의 시스템 동작 시간
 * @ param float32 dist      : 초음파 센서 거리
 * @ param uint8 *buzzer_on  : 부저 on/off 모드
 *
 * @ return 없음
 */
extern void taskBuzzerMode(const uint32 time_100ms, const float32 dist, uint8 *buzzer_on);

/**
 * @ brief : 블루투스 제어를 on/off 할 수 있고, 블루투스 제어가 on인 동안은 모터의 동작을 제어할 수 있음
 *
 * @ param uint8 *bt_on      : 블루투스 제어 on/off 모드
 * @ param uint8 *motor_on   : 모터 제어 on/off 모드
 * @ param uint32 time_100ms : 0.1s 단위의 시스템 동작 시간
 * @ param float32 *w_ref    : 목표 각속도
 * @ param uint8 *dir        : rc카 진행 방향
 *
 * @ return 없음
 */
extern void taskBluetooth(uint8 *bt_on, uint8 *motor_on, const uint32 time_100ms, float32 *w_ref, uint8 *dir);

/**
 * @ brief : 스위치로 모터 동작 on/off 제어
 *
 * @ param uint8 bt_on      : 블루투스 제어 on/off 모드
 * @ param uint8 *motor_on   : 모터 제어 on/off 모드
 *
 * @ return 없음
 */
extern void taskSW(const uint8 bt_on, uint8 *motor_on);

/**
 * @ brief : 다이얼로 모터의 목표 각속도 설정
 *
 * @ param uint8 bt_on      : 블루투스 제어 on/off 모드
 * @ param uint8 *motor_on  : 모터 제어 on/off 모드
 * @ param float32 dist     : 장애물과의 거리
 * @ param float32 *w_ref   : 목표 각속도
 *
 * @ return 없음
 */
extern void taskDial(const uint8 bt_on, const uint8 motor_on, const float32 dist, float32 *w_ref);
#endif /* INCLUDES_APP_TASKSCHEDULER_TASK_H_ */
