#ifndef INCLUDES_HARDWARE_COMMONMACROS_H_
#define INCLUDES_HARDWARE_COMMONMACROS_H_

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define PI          3.141592f

// 좌/우 엔코더 인덱스
#define ENC1        0
#define ENC2        1

// 좌/우 모터 인덱스
#define MOTOR1      0
#define MOTOR2      1

// 모터 진행 방향
#define FORWARD     0
#define LEFT        1
#define RIGHT       2

// 모터 인가 전압 최대/최소
#define V_MIN       0.0f
#define V_MAX       12.0f

// 블루투스 모터 속도 제어 증감 스텝
#define W_STEP      50.0f

// 모터 각속도 최대/최소
#define W_MAX       700.0f
#define W_MIN       0.0f

#endif /* INCLUDES_HARDWARE_COMMONMACROS_H_ */
