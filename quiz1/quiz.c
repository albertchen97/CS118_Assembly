#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

//implement this function in assembly returns number of even numbers found in array src

// also updates even and odd arrays which are passed as an argument

uint32_t evens_and_odds(uint32_t* src, uint32_t* evn, uint32_t* odd,  uint32_t size);

int main(int argc, char** argv)
{
		uint32_t source[14] = {4, 8, 1, 23, 13, 24, 15, 16, 17, 8, 19, 11, 12, 44 };

		uint32_t even[14] = {0};

		uint32_t odd[14] = {0};

		uint32_t n = evens_and_odds(source, even, odd, 14);
	
		for (int i =0; i< n; i++)
		{
           printf(" %d ",even[i]);
        }
        
return 0;
}
