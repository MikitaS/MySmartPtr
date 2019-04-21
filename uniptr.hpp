#pragma once

#include "smartptr.hpp"

template <typename Type>
UniPtr<Type>::UniPtr() : pointer_(nullptr) { }

template <typename Type>
UniPtr<Type>::UniPtr(Type & object) : pointer_(new Type) 
{
	*pointer_ = object; 
}

template <typename Type>
UniPtr<Type>::UniPtr(Type * ptr): pointer_(ptr) { }


template <typename Type>
UniPtr<Type>::~UniPtr()
{
	if(pointer_)
		delete pointer_;
}
