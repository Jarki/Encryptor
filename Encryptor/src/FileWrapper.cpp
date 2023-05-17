#include <exception>

#include "../include/FileWrapper.h"
#include <string.h>

FileWrapper::FileWrapper(const char* filename)
{
	open(filename, "r");
}

FileWrapper::FileWrapper(const char* filename, const char* mode)
{
	open(filename, mode);
}

void FileWrapper::open(const char* filename, const char* mode)
{
	fopen_s(&handle, filename, mode);
}

void FileWrapper::close()
{
	if(handle != nullptr)
		fclose(handle);
}

char* FileWrapper::read()
{
	fseek(handle, 0, SEEK_END);
	long fsize = ftell(handle);
	rewind(handle);

	char* buffer = (char*)malloc(sizeof(char) * fsize + 1);
	
	if (buffer == nullptr) {
		printf("%s", "Error!");
		return nullptr;
	}

	size_t result = fread(buffer, 1, fsize, handle);

	if (result != fsize) { 
		printf("%s", "Reading error!");
		return nullptr; 
	}

	buffer[fsize] = '\0';
	return buffer;
}

void FileWrapper::write(const char* content, size_t content_size)
{
	fwrite(content, sizeof(char), content_size, handle);
}

FileWrapper::~FileWrapper()
{
	try {
		close();
	}
	catch(const std::exception& ex) {
		printf("%s", "Error while closing file: ");
		printf("%s", ex.what());
	}
	catch(...) {
		printf("%s", "Unexpected error while closing file.");
	}	
}
