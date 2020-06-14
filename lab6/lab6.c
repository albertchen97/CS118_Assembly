#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void memoryCopy();
void myMemoryCopy(uint32_t*, uint32_t*, uint32_t);

int main(){
	
	const uint32_t MEMORY_SIZE = 100 * 1024 * 1024 * sizeof(uint32_t) / 4; // 100MB
	
	uint32_t *src = (uint32_t*)malloc(MEMORY_SIZE);
	uint32_t *des = (uint32_t*)malloc(MEMORY_SIZE);
	*src = (uint32_t)0xDEADBEEF;
	clock_t start, end;
	start = clock();
	myMemoryCopy(des, src, MEMORY_SIZE);
	end = clock();
	
	double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n my_memory_copy() took %f seconds to execute.\n", time_elapsed);
	
	free(src);
	free(des);
	return 0;
}

void memoryCopy(){
	
	const uint32_t MEMORY_SIZE = 100 * 1024 * 1024 * sizeof(uint32_t);
	uint32_t *buffer_one = (uint32_t*)malloc(MEMORY_SIZE);
	uint32_t *buffer_two = (uint32_t*)malloc(MEMORY_SIZE);
	*buffer_one = 0xDEADBEEF;
	
	clock_t start, end;
	
	start = clock();
	for(int i = 0; i < 10; i++){
		memcpy(buffer_two, buffer_one, MEMORY_SIZE);
	}
	end = clock();
	
	double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n memcpy() took %f seconds to execute.", time_elapsed);
	
	free(buffer_one);
	free(buffer_two);	
}
