/*linker script CortexM4
Mostafa Mahmoud */

MEMORY
{
flash (rx) : ORIGIN = 0x00000000, LENGTH = 256k
sram (rwx) : ORIGIN = 0x20000000, LENGTH = 32k
}

SECTIONS{

   .text :
   {
    *(.vectors*)
    *(.text*)
	*(.rodata*)
	_E_text = . ;
   }>flash
   
   .data :
   {
    _S_data = . ;
     *(.data)
	. = ALIGN(4) ;
	 _E_data = . ;
   }> sram AT> flash
   
   .bss :
   {
    _S_bss = . ;
    *(.bss*)
	. = ALIGN(4);
	_E_bss = . ;
   }>sram
   
}