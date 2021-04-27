#include "Platform_Types.h"

#define SYSCTL_RCG2_R     *((volatile uint32*)0x400FE108)
#define GPIO_PORTF_DIR_R  0x40025400
#define GPIO_PORTF_DEN_R  0x4002551C
#define GPIO_PORTF_DATA_R 0x400253FC


typedef union{
	volatile uint32 ALL_FIELDS;
	struct {
		volatile uint32 :3;
		volatile uint32 pin3:1;
	}pins;
}GPIO_PF_Rs;



volatile GPIO_PF_Rs * dir_R= (volatile GPIO_PF_Rs *)(GPIO_PORTF_DIR_R);
volatile GPIO_PF_Rs * den_R= (volatile GPIO_PF_Rs *)(GPIO_PORTF_DEN_R);
volatile GPIO_PF_Rs * data_R= (volatile GPIO_PF_Rs *)(GPIO_PORTF_DATA_R);

static uint32 i;

int main(void)
{
	SYSCTL_RCG2_R=0x20;
	
	for(i=0;i<200;i++);
	dir_R->pins.pin3=1;
	den_R->pins.pin3=1;
	
	while(1){
		data_R->pins.pin3=1;
		for(i=0;i<200000;i++);
		data_R->pins.pin3=0;
		for( i=0;i<200000;i++);
	}
}
