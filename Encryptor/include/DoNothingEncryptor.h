#pragma once
#include "BaseEncryptor.h"
class DoNothingEncryptor :
    public BaseEncryptor
{
public:
    char* encrypt(char* content);
};

