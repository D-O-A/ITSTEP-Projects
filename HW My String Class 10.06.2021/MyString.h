#pragma once
class MyStringClass
{
public:

	MyStringClass() = default;
	MyStringClass(const char* str);
	~MyStringClass();
	MyStringClass(const MyStringClass& str);

	size_t MyStrLen(const char* str) const;
	void Append(const char* str);
	void Assign(const char* str);
	void Insert(size_t index, const char* str);
	void Remove(size_t index, size_t length);

	MyStringClass& operator=(const MyStringClass& str);
	MyStringClass& operator=(MyStringClass&& str);

	char* operator[](const char* str);

	//debug
	void PrintStr() const;

private:

	void Copy(const MyStringClass& str);
	void Clear();
	char* pstr_ = nullptr;
	size_t str_len_ = 0;

};

