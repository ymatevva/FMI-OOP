#pragma once

#pragma warning(disable:4996)
class String {
	
	char* str = nullptr;
	size_t size = 0;
	size_t capacity = 1;

	void copyFrom(const String& other);
	void free();
	void setStr(const char* str);
	void resize(unsigned capacity);

public:

	String() = default;
	String(const char* str);
	String(const String& other);
	String&operator=(const String& other);
	~String();

	
    const char* getStr() const;
	size_t getCapacity() const;
	char at(unsigned index) const;
	char front() const;
	char back() const;
	
	
	void appChar(char ch);
	void appendStr(const char* str);

	unsigned lengthStr() const;
	unsigned capacityStr() const;
	bool isEmpty() const;
	void appStrings( const String& other);
	void clear();
	bool areEqual(const String& other) const;
	int findSymbol(char ch) const;

};