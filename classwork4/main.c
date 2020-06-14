#include <stdio.h>
#include <stdint.h>

unsigned int _abs(int x);

int main(int argc, char** argv){
	
	unsigned int x = _abs(-10);
	printf("abs(-10) = %d \n", x);
	
	unsigned int y = _abs(20);
	printf("abs(20) = %d \n", y);
	
	return 0;
	
}
