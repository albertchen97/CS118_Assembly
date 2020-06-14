
// An Interrupt Service Routine (ISR) example.
// These program is generated in BIOS (Basic Input/Output System).
// BIOS will initialize RAM, checks how many drivers are connected to the system.
// It also initialize display to read the first sector form the boot drive, loads it in memory, and CPU control transferred to this code.
// Loads to OS (Operating System)
// Device drivers take over all hardwares (Reads what BIOS info before it does it own discovery).

// PCI (Peripheral Component Interconnect) Bus: The bus which connect CPU to all the devices.

#include <stdio.h>

// Define a function pointer of (isr) type.
typedef void(*isr)(unsigned int);

void mouse_isr(unsigned int a){

	// Declare the x and y coordinates.
	unsigned int* x_c = (unsigned int*)0x123456677;
	unsigned int* y_c = (unsigned int*)0x123456677;
	*x_c = 10;
	
	// Read register of mouse controller and get x, y co-ordinates.
	// Send a message to graphics system to update mouse pointer location.
	
}

void keyboard_isr(unsigned int a){

	printf("keyboard_isr called. \n");
	
}

int main(int argc, char** args){
	
	int isr_number = 0;
	
	// 
	isr x = keyboard_isr;
	
	// Inverrupt Vector Table(IVT).
	// We are setting up 2 interupt service: routines for mouse and keyboard.
	isr ivt[2] = { mouse_isr, keyboard_isr };
	
	// Call keyboard_isr. 
	ivt[isr_number](0);
	
}
