#Make File
CC=arm-none-eabi-
CFLAGS=-mthumb -mcpu=cortex-m3
INCS=-I.
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
Project_name=Pressure_Controller


all:$(Project_name).elf
	@echo "============Build is Done============"

%.o:%.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@ 
	
$(Project_name).elf:$(OBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) -o $@ -Map=Map_file.map
		
clean:
	rm *.elf

clean_all:
	rm *.elf *.o
	