#pragma once

#include "Headers.h"

template <typename T>
class DoublyLinkedList
{
public:

	DoublyLinkedList() = default;

	DoublyLinkedList(const DoublyLinkedList& list)
	{
		DoublyListItem<T>* cursor = list.head_;
		DoublyListItem<T>* prevItem = nullptr;

		while (cursor != nullptr)
		{
			DoublyListItem<T>* newItem = new DoublyListItem<T>(cursor->data_);

			if (cursor == list.head_)
			{
				head_ = newItem;
			}
			else
			{
				prevItem->next_ = newItem;
				newItem->prev_ = prevItem;
			}

			prevItem = newItem;
			cursor = cursor->next_;
		}

		tail_ = prevItem;
		size_ = list.size_;
	}

	DoublyLinkedList(DoublyLinkedList&& list) 
	{
		head_ = list.head_;
		tail_ = list.tail_;
		size_ = list.size_;
		
		list.head_ = nullptr;		
		list.tail_ = nullptr;		
		list.size_ = 0;
	}

	void AddToFront(T data)
	{
		DoublyListItem<T>* newItem = new DoublyListItem<T>(data);

		if (tail_ == nullptr) 
		{			
			tail_ = newItem;
		}
		else 
		{
			newItem->next_ = head_; //направл€ем новый элемент на первый в списке
			head_->prev_ = newItem; //направл€ем первый элемент списка на новый			
		}

		head_ = newItem; //головой списка становитс€ новый элемент
		size_++;
	}

	void AddToBack(T data) 
	{
		DoublyListItem<T>* newItem = new DoublyListItem<T>(data);

		if (head_ == nullptr) 
		{
			head_ = newItem;			
		}
		else
		{
			newItem->prev_ = tail_;
			tail_->next_ = newItem;			
		}
		
		tail_ = newItem;
		size_++;
	}

	void AddAt(const T& value, size_t index)
	{
		DoublyListItem<T>* new_item = new DoublyListItem<T>(value);
		DoublyListItem<T>* cursor = nullptr;

		//if (head_ == nullptr)
		//{
		//	AddToFront(value);
		//}

		if (index == 0)
		{
			AddToFront(value);
		}
		else if (index == size_ - 1)
		{
			new_item->prev_ = tail_;
			tail_->next_ = new_item;
			tail_ = new_item;
		}
		else
		{
			cursor = search(index);
			cursor->prev_->next_ = new_item;
			new_item->next_ = cursor;
			new_item->prev_ = cursor->prev_;
			cursor->prev_ = new_item;
		}

		size_++;
	}

	void RemoveByIndex(size_t index) 
	{
		DoublyListItem<T>* delItem = nullptr;

		//нет проверки если список пуст. ћожно сразу вызвать функцию search, и в случае, если список пуст, вернет исключение "Index out of range"
		//либо же вариант ниже, сразу проверку на nullptr
	
		//delItem = search(index);

		if (head_ == nullptr)
		{
			throw exception("List is empty");
		}

		if (head_ == tail_ && head_ != nullptr) //единственный элемент в списке
		{
			delItem = head_;
			head_ = nullptr;
			tail_ = nullptr;			
		}
		else if (index == 0) //удал€ем из начала
		{
			delItem = head_;
			head_ = head_->next_;
			head_->prev_ = nullptr;
		}
		else if (index == size_ - 1) //удал€ем с конца
		{
			delItem = tail_;
			tail_ = tail_->prev_;
			tail_->next_ = nullptr;
		}
		else
		{
			delItem = search(index);
			delItem->prev_->next_ = delItem->next_;
			//неправильно перенаправлен указатель
			//delItem->prev_->next_ = delItem->prev_;
			delItem->next_->prev_ = delItem->prev_;
		}

		delete delItem;
		size_--;
	}

	size_t GetSize() const 
	{
		return size_;
	}

	T GetFront() const 
	{
		if (head_ == nullptr)
		{
			throw exception("List is empty");
		}

		return head_->data_;
	}

	T GetBack() const
	{
		if (tail_ == nullptr) 
		{
			throw exception("List is empty");
		}

		return tail_->data_;
	}

	void Print() 
	{
		DoublyListItem<T>* cursor = head_;

		while (cursor != nullptr)
		{
			cout << cursor->data_ << "\t";
			cursor = cursor->next_;
		}
		cout << endl;
	}

	void ReversePrint() 
	{
		DoublyListItem<T>* cursor = tail_;

		while (cursor != nullptr)
		{
			cout << cursor->data_ << "\t";
			cursor = cursor->prev_;
		}
		cout << endl;
	}

private:

	DoublyListItem<T>* head_ = nullptr;
	DoublyListItem<T>* tail_ = nullptr;

	size_t size_ = 0;

	DoublyListItem<T>* search(size_t index) 
	{
		if (index >= size_) 
		{
			throw exception("Index out of range");
		}

		DoublyListItem<T>* cursor = head_;

		for (size_t i = 0; i < index; i++)
		{
			cursor = cursor->next_;
		}

		//?
		if (cursor == nullptr)
		{
			throw exception("List is empty");
		}

		return cursor;
	}
};

