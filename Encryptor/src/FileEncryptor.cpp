#include <exception>

#include "../include/FileEncryptor.h"
#include "../include/BaseEncryptor.h"


FileEncryptor::FileEncryptor()
{
    encryptor = nullptr;
}

FileEncryptor::FileEncryptor(BaseEncryptor* encryptor)
{
    setEncryptor(encryptor);
}

void FileEncryptor::encrypt(char* filepath)
{
    if (encryptor == nullptr) {
        throw std::exception("Encrypting error: no encryptor set");
    }

    encryptor->encrypt(filepath);
}

void FileEncryptor::setEncryptor(BaseEncryptor* encryptor)
{
    encryptor = encryptor;
}

FileEncryptor::~FileEncryptor()
{
    delete encryptor;
}
