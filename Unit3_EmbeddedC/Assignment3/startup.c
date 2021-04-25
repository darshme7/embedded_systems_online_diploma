/*startup.c Mostafa Mahmoud*/
#include "Platform_Types.h"

extern int main(void);
void Reset_Handler();
void Default_Handler(){
	Reset_Handler();
}
void NMI_Handler() __attribute__((weak,alias("Default_Handler")));;
void H_fault_Handler()__attribute__((weak,alias("Default_Handler")));;
void MM_fault_Handler()__attribute__((weak,alias("Default_Handler")));;
void Bus_fault_Handler()__attribute__((weak,alias("Default_Handler")));;
void Usage_fault_Handler()__attribute__((weak,alias("Default_Handler")));;

extern uint32 _stack_top;
extern uint32 _E_text;
extern uint32 _S_data; 
extern uint32 _E_data;
extern uint32 _S_bss;
extern uint32 _E_bss;

uint32 vectors[] __attribute__((section(".vectors"))) ={
	(uint32)&_stack_top,
	(uint32)&Reset_Handler,
	(uint32)&NMI_Handler,
	(uint32)&H_fault_Handler,
	(uint32)&MM_fault_Handler,
	(uint32)&Bus_fault_Handler,
	(uint32)&Usage_fault_Handler
	
};

void Reset_Handler(){

/*copy data section*/
 uint32 i;
 uint32 DATA_size= (uint8*)&_E_data-(uint8*)&_S_data;
 uint8 *P_src =(uint8*)&_E_text;
 uint8 *P_dst =(uint8*)&_S_data;
 for(i=0;i<DATA_size;i++){
	 *((uint8*)P_dst++)=*((uint8*)P_src++);
	}
/*init bss section*/
uint32 BSS_size=(uint8*)&_E_bss-(uint8*)_S_bss;
P_dst=(uint8*)&_S_bss;
for(i=0;i<BSS_size;i++){
	*((uint8*)P_dst++)=(uint8)0;
}
/*call main()*/
	main();
}