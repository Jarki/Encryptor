#pragma once

class BaseEncryptor;

class FileEncryptor
{
public:
	FileEncryptor() : encryptor(nullptr) {};
	FileEncryptor(BaseEncryptor* encryptor);

	void encrypt(const char* source_filepath, const char* dest_filepath = nullptr);

	void setEncryptor(BaseEncryptor* encryptor);

	~FileEncryptor();
private:
	BaseEncryptor* encryptor;
};

