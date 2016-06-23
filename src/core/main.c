/*
 * (c) 2014 Apollo Developers
 * main.c - The Opening point of the Kernel Proper.
 */

#include <sys/init.h>
void initModules()
{
	vgaInit(0x3D5, 0x3D4, 0xB8000);             // Index, Data, Base Address. 
	scrWrite("Starting GDT\t\t\t");
	gdtInit();
	scrWrite("[ OK ]\n");

	scrWrite("Starting IDT\t\t\t");
	idtInit();                                  // IDT takes no Arguments.
	scrWrite("[ OK ]\n");

	scrWrite("Starting PIC\t\t\t");
	picInit(0x20, 0xA0);                        // Command Registers of the PIC
	scrWrite("[ OK ]\n");

	scrWrite("Starting PIT\t\t\t");
	pitInit(CLOCKS_PER_SEC);
	scrWrite("[ OK ]\n");

	scrWrite("Starting Keyboard\t\t\t");
	// TODO: Keyboard Check
	scrWrite("[ OK ]\n");
}

int main()
{
	initModules();
	scrWrite("Welcome to XTOS 1.0!\n"); 
	while(1){
		;
	}
	return 0xDEADC0DE;
}
