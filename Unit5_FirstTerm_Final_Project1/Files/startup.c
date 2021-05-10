//startup.c

#include "Platform_Types.h"

extern int main(void);

void Reset_Handler(void);

extern uint32 _stack_top;
extern uint32 _E_text;
extern uint32 _S_data;
extern uint32 _E_data;
extern uint32 _S_bss;
extern uint32 _E_bss;

void Default_Handler(void){

	Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));
void Hard_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));
void MM_Handler(void) __attribute__((weak,alias("Default_Handler")));
void Bus_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));

uint32 vectors[] __attribute__((section(".vectors"))) = {
	(uint32)&_stack_top,
	(uint32)Reset_Handler,
	(uint32)NMI_Handler,
	(uint32)Hard_Fault_Handler,
	(uint32)MM_Handler,
	(uint32)Bus_Fault_Handler,
	(uint32)Usage_Fault_Handler
};

void Reset_Handler(void){

	uint8 *pFlash = ((uint8*)(&_E_text));
	uint8 *pRam   = ((uint8*)(&_S_data)) ;
	uint8 size    = (uint8)(((uint8*)&_E_data)-((uint8*)&_S_data));
	uint8 i;
	

	for(i=0;i<size;i++){
		*pRam = *pFlash;
		pFlash++;
		pRam++;
	}

	pRam = ((uint8*)(&_E_data)) ;
	size = (uint32)(((uint8*)&_E_bss)-((uint8*)&_S_bss));

	for(i=0;i<size;i++){
		*pRam = (uint8)0;
		pRam++;
	}

	main();
}