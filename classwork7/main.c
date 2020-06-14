#include <stdio.h>
#include <immintrin.h>

//https://software.intel.com/sites/landingpage/IntrinsicsGuide/#techs=AVX (Links to an external site.)
// compile with -mavx for 256 intrinsic.
int main(int argc, char** argv) {


	float r[8] = {0};
	float xx[8] = {1.2, 1.3, 1.4, 1.5, 2.1, 6.1, 7.2, 3.5};
	float yy[8] = {1.2, 1.3, 1.4, 1.5, 2.1, 6.1, 7.2, 3.5};

	//xmm0 128 bit
	//xmm0 1f 1f 1f 1f = 32 x 4 = 128
	__m256 x = _mm256_loadu_ps(xx);
	__m256 y = _mm256_loadu_ps(yy);

	__m256 z = _mm256_mul_ps (x, y);
	
	__m256 a = _mm256_hadd_ps(z, z);
	
	_mm256_storeu_ps(r, a);
	
	float result = r[0] + r[1] + r[4] + r[5];
	
	printf("%f \n", result);
	
	return 0;
	
}
