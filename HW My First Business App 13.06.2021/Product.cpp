#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(const char* name, const char* description, double price, unsigned quantity) : price_(price), quantity_(quantity)
{
	SetName(name);
	SetDescription(description);
}

Product::Product() : Product("undefined", "undefined", 0, 0) {}

Product::Product(const char* name, const char* description, double price) : Product(name, description, price, 0) {}

Product::Product(const char* name, const char* description) : Product(name, description, 0, 0) {}

Product::Product(const char* name) : Product(name, "undefined", 0, 0) {}

Product::~Product()
{
	Clear();
}

Product::Product(const Product& product)
{
	Copy(product);
}

Product::Product(Product&& product)
{
	this->name_ = product.name_;
	this->description_ = product.description_;
	this->price_ = product.price_;
	this->quantity_ = product.quantity_;

	product.name_ = nullptr;
	product.description_ = nullptr;
	product.price_ = 0;
	product.quantity_ = 0;
}

void Product::SetName(const char* name)
{
	size_t name_len = StrLen(name);
	name_ = new char[name_len + 1];

	for (size_t i = 0; i <= name_len; i++)
	{
		name_[i] = name[i];
	}
}

void Product::SetDescription(const char* description)
{
	size_t description_len = StrLen(description);
	description_ = new char[description_len + 1];

	for (size_t i = 0; i <= description_len; i++)
	{
		description_[i] = description[i];
	}
}

void Product::SetPrice(double price)
{
	price_ = price;
}

void Product::SetQuantity(unsigned quantity)
{
	quantity_ = quantity;
}

char* Product::GetName()
{
	return name_;
}

char* Product::GetDescription()
{
	return description_;
}

double Product::GetPrice()
{
	return price_;
}

unsigned Product::GetQuantity()
{
	return quantity_;
}

Product& Product::operator=(Product&& product)
{
	if (this != &product)
	{
		Clear();

		this->name_ = product.name_;
		this->description_ = product.description_;
		this->price_ = product.price_;
		this->quantity_ = product.quantity_;

		product.name_ = nullptr;
		product.description_ = nullptr;
		product.price_ = 0;
		product.quantity_ = 0;
	}

	return *this;
}

Product& Product::operator=(const Product& product)
{
	if (this != &product)
	{
		Clear();
		Copy(product);
	}

	return *this;
}



void Product::Copy(const Product& product)
{
	size_t name_len = StrLen(product.name_);
	size_t description_len = StrLen(product.description_);

	name_ = new char[name_len + 1];
	description_ = new char[description_len + 1];

	for (size_t i = 0; i <= name_len; i++)
	{
		name_[i] = product.name_[i];
	}

	for (size_t i = 0; i <= description_len; i++)
	{
		description_[i] = product.description_[i];
	}

	price_ = product.price_;
	quantity_ = product.quantity_;
}

void Product::Clear()
{
	delete[] name_;
	delete[] description_;
	price_ = 0;
	quantity_ = 0;

	name_ = nullptr;
	description_ = nullptr;
}

void Product::PrintName()
{
	cout << "Name: ";
	size_t name_len = StrLen(name_);

	for (size_t i = 0; i < name_len; i++)
	{
		cout << name_[i];
	}

	cout << endl;
}

void Product::PrintDescription()
{
	cout << "Description: ";
	size_t desc_len = StrLen(description_);

	for (size_t i = 0; i < desc_len; i++)
	{
		cout << description_[i];
	}

	cout << endl;
}

void Product::PrintPrice()
{
	cout << "Price: " << price_ << endl;
}

void Product::PrintQuantity()
{
	cout << "Quantity: " << quantity_ << endl;
}

void Product::PrintAllObj()
{
	PrintName();
	PrintDescription();
	PrintPrice();
	PrintQuantity();
}

size_t Product::StrLen(const char* str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return length;
}
