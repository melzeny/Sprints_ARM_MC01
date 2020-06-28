#ifndef NVIC_CFG
#define NVIC_CFG

/*
*  Please choose from th followings
*  NVIC_GROUPING_SYSTEM_XXX  : [0-7]Groups , [0]Subgroup
*  NVIC_GROUPING_SYSTEM_XXY  : [0-3]Groups , [0-1]Subgroup
*  NVIC_GROUPING_SYSTEM_XYY  : [0-1]Groups , [0-3]Subgroup
*  NVIC_GROUPING_SYSTEM_YYY  : [0]Groups   , [0-7]Subgroup Non-Preemption system
*/


#define NVIC_GROUPING_SYSTEM             NVIC_GROUPING_SYSTEM_YYY



#define NVIC_ACTIVATED_INT_SIZE           3


#endif
