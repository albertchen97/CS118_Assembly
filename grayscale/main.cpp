/*                                                               
 compilation command: 
 * 1. Assemble: yasm -g dwarf2 -f elf64 -l grayscale.lst grayscale.asm
 * 2. Compile and link: 
		g++ -g -no-pie grayscale.o main.cpp -o main -I/usr/local/include/opencv4/opencv2 -I/usr/local/include/opencv4 -L/usr/local/lib -lopencv_core -lopencv_highgui -ldl -lm -lpthread -lrt -lstdc++ -lopencv_imgcodecs
*/

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

extern "C" uint8_t gray_scale_asm(uint32_t*);
void gray_scale(Mat*, Mat*);			

int main( int argc, char *argv[] ) // argc - argument count; argv - argument vector
{
	if( argc != 2){
		cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
		return -1;
	}

	Mat image, gray;
	image = imread(argv[1], cv::IMREAD_COLOR); // Read the file. argv[1] is the argument you passed to main() function in index 1. Index 0 contains the execution command such as "./main".
	gray.create(image.rows, image.cols, CV_8UC1);

	//converting color image to gray scale with C++.
	//Add RGB channels and divide by there ... average or all three channels
	//gray_scale(&image, &gray);
	
	for (int r = 0; r < image.rows; r++) { // rows
		
		for (int c = 0; c < image.cols; c++) { // columns
			
			uint32_t* p = (uint32_t*)image.ptr(r,c);
			
				// cout << "image.ptr(" << r << "," << c <<") = " << (uint32_t)*image.ptr(r,c) << endl;  // code for testing
			
			// converting colored_pixel(row, column) to gray_picel(row, column)
			*(gray.ptr(r, c)) = gray_scale_asm(p);
			
				// cout << "gray.ptr(" << r << "," << c << ") = " << (uint32_t)*gray.ptr(r,c) << endl; // code for testing
		}

	}
	
	printf("\n***** Input image *****\n");
	printf("Dim:%x\n", image.dims);
	printf("Rows:%d\n", image.rows);
	printf("Cols:%d\n", image.cols);
	printf("Channels:%d\n", image.channels());

	printf("\n***** Gray image *****\n");
	printf("Dim:%x\n", gray.dims);
	printf("Rows:%d\n", gray.rows);
	printf("Cols:%d\n", gray.cols);
	printf("Channels:%d\n", gray.channels());

	if(! image.data ) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl ;
		return -1;
	}

	namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
	imshow( "Display window", image ); // Show our image inside it.

	namedWindow( "Display gray window", WINDOW_AUTOSIZE );// Create a window for display.
	imshow( "Display gray window", gray); // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
	
	return 0;
	
}

void gray_scale(Mat* color, Mat* gray) {
	
	for (int r = 0; r < color -> rows; r++) { // rows
		
		for (int c = 0; c < color->cols; c++) { // columns
			
			uint32_t* p = (uint32_t*)color->ptr(r,c);
			
			// converting colored_pixel(row, column) to gray_picel(row, column)
			*gray->ptr(r, c) = 
				( 
					( (*p & 0xff000000) >> 24 ) // red to gray
				  + ( (*p & 0x00ff0000) >> 16 ) // green to gray
				  + ( (*p & 0x0000ff00) >> 8  ) // blue to gray
				) / 3 ; // get the average
		
		}

	}
	
}
