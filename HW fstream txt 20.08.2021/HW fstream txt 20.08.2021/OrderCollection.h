#pragma once
#include "Headers.h"
class OrderCollection
{
	friend class WriteToTxtFile;

public:

	OrderCollection() = default;
	OrderCollection(string name, unsigned quantity, double price);

	void AddProduct(string name, unsigned quantity, double price);

	double CalculateTotalPrice();

private:

	struct ProductDescription
	{
		string nameOfProduct_;
		unsigned quantity_;
		double price_;
	};

	ProductDescription product_{ "undefined", 0, 0.0 };

	double totalPrice_ = 0.0;

	vector<ProductDescription> collection_;
	size_t size_ = 0;
};

