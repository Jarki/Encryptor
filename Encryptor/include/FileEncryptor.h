#pragma once

class BaseEncryptor;

class FileEncryptor
{
public:
	FileEncryptor();
	FileEncryptor(BaseEncryptor* encryptor);

	void encrypt(char* filepath);

	void setEncryptor(BaseEncryptor* encryptor);

	~FileEncryptor();
private:
	BaseEncryptor* encryptor;
};

