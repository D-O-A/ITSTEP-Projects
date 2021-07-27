#pragma once
#include "Headers.h"

enum Priority
{
	LOW = 1,
	MEDIUM,
	HIGH
};

template <typename T>
class Queue
{
public:

	Queue() = default;
	Queue(const Queue& that);
	Queue(Queue&& that);
	~Queue();

	void Clear();

	Queue& operator=(const Queue& that);
	Queue& operator=(Queue&& that);

	void Enqueue(const T& value, Priority priority);
	void Enqueue(const T& value);
	void Dequeue();

	void Peek() const;
	void Print() const;

	size_t GetSize() const;

private:

	template <typename T>
	struct Node
	{
		Node() = default;

		Node(const T& value, Priority priority)
		{
			value_ = value;
			priority_ = priority;
		}

		Node(const T& value)
		{
			value_ = value;
		}

		Node* pNext_ = nullptr;
		T value_ = NULL;
		Priority priority_ = HIGH;
	};

	void Copy(const Queue& that);

	Node<T>* pHead_ = nullptr;
	size_t size_ = 0;
};

template<typename T>
inline Queue<T>::Queue(const Queue& that)
{
	Copy(that);
}

template<typename T>
inline Queue<T>::Queue(Queue&& that)
{
	pHead_ = that.pHead_;
	size_ = that.size_;

	that.pHead_ = nullptr;
	that.size_ = 0;
}

template<typename T>
inline Queue<T>::~Queue()
{
	Clear();
}

template<typename T>
inline void Queue<T>::Clear()
{
	Node<T>* delItem = nullptr;

	while (pHead_ != nullptr)
	{
		delItem = pHead_;
		pHead_ = delItem->pNext_;
		delete delItem;
	}

	size_ = 0;
}

template<typename T>
inline Queue<T>& Queue<T>::operator=(const Queue<T>& that)
{
	if (this != &that)
	{
		Clear();
		Copy(that);
	}

	return *this;
}

template<typename T>
inline Queue<T>& Queue<T>::operator=(Queue<T>&& that)
{
	if (this != &that)
	{
		Clear();

		this->pHead_ = that.pHead_;
		that.pHead_ = nullptr;

		this->size_ = that.size_;
		that.size_ = 0;
	}

	return *this;
}

template<typename T>
inline void Queue<T>::Enqueue(const T& value, Priority priority)
{
	Node<T>* newNode = new Node<T>(value, priority);
	Node<T>* cursor = pHead_;

	if (pHead_ == nullptr)
	{
		pHead_ = newNode;
	}
	else if (pHead_->priority_ > priority)
	{
		newNode->pNext_ = pHead_;
		pHead_ = newNode;
	}
	else
	{
		while (cursor->pNext_ != nullptr && cursor->pNext_->priority_ < priority)
		{
			cursor = cursor->pNext_;
		}

		newNode->pNext_ = cursor->pNext_;
		cursor->pNext_ = newNode;
	}

	size_++;
}

template<typename T>
inline void Queue<T>::Enqueue(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	Node<T>* cursor = pHead_;

	if (pHead_ == nullptr)
	{
		pHead_ = newNode;
	}
	else if (pHead_->priority_ > HIGH)
	{
		newNode->pNext_ = pHead_;
		pHead_ = newNode;
	}
	else
	{
		while (cursor->pNext_ != nullptr && cursor->pNext_->priority_ < HIGH)
		{
			cursor = cursor->pNext_;
		}

		newNode->pNext_ = cursor->pNext_;
		cursor->pNext_ = newNode;
	}

	size_++;
}

template<typename T>
inline void Queue<T>::Dequeue()
{
	if (pHead_ == nullptr)
	{
		return;
	}

	Node<T>* delNode = nullptr;

	if (size_ == 1)
	{
		delNode = pHead_;
		pHead_ = delNode->pNext_;
	}
	else
	{
		Node<T>* prevNode = pHead_;

		for (size_t i = 0; i < size_ - 2; i++)
		{
			prevNode = prevNode->pNext_;
		}

		delNode = prevNode->pNext_;
		prevNode->pNext_ = nullptr;
	}

	delete delNode;
	size_--;
}

template<typename T>
inline void Queue<T>::Peek() const
{
	Node<T>* cursor = pHead_;

	for (size_t i = 0; i < size_ - 1; i++)
	{
		cursor = cursor->pNext_;
	}

	cout << cursor->value_ << endl;
}

template<typename T>
inline void Queue<T>::Print() const
{
	Node<T>* cursor = pHead_;

	while (cursor != nullptr)
	{
		cout << cursor->value_ << " " << cursor->priority_ << "\t";
		cursor = cursor->pNext_;
	}
	cout << endl;
}

template<typename T>
inline size_t Queue<T>::GetSize() const
{
	return size_;
}

template<typename T>
inline void Queue<T>::Copy(const Queue& that)
{
	Node<T>* cursor = that.pHead_;
	Node<T>* prev = nullptr;

	while (cursor != nullptr)
	{
		Node<T>* newItem = new Node<T>(cursor->value_, cursor->priority_);

		if (cursor == that.pHead_)
		{
			pHead_ = newItem;
		}
		else
		{
			prev->pNext_ = newItem;
		}

		prev = newItem;
		cursor = cursor->pNext_;
	}

	size_ = that.size_;
}