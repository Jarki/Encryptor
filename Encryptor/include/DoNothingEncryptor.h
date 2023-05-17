#pragma once
#include "BaseEncryptor.h"
class DoNothingEncryptor :
    public BaseEncryptor
{
public:
    void encrypt(const char* source_filename, const char* dest_filename);
};

