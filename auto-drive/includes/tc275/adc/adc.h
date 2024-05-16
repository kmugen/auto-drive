#ifndef SRC_TC275_ADC_ADC_H_
#define SRC_TC275_ADC_ADC_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Platform_Types.h"
#include "IfxVadc_Adc.h"

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
typedef struct
{
    uint8 group_id;
    uint8 chn_id;
    IfxVadc_Adc_Channel chn;
} adc_t;

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
extern adc_t SAR0_0;
extern adc_t SAR0_1;
extern adc_t SAR0_2;
extern adc_t SAR0_3;

extern adc_t SAR2_4;
extern adc_t SAR2_5;

extern adc_t SAR3_0;
extern adc_t SAR3_1;

extern adc_t SAR4_4;
extern adc_t SAR4_5;
extern adc_t SAR4_6;
extern adc_t SAR4_7;

extern adc_t SAR5_4;
extern adc_t SAR5_5;
extern adc_t SAR5_6;
extern adc_t SAR5_7;

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void initAdc(adc_t *pin);
uint16 getAdc(adc_t *pin);

#endif /* SRC_TC275_ADC_ADC_H_ */