#include <iostream>
#include <cstdint>
#include <cstring>
#include <stdio.h> // printf, scanf, NULL
#include <stdlib.h> // malloc, free, rand
#include <string>
using namespace std;
/*
 *  Implement memory copy.
 * 1. Move at least 1GB of memory.
 * 2. Allocate 100MB buffers, 
 * 	initialize one buffer with 0xDEADBEF
 * 3. Copy initialized buffer on the other
 * 	buffer and repeat it 10 times.
 */
 
int main(){
	
	// Size of 100MB
	const size_t MEM_SIZE = 100 * 1024 * 1024 * sizeof(char);
	
	// cout << "sizeof(src_buffer) = " << sizeof(src_buffer) << endl;
	
	// Copy src_buffer to des_buffer and repeat 10 times
	for(int i = 0; i < 10; i++){
		
		// Allocate 100MB memory and split into two buffers 
		char src_buffer[] = "0xDEADBEEF";
		char *des_buffer = new char[MEM_SIZE - sizeof(src_buffer)];
		
		// Coppy src_buffer to des_buffer
		memcpy(des_buffer, src_buffer, sizeof(src_buffer)); // void *memcpy(void *to, const void *from, size_t numBytes)
		
		cout << " Copy No." << i+1 << endl
			<< " &src_buffer = " << &src_buffer << endl
			<< " &des_buffer = " << &des_buffer << endl
			<< " src_buffer = " << src_buffer << endl
			<< " des_buffer = " << des_buffer << endl
			<< endl;
			
		delete &src_buffer;
		delete des_buffer;
	}
	
	return 0;
}








