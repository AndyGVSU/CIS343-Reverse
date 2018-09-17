//file_utils.c
//Handles reading and writing text files.
//Written by Andy Hudson

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

//Reads a given file and writes it to the given buffer.
//@param filename - name of the text file to read from (must contain text!)
//@param buffer - pointer to a space for memory to be allocated to
int read_file(char* filename, char** buffer) {
	FILE* inputFile;
	int charSize = sizeof(char);
	int bytesRead;

	struct stat st;
	stat(filename, &st);
	int fileSize = st.st_size;
	
	*buffer = (char*) malloc(fileSize * charSize);
	
	inputFile = fopen(filename,"r");
	if (inputFile == NULL) { 
		fprintf(stderr,"\nfile_read error: invalid file name");
		return -2;
	}

	if (*buffer == NULL) { 
		fprintf(stderr,"\nfile_read error: invalid memory allocation"); 
		return -1;
	}
	
			//else {
		bytesRead = fread(*buffer, charSize, fileSize / charSize, inputFile);
		fclose(inputFile);
	//}

	return bytesRead;
}

//Writes a new file from the text stored in the buffer.
//@param filename - Name of the file to create (or overwrite)
//@param buffer - string to write to the new file
//@param size - size (in bytes) of the text to write
int write_file(char* filename, char* buffer, int size) {
	FILE* outputFile;
	int charSize = sizeof(char);

	outputFile = fopen(filename,"w");
	if (outputFile == NULL) { 
		fprintf(stderr,"\nfile_write error: invalid file name"); 
		return -2;
	}

	int bytesWritten = fwrite(buffer, charSize, size / charSize, outputFile);
	
	//deallocate buffer memory
	free(buffer);
	fclose(outputFile);
	
	return bytesWritten;
}
