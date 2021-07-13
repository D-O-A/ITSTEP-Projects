#pragma once

#include "Headers.h"

template <typename TValue>
class SinglyLinkedList
{
public:
	SinglyLinkedList() = default;
	SinglyLinkedList(const SinglyLinkedList<TValue>& that);
	SinglyLinkedList(SinglyLinkedList<TValue>&& that);
	~SinglyLinkedList();

	void AddToBack(const TValue& value); //добавление в конец списка
	void AddToFront(const TValue& value);
	void AddAt(const TValue& value, size_t index);
	void RemoveAt(size_t index);
	void Clear();

	SinglyLinkedList<TValue>& operator=(const SinglyLinkedList<TValue>& that);
	SinglyLinkedList<TValue>& operator=(SinglyLinkedList<TValue>&& that);

	TValue& operator[](size_t index);
	const TValue& operator[](size_t index) const;

	void Print() const;

	size_t GetSize() const
	{
		return size_;
	}

private:
	
	void Copy(const SinglyLinkedList& that);
	SinglyListItem<TValue>* head_ = nullptr;
	size_t size_ = 0;
};

template<typename TValue>
inline SinglyLinkedList<TValue>::SinglyLinkedList(const SinglyLinkedList<TValue>& that)
{
	Copy(that);
}

template<typename TValue>
inline SinglyLinkedList<TValue>::SinglyLinkedList(SinglyLinkedList<TValue>&& that)
{
	head_ = that.head_;
	size_ = that.size_;

	that.head_ = nullptr;
	that.size_ = 0;
}

template<typename TValue>
inline SinglyLinkedList<TValue>::~SinglyLinkedList()
{
	Clear();
}

template<typename TValue>
inline void SinglyLinkedList<TValue>::AddToBack(const TValue& value)
{
	SinglyListItem<TValue>* newItem = new SinglyListItem<TValue>(value);

	if (head_ == nullptr)
	{
		head_ = newItem;
	}
	else
	{
		//search list item
		SinglyListItem<TValue>* cursor = head_;

		while (cursor->next_ != nullptr)//пока есть следующий элемент
		{
			cursor = cursor->next_;
		}

		//в последний элемент записать адрес нового элемента
		cursor->next_ = newItem; 
	}

	size_++;

}

template<typename TValue>
inline void SinglyLinkedList<TValue>::AddToFront(const TValue& value)
{
	SinglyListItem<TValue>* newItem = new SinglyListItem<TValue>(value);

	if (head_ != nullptr)
	{
		newItem->next_ = head_;
	}

	head_ = newItem;
	size_++;
}

template<typename TValue>
inline void SinglyLinkedList<TValue>::AddAt(const TValue& value, size_t index)
{
	if (index >= size_)
	{
		throw exception("Index out of range");
	}

	SinglyListItem<TValue>* new_item = new SinglyListItem<TValue>(value);

	if (index == 0)
	{
		new_item->next_ = head_;
		head_ = new_item;
	}
	else
	{
		//size_t counter = 0;

		SinglyListItem<TValue>* cursor = head_;

		for (size_t i = 0; i < index - 1; i++)
		{
			cursor = cursor->next_;
		}

		//while (counter != index - 1)
		//{
		//	cursor = cursor->next_;
		//	counter++;
		//}

		new_item->next_ = cursor->next_;

		cursor->next_ = new_item;
	}

	size_++;
}

template<typename TValue>
inline void SinglyLinkedList<TValue>::RemoveAt(size_t index)
{
	if (index >= size_)
	{
		throw exception("Index out of range");
	}

	SinglyListItem<TValue>* delItem = nullptr;
	if (index == 0)
	{
		//если удаляемый элемент первый
		delItem = head_;
		//перенапрявляем голову на втрой элемент
		head_ = delItem->next_;
	}
	else
	{
		//поиск элемента перед удаляемым
		SinglyListItem<TValue>* prevItem = head_;
		for (size_t i = 0; i < index - 1; i++)
		{
			prevItem = prevItem->next_;
		}

		//сохраняем адрес удаляемого элемента
		delItem = prevItem->next_;

		//перенаправляем указатель
		prevItem->next_ = delItem->next_;
	}

	//удаляем элемент
	delete delItem;
	size_--;

}

template<typename TValue>
inline void SinglyLinkedList<TValue>::Clear()
{
	SinglyListItem<TValue>* delItem = nullptr;

	while (head_ != nullptr)
	{
		delItem = head_;
		head_ = delItem->next_;
		delete delItem;
	}

	size_ = 0;
}

template<typename TValue>
inline SinglyLinkedList<TValue>& SinglyLinkedList<TValue>::operator=(const SinglyLinkedList<TValue>& that)
{
	if (this != &that)
	{
		Clear();
		Copy(that);
	}

	return *this;
}

template<typename TValue>
inline SinglyLinkedList<TValue>& SinglyLinkedList<TValue>::operator=(SinglyLinkedList<TValue>&& that)
{
	//как протестировать??
	if (this != &that)
	{
		Clear();

		this->head_ = that.head_;
		that.head_ = nullptr;

		this->size_ = that.size_;
		that.size_ = 0;
	}

	return *this;
}

template<typename TValue>
inline TValue& SinglyLinkedList<TValue>::operator[](size_t index)
{
	if (index >= size_)
	{
		throw exception("Index out of range");
	}

	SinglyListItem<TValue>* cursor = head_;
	for (size_t i = 0; i < index; i++)
	{
		cursor = cursor->next_;
	}

	return cursor->value_;
}

template<typename TValue>
inline const TValue& SinglyLinkedList<TValue>::operator[](size_t index) const
{
	if (index >= size_)
	{
		throw exception("Index out of range");
	}

	SinglyListItem<TValue>* cursor = head_;
	for (size_t i = 0; i < index; i++)
	{
		cursor = cursor->next_;
	}

	return cursor->value;
}

template<typename TValue>
inline void SinglyLinkedList<TValue>::Print()const
{
	SinglyListItem<TValue>* cursor = head_;

	while (cursor != nullptr)
	{
		cout << cursor->value_ << "\t";
		cursor = cursor->next_;
	}
	cout << endl;
}

template<typename TValue>
inline void SinglyLinkedList<TValue>::Copy(const SinglyLinkedList& that)
{
	SinglyListItem<TValue>* cursor = that.head_;
	SinglyListItem<TValue>* prev = nullptr;

	while (cursor != nullptr)
	{
		SinglyListItem<TValue>* newItem = new SinglyListItem<TValue>(cursor->value_);

		if (cursor == that.head_)
		{
			head_ = newItem;
		}
		else
		{
			prev->next_ = newItem;
		}

		prev = newItem;
		cursor = cursor->next_;
	}

	size_ = that.size_;
}
