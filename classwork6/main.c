#include <stdio.h>
#include <nmmintrin.h>

int main(int argc, char** argv) {


	float r[8] = {0};
	float xx[8] = {1.2, 1.3, 1.4, 1.5, 2.1, 6.1, 7.2, 3.5};
	float yy[8] = {1.2, 1.3, 1.4, 1.5, 2.1, 6.1, 7.2, 3.5};

	// xmm0 - 128 bit
	// xmm0 - (1 float) + (1 float) + (1 float) +  1f = 32 x 4 = 128
	
	for(int i = 0; i < 2; i++){
		
		// Load elements
		__m128 x = _mm_load_ps(xx + i*4);
		__m128 y = _mm_load_ps(yy + i*4);
		
		// Multiplication
		__m128 z = _mm_mul_ps (x, y);
		
		// Store results into r array
		_mm_storeu_ps (r + i*4, z);
		
	}
	
	// Print the results
	for (int i = 0; i < 8; i++)
		printf("%f \n", r[i]);
	
	return 0;

}

