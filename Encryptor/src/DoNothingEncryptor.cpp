#include <string.h>

#include "../include/DoNothingEncryptor.h"
#include "../include/FileWrapper.h"

void DoNothingEncryptor::encrypt(const char* source_filename, const char* dest_filename)
{
	// open the source file in read mode
	auto source_file = FileWrapper(source_filename);
	// extract file content
	char* content = source_file.read();

	// close the file
	// this means that we dont care if dest is the same as source
	source_file.close();

	// open the dest file, discard any content it had
	auto dest_file = FileWrapper(dest_filename, "w+");

	// write the new content
	//printf("%d", strlen(content));
	dest_file.write(content, strlen(content));
}
