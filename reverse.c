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
	
	//printf("%p\n",*fileBuffer);
	
	int bytesRead = read_file(inputFilename, fileBuffer);
	if (bytesRead < 0) { return bytesRead; } //read_file() error
	
	//printf("%s",*fileBuffer);
	//printf("%d",bytesRead);
	//printf("%c",bufferPointer[0]);
	//printf("%c",bufferPointer[1]);
	//reverse string in buffer

	printf("%c",*fileBuffer[0]);

	//int reverse = bytesRead / 2;
	//char* reverse = (char*) malloc(bytesRead * sizeof(char));
	/*
	for (int i = 0; i < (bytesRead / 2) - 1; i++)
		{
		
		//reverse[i] = *fileBuffer[bytesRead - i - 1];
		}
	*/

	int bytesWritten = write_file(outputFilename, *fileBuffer, bytesRead);
	//printf("%d",bytesWritten);
	return 0;
	}
