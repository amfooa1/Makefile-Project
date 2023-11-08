/***********************************************************/
/***************  Name   : Ahmed Fathi *********************/
/***************  Date   : 01/9/2022   *********************/
/***************  STD_TYPES            *********************/
/***********************************************************/ 

#ifndef _STD_TYPES_H
#define _STD_TYPES_H

typedef unsigned char u8 ;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;

typedef signed char s8 ;
typedef signed short int s16;
typedef signed long  int s32;
typedef signed long long int s64;

typedef float f32;
typedef double f64;
typedef long double f128; 

typedef enum 
{
	EOK  ,
	ENOK  ,
	PARAM_OUT_RANGE,
	PARAM_NULL_PTR 
}tenuErrorStatus;

#define NULL_PTR (void *) 0

//#define NULL (void*)0

#define OK 		0
#define	NOK 	1

#define TRUE    1
#define FALSE   0

#endif
