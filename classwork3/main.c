// calculate standard variance
#include <stdint.h>
#include <stdio.h>

int variance(uint32_t* , uint32_t*, uint32_t);
int main(int argc, char** argv){
	
	uint32_t src[10] = {1, 2, 3, 4, 5, 60, 77, 23, 33, 55};
	uint32_t tmp[10] = {0};	// to store square
	printf("variance = %d \n", variance(src, tmp, 10)); //533
	return 0;
	
}
