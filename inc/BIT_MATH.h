/***********************************************************/
/***************  Name   : Ahmed Fathi *********************/
/***************  Date   : 01/9/2022   *********************/
/***************  BIT_MATH             *********************/
/***********************************************************/ 

#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(REG,BIT_NO) REG=REG|(1<<BIT_NO)
#define CLR_BIT(REG,BIT_NO) REG=REG&(~(1<<BIT_NO))
#define TOG_BIT(REG,BIT_NO) REG=REG^(1<<BIT_NO)
#define GET_BIT(REG,BIT_NO) (REG>>BIT_NO)&1

#endif
