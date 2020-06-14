#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int32_t add_array_asm(int32_t *myarray, uint32_t size);
void reverse_array_asm(int32_t *myarray, int32_t *revarray, uint32_t size);
int32_t add_square_asm(int32_t*, int);

int main(int argc, char** avgs){
	
	// sum array
	
	int32_t myarray[4] = {1, 2, 3, 4};
	uint32_t size = sizeof(myarray) / 4; // since c don't have <array> library, we cannot use myarray.size().
	int32_t sum = add_array_asm(myarray, size);
	
	printf("Original array, size = %d: \n", size);
	
	for(unsigned int i = 0; i < size; i++){
		
		printf("myarray[%d] = %d \n", i , myarray[i]); 
		
	}
	
	printf("Sum of array is %d\n", sum);
	
	// reverse array
	
	int32_t *reversed_array = (int32_t*)malloc(sizeof(int32_t) * size );
	reverse_array_asm(myarray, reversed_array, size);
	
	printf("Reversed array, size = %d: \n", size);
	
	for(int32_t j = 0; j < size; j++){
		
		printf("reversed_array[%d] = %d \n", j , reversed_array[j] ); 
		
	}
	
	// square
	
	printf("array_square = %d \n", add_square_asm(myarray, (int)size));

	return 0;
}
