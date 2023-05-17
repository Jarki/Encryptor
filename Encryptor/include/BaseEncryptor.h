#pragma once
class BaseEncryptor
{
public:
	BaseEncryptor() : key(nullptr) {};
	BaseEncryptor(char* user_key) : key(user_key) {};

	virtual char* encrypt(char* content) = 0;

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

