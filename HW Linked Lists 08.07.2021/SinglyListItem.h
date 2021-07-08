#pragma once

#include "Headers.h"

template <typename TValue >
struct SinglyListItem
{	
	SinglyListItem() = default;

	SinglyListItem(const TValue& value)
	{
		
		this->value_ = value;
	}

	SinglyListItem* next_ = nullptr;
	TValue value_;	
};

