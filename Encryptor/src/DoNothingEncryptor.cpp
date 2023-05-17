#include <string.h>

#include "../include/DoNothingEncryptor.h"
#include "../include/FileWrapper.h"


char* DoNothingEncryptor::encrypt(char* content)
{
	return content;
}
