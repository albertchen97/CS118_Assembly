/*
 * This program explores the use of parallel processing using pthread(POXIS thread) API.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_LOOPS 1000000
int random_number = 0;
pthread_mutex_t mutex_main_thread = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_thread_1 = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

void* thread_function(void*);
int main(int argc, char **argv){
	
	// Create a thread that runs thread_function().
	pthread_t thread1; 
	pthread_create( &thread1, NULL, thread_function, NULL );
	
	// Loop in the main thread. It runs parallely with thread1.
	for (int i = 0; i < NUM_LOOPS; i++) {
		
		// Lock the main thread.
		pthread_mutex_lock( &mutex_main_thread ); 
		
		// Chekc random_number.
		if(random_number == 129) {
			count++;
		}
		
		// Unlock the thread1 after main thread read the data. 
		pthread_mutex_unlock( &mutex_thread_1 ); 
		
	}
	
	// Wait until thread1 finished.
	pthread_join(thread1, NULL);
	printf("count = %d\n", count);
	
	return 0;
}

void* thread_function(void* arg){
	
	// Loop in thread1. It runs p	
	for (int i = 0; i < NUM_LOOPS; i++) {
		
		// Lock the thread1. Main thread is been blocked from random_number.
		pthread_mutex_lock( &mutex_thread_1 ); 
		
		//create randowm number 0 to 200
		random_number = rand() % 201;
		
		// Unlock the main thread. It allows main thread to check the random_number.
		pthread_mutex_unlock( &mutex_main_thread  ); 
		
	}

}
