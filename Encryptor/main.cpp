#include <iostream>

#include "include/FileWrapper.h"
#include "include/DoNothingEncryptor.h"
#include "include/FileEncryptor.h"

int main(int argc, char* argv[]) {
	auto string_encryptor = new DoNothingEncryptor();

	FileEncryptor encryptor(string_encryptor);

	encryptor.encrypt("test.txt", "test_enc.txt");

	return 0;
}