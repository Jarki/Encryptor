#include <iostream>

#include "include/FileWrapper.h"
#include "include/DoNothingEncryptor.h"
#include "include/FileEncryptor.h"

int main(int argc, char* argv[]) {
	DoNothingEncryptor encryptor_tool;

	FileEncryptor encryptor(&encryptor_tool);

	encryptor_tool.encrypt("test.txt", "test_enc.txt");

	return 0;
}