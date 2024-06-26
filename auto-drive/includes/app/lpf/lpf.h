#ifndef SRC_APP_LPF_LPF_H_
#define SRC_APP_LPF_LPF_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Platform_Types.h"

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

// 저역 통과 필터 LPF
extern float32 lowPassFilter(const float32 w_ref, const float32 prevLpf, const float32 t_s);

#endif /* SRC_APP_LPF_LPF_H_ */
