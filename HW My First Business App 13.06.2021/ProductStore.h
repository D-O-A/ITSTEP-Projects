#pragma once
#include "Product.h"
#include <iostream>
using namespace std;

class ProductStore
{
public:

	ProductStore() = default;
	ProductStore(size_t size);
	~ProductStore();
	ProductStore(const ProductStore& store);

	void SetAllCollection(const char* name, const char* description, double price, unsigned quantity);
	void SetCurCollection(const char* name, const char* description, double price, unsigned quantity, size_t index);

	void AddItem();
	void RemoveItem(size_t index);

	void PrintAllCollection();
	void PrintCurCollection(size_t index);

private:

	Product* pcollection_ = nullptr;
	size_t size_ = 0;

};

