#pragma once
class BaseEncryptor
{
public:
	BaseEncryptor() : key(nullptr) {};
	BaseEncryptor(char* user_key) : key(nullptr) {};

	virtual void encrypt(const char* source_filename, const char* dest_filename) {};

	void setKey(char* key) {
		this->key = key;
	};
	char* getkey() {
		return key;
	};

	virtual ~BaseEncryptor() {};
private:
	char* key;
};

