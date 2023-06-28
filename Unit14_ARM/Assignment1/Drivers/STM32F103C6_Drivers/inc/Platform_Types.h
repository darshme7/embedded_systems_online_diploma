#ifndef  INC_PLATFORM_TYPES_H_
#define  INC_PLATFORM_TYPES_H_

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef NULL
#define NULL ((void *)(0x00))
#endif

typedef unsigned char			boolean;
typedef unsigned char			uint8;
typedef unsigned short			uint16;
typedef unsigned long			uint32;
typedef unsigned long long		uint64;

typedef signed char				sint8;
typedef signed short			sint16;
typedef signed long				sint32;
typedef signed long long		sint64;

typedef unsigned char			uint8_least;
typedef unsigned short			uint16_least;
typedef unsigned long			uint32_least;
 
typedef signed char				sint8_least;
typedef signed short			sint16_least;
typedef signed long				sint32_least;

typedef float                   float32;
typedef double                  float64;

#endif /* INC_PLATFORM_TYPES_H_ */
