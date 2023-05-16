#include <exception>

#include "../include/FileWrapper.h"

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
	fclose(handle);
	delete handle;
}

const char* FileWrapper::read()
{
	return nullptr;
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
