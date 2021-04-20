#include "uart.h"

#define UART0 *((volatile unsigned int * const)((unsigned int *)(0x101f1000)))

void Uart_send_string(unsigned char *p_string){
	
	while(*p_string !='\0'){
		UART0 = (unsigned int)(*p_string);
        p_string++;
	}
}