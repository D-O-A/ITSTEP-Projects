﻿#pragma once
class Product
{
public:

	Product();
	Product(const char* name, const char* description, double price, unsigned quantity);
	Product(const char* name, const char* description, double price);
	Product(const char* name, const char* description);
	Product(const char* name);
	~Product();
	Product(const Product& product);
	Product(Product&& product);

	void SetName(const char* name);
	void SetDescription(const char* description);
	void SetPrice(double price);
	void SetQuantity(unsigned quantity);

	char* GetName();
	char* GetDescription();
	double GetPrice();
	unsigned GetQuantity();

	Product& operator=(Product&& product);
	Product& operator=(const Product& product);

	void PrintName();
	void PrintDescription();
	void PrintPrice();
	void PrintQuantity();
	void PrintAllObj();

private:

	void Clear();
	void Copy(const Product& product);
	size_t StrLen(const char* str);
	char* name_;
	char* description_;
	double price_;
	unsigned quantity_;

};

