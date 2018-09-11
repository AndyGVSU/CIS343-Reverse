#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

int read_file(char* filename, char** buffer)
	{
	FILE* inputFile;
	//char* fileBuffer = *buffer;
	
	//printf("%p\n",buffer);
	//printf("%p\n",*buffer);
	//printf("%p\n",fileBuffer);

	int charSize = sizeof(char);
	int bytesRead;

	struct stat st;
	stat(filename, &st);
	int fileSize = st.st_size;
	
	*buffer = (char*) malloc(fileSize * charSize);
	//printf("%p\n",fileBuffer);
	
	if (*buffer == NULL) 
		{ 
		fprintf(stderr,"file_read error: invalid memory allocation"); 
		return -1; 
		}
	
	inputFile = fopen(filename,"r");
	if (inputFile == NULL) 
		{ 
		fprintf(stderr,"file_read error: invalid file name"); 
		return -2; 
		}
	else
		{
		bytesRead = fread(*buffer, charSize, fileSize / charSize, inputFile);
		//fileBuffer[sizeof fileBuffer - 1] = 0;
		fclose(inputFile);
		}

	return bytesRead;
	}
int write_file(char* filename, char* buffer, int size)
	{
	FILE* outputFile;
	int charSize = sizeof(char);

	outputFile = fopen(filename,"w");
	
	int bytesWritten = fwrite(buffer, charSize, size / charSize, outputFile);
	
	free(buffer); //deallocate buffer memory
	fclose(outputFile);
	
	return bytesWritten;
	}
