#include "ProductStore.h"

ProductStore::ProductStore(size_t size)
{
	pcollection_ = new Product[size];
	size_ = size;
}

ProductStore::~ProductStore()
{
	if (pcollection_ != nullptr)
	{
		delete[] pcollection_;
		pcollection_ = nullptr;
	}
}

ProductStore::ProductStore(const ProductStore& store)
{
	size_ = store.size_;
	pcollection_ = new Product[size_];

	for (size_t i = 0; i < size_; i++)
	{
		pcollection_[i].Copy(store.pcollection_[i]);
	}
}

void ProductStore::SetAllCollection(const char* name, const char* description, double price, unsigned quantity)
{
	if (name == nullptr || description == nullptr)
	{
		cout << "Error!\n";
		return;
	}

	for (size_t i = 0; i < size_; i++)
	{
		pcollection_[i].SetName(name);
		pcollection_[i].SetDescription(description);
		pcollection_[i].SetPrice(price);
		pcollection_[i].SetQuantity(quantity);
	}
}

void ProductStore::SetCurCollection(const char* name, const char* description, double price, unsigned quantity, size_t index)
{
	if (name == nullptr || description == nullptr)
	{
		cout << "Error!\n";
		return;
	}

	if (index <= 0 || index > size_)
	{
		cout << "Error!\n";
		return;
	}

	pcollection_[index - 1].SetName(name);
	pcollection_[index - 1].SetDescription(description);
	pcollection_[index - 1].SetPrice(price);
	pcollection_[index - 1].SetQuantity(quantity);
}

void ProductStore::AddItem()
{
	Product* temp = new Product[size_ + 1];

	for (size_t i = 0; i < size_; i++)
	{
		temp[i].Copy(pcollection_[i]);
	}

	delete[] pcollection_;
	pcollection_ = temp;
	size_++;
}

void ProductStore::RemoveItem(size_t index)
{
	if (index <= 0 || index > size_)
	{
		cout << "Error!\n";
		return;
	}

	size_t ind = index - 1;
	Product* temp = new Product[size_ - 1];

	for (size_t i = 0; i < size_; i++)
	{
		if (i < ind)
		{
			temp[i].Copy(pcollection_[i]);
		}
		else if (i > ind)
		{
			temp[i - 1].Copy(pcollection_[i]);
		}
	}

	delete[] pcollection_;
	pcollection_ = temp;
	size_--;
}

void ProductStore::PrintAllCollection()
{
	for (size_t i = 0; i < size_; i++)
	{
		pcollection_[i].PrintName();
		pcollection_[i].PrintDescription();
		pcollection_[i].PrintPrice();
		pcollection_[i].PrintQuantity();
		cout << endl;
	}
}

void ProductStore::PrintCurCollection(size_t index)
{
	if (index <= 0 || index > size_)
	{
		cout << "Error!\n";
		return;
	}

	pcollection_[index - 1].PrintName();
	pcollection_[index - 1].PrintDescription();
	pcollection_[index - 1].PrintPrice();
	pcollection_[index - 1].PrintQuantity();
}
