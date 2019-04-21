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

template <typename Type>
bool UniPtr<Type>::is_null() const
{
	return !pointer_;
}

template <typename Type>
Type UniPtr<Type>::operator *()
{
	return *pointer_;
}

template <typename Type>
UniPtr<Type>::operator Type* ()
{
	return pointer_;
}

template <typename Type>
UniPtr<Type> & UniPtr<Type>::operator = (Type * ptr)
{
	delete pointer_;
	pointer_ = ptr;
	
	return *this;
}

template <typename Type>
Type * UniPtr<Type>::operator ->()
{
	return pointer_;
}

template <typename Type>
void UniPtr<Type>::kill()
{
	delete pointer_;
	pointer_ = 0;
}

template <typename Type>
void UniPtr<Type>::move(UniPtr<Type> & other)
{
	Type * cptr = this->pointer_;
	
	this->pointer_ = other.pointer_;
	other.pointer_ = cptr;
}
