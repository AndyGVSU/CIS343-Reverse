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

	//printf("%c",*fileBuffer[0]);

	int first = 0;
	int last = bytesRead - 2; //for array bound / null character
	char swapCharFirst;
	char swapCharLast;

	//char* reverse = (char*) malloc(bytesRead * sizeof(char));
	
	//*fileBuffer += sizeof(char) * middle;

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
	
	//printf("%s",*fileBuffer);
	/*
	for (int i = 0; i < (bytesRead); i++)
		{
		printf("%c",**fileBuffer);
		printf("%d",i);
		*fileBuffer += sizeof(char);
		//reverse[i] = *fileBuffer[bytesRead - i - 1];
		}
	*/
	//*fileBuffer -= (sizeof(char) * bytesRead);

	int bytesWritten = write_file(outputFilename, *fileBuffer, bytesRead);
	//printf("%d",bytesWritten);
	return 0;
	}
