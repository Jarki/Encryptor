#include <exception>
#include <string.h>

#include "../include/FileEncryptor.h"
#include "../include/BaseEncryptor.h"
#include "../include/FileWrapper.h"


FileEncryptor::FileEncryptor(BaseEncryptor* encryptor)
{
    setEncryptor(encryptor);
}

void FileEncryptor::encrypt(const char* source_filepath, const char* dest_filepath)
{
    if (encryptor == nullptr)
        throw std::exception("Encrypting error: no encryptor set");

	if (dest_filepath == nullptr)
		dest_filepath = source_filepath;

	// open the source file in read mode
	auto source_file = FileWrapper(source_filepath);
	
	char* content = source_file.read();

	// close the file
	// this means that we dont care if dest is the same as source
	source_file.close();

	encryptor->encrypt(content);

	// open the dest file, discard any content it had
	auto dest_file = FileWrapper(dest_filepath, "w+");

	// write the new content
	//printf("%d", strlen(content));
	dest_file.write(content, strlen(content));
}

void FileEncryptor::setEncryptor(BaseEncryptor* encryptor)
{
    this->encryptor = encryptor;
}

FileEncryptor::~FileEncryptor()
{
    delete encryptor;
}
