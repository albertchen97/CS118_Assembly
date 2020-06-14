/* 
	Matrix Multiplicaiton
	Use thread and SSE instruction.
	Write matrix multiplication application in C using SSE library.
		1. Use 4x4 matrix in your program 
		2. Use pthreads library and SSE C library.
	// compile with -mavx for 256 intrinsic.
	Compile command: gcc main.c -o exe -pthread -mavx
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <xmmintrin.h>
#include <immintrin.h>
#include <pmmintrin.h>

// Use two threads to do the matrix multiplication.
// Main thread do multiplication
// The other thread do addition

// Define number of loops as a constant.
#define NUM_LOOPS 4

// Hardcode two 4x4 matrices using 2D array.
float matrix_1 [4][4] = { 
							{1.1, 1.2, 1.3, 1.4}, 
							{2.1, 2.2, 2.3, 2.4},
							{3.1, 3.2, 3.3, 3.4},
							{4.1, 4.2, 4.2, 4.4}
						};
float matrix_2 [4][4] = { 
							{1.1, 1.2, 1.3, 1.4}, 
							{2.1, 2.2, 2.3, 2.4},
							{3.1, 3.2, 3.3, 3.4},
							{4.1, 4.2, 4.2, 4.4}
						};
						
// Store the result in another matrix.
float result [4][4] = {0};

// Declare two mutex lockers.
pthread_mutex_t main_locker = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t thread_locker = PTHREAD_MUTEX_INITIALIZER;

// To store the temp value.
float zz[4] = {0};

// A thread function to do thread process.
void* thread_function(void*);

int main(int argc, char **argv){
	
	// Create a thread that runs thread_function(). 
	pthread_t thread1; 
	pthread_create( &thread1, NULL, thread_function, NULL );
	
	
	
	for(int i = 0; i < NUM_LOOPS; i++){
		
		for(int j = 0; j < NUM_LOOPS; j++){
			
			// The n_th row of the first matrix multiply by the n_th column of the second matrix.
			
			// Get the row of the first matrix
			float xx[4] = { matrix_1[i][0], matrix_1[i][1], matrix_1[i][2], matrix_1[i][3] };
					
			// Get the column of the second matrix
			float yy[4] = { matrix_2[0][j], matrix_2[1][j], matrix_2[2][j], matrix_2[3][j] };
			
			// Lock main thread to do multiplication.
			pthread_mutex_lock( &main_locker );
			
			__m128 x = _mm_loadu_ps(xx);
			__m128 y = _mm_loadu_ps(yy);
			__m128 z = _mm_mul_ps (x, y);
			
			// Store into zz and add them up in thread_function.
			_mm_storeu_ps(zz, z);
			
			// Unlock thread1 to do addition.
			pthread_mutex_unlock( &thread_locker );
			
		}
	}
	
	pthread_join(thread1, NULL);
	
	for(int i = 0; i < NUM_LOOPS; i++){
		for(int j = 0; j < NUM_LOOPS; j++){
			printf(" %f ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void* thread_function(void* arg){
	
	float r[4] = {0};
	
	// Add up the multiplicaiton result and store into result matrix.
	// Use nested-loop.
	for(int i = 0; i < NUM_LOOPS; i++){
		for(int j = 0; j < NUM_LOOPS; j++){
			
			// Lock thread1 to do addition.
			pthread_mutex_lock( &thread_locker );
			
			__m128 z = _mm_loadu_ps( zz );
			
			// Add up the 4 elements in zz to get the result.
			__m128 a = _mm_hadd_ps(z, z);
			_mm_storeu_ps(r, a);
			
			// The result stored in r[0] + r[1]
			result[i][j] = r[0] + r[1];
			
			// Unlock main thread to do multiplication.
			pthread_mutex_unlock( &main_locker );
			
		}
	}
	
}
