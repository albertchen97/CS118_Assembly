#include <stdio.h>

float sum(float* arr, int size);

int main(int argc, char** argv) {
	
	float arr[10] = 
	{1.5, 4.2, 16.1, 45.2, 2.1, 3.4, 3.14159265, 1.619, 2.71827, 6.022}; //86.00086265
	float x = sum(arr,10);
	printf("Sum is : %f \n", x);
	return 0;

}
