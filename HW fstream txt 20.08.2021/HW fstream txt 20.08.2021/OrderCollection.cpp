#include "Headers.h"

OrderCollection::OrderCollection(string name, unsigned quantity, double price)
{
	product_.nameOfProduct_ = name;
	product_.quantity_ = quantity;
	product_.price_ = price;

	collection_.push_back(product_);
	size_ = collection_.size();
}

void OrderCollection::AddProduct(string name, unsigned quantity, double price)
{
	product_.nameOfProduct_ = name;
	product_.quantity_ = quantity;
	product_.price_ = price;

	collection_.push_back(product_);
	size_ = collection_.size();
}

double OrderCollection::CalculateTotalPrice()
{
	for (size_t i = 0; i < size_; i++)
	{
		totalPrice_ += collection_[i].price_ * collection_[i].quantity_;
	}

	return totalPrice_;
}
