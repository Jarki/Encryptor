#include <iostream>

#include "include/FileWrapper.h"

int main(int argc, char* argv[]) {
	auto file = FileWrapper("test.txt", "w+");

	file.write("Hello", 5);

	return 0;
}