#include "ProductStore.h"

ProductStore::ProductStore(size_t size)
{
	pcollection_ = new Product[size];
	size_ = size;
}

ProductStore::~ProductStore()
{
	Clear();
}

ProductStore::ProductStore(const ProductStore& store)
{
	Copy(store);
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
		temp[i] = pcollection_[i];
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
			temp[i] = pcollection_[i];
		}
		else if (i > ind)
		{
			temp[i - 1] = pcollection_[i];
		}
	}

	delete[] pcollection_;
	pcollection_ = temp;
	size_--;
}

size_t ProductStore::operator[](const char* name)
{
	for (size_t i = 0; i < size_; i++)
	{
		if (_stricmp(pcollection_[i].GetName(), name) == 0)
		{
			return i;
		}
	}

	return -1;
}

Product& ProductStore::operator[](size_t index)
{
	return pcollection_[index];
}

ProductStore& ProductStore::operator=(const ProductStore& collection)
{
	if (this != &collection)
	{
		Clear();
		Copy(collection);
	}

	return *this;
}

ProductStore& ProductStore::operator=(ProductStore&& collection)
{
	if (this != &collection)
	{
		Clear();

		for (size_t i = 0; i < size_; i++)
		{
			this->pcollection_[i] = collection.pcollection_[i];
		}

		this->size_ = collection.size_;

		collection.pcollection_ = nullptr;
		collection.size_ = 0;
	}

	return *this;
}

void ProductStore::PrintSearchResult(size_t index)
{
	size_t key = index + 1;

	if (key >= 1)
	{
		PrintCurCollection(key);
	}
	else
	{
		cout << "Not found!" << endl;
	}
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

void ProductStore::Clear()
{
	if (pcollection_ != nullptr)
	{
		delete[] pcollection_;
		pcollection_ = nullptr;
	}
}

void ProductStore::Copy(const ProductStore& store)
{
	size_ = store.size_;
	pcollection_ = new Product[size_];

	for (size_t i = 0; i < size_; i++)
	{
		pcollection_[i] = store.pcollection_[i];
	}

	size_ = store.size_;
}
