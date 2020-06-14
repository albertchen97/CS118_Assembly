// Testing the functionality of linking cpp file and asm file
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
extern "C" int8_t gray_scale_asm(uint32_t*);
int main()
{
	uint8_t p = gray_scale_asm((uint32_t*)0xFFFFFF00);
	cout<< (uint32_t)p << endl;
	return 0;
}
