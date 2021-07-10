#pragma once

#include "Headers.h"

template <typename T>
class DoublyListItem
{
	//friend class DoublyLinkedList<T>;

public:
	DoublyListItem() = default;
	
	DoublyListItem(T data) 
	{
		data_ = data;
	}

//private:
	DoublyListItem* next_ = nullptr;
	DoublyListItem* prev_ = nullptr;
	T data_;
};

