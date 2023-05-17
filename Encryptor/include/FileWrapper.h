#pragma once
#include <cstdio>

class FileWrapper
{
public:
	FileWrapper(const char* filename);
	FileWrapper(const char* filename, const char* mode);

	void open(const char* filename, const char* mode);
	void close();

	char* read();
	void write(const char* content, size_t content_size);

	~FileWrapper();
private:
	std::FILE* handle;
};

