//reverse.c
//Takes two files as input; the second file will contain the text of the first reversed.
//Written by Andy Hudson

#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int main(int argc, char** argv) 
	{
	char* inputFilename = *++argv;
	argv++;
	char* outputFilename = *argv;
	char** fileBuffer;
	char* bufferPointer;
	fileBuffer = &bufferPointer;
	
	int bytesRead = read_file(inputFilename, fileBuffer);
	if (bytesRead < 0) { return bytesRead; } //read_file() error
	
	int first = 0;
	int last = bytesRead - 2; //two for array bound / null character
	char swapCharFirst;
	char swapCharLast;
	
	while (first < last)
		{
		//store first char
		swapCharFirst = **fileBuffer;
		//goto last char
		*fileBuffer += sizeof(char) * (last - first);
		//store last char
		swapCharLast = **fileBuffer;
		//set last char to stored first char
		**fileBuffer = swapCharFirst;
		//goto first char
		*fileBuffer -= sizeof(char) * (last - first);
		//set first char to stored last char
		**fileBuffer = swapCharLast;
		
		//move buffer forward
		*fileBuffer += sizeof(char);
		//close bounds
		first++;
		last--;
		}

	//move buffer back to original position
	*fileBuffer -= first * sizeof(char);

	int bytesWritten = write_file(outputFilename, *fileBuffer, bytesRead);

	return 0;
	}
