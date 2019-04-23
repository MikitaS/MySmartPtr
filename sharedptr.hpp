#pragma once

#include "smartptr.hpp"

template <typename Type>
SharedPtr<Type>::SharedPtr() : ptrstruct_(new ShrPointerStruct<Type>)
{
	ptrstruct_ -> counter_ = 1;
	ptrstruct_ -> ptr_ = nullptr;
}

template <typename Type>
SharedPtr<Type>::~SharedPtr()
{
	ptrstruct_ -> counter_--;
	
	if(ptrstruct_ -> counter_ == 0)
	{
		delete ptrstruct_ -> ptr_;
		ptrstruct_ -> ptr_ = nullptr;
	
		delete ptrstruct_;
	}
	
	ptrstruct_ = nullptr;
}

template <typename Type>
SharedPtr<Type>::SharedPtr(Type * other) : ptrstruct_(new ShrPointerStruct<Type>)
{
	ptrstruct_ -> ptr_ = other;
	ptrstruct_ -> counter_ = 1;
}


template <typename Type>
SharedPtr<Type>::SharedPtr(Type & other) : ptrstruct_(new ShrPointerStruct<Type>)
{
	ptrstruct_ -> ptr_ = new Type;
	*(ptrstruct_ -> ptr_) = other;
	ptrstruct_ -> counter_ = 1;
}

template <typename Type>
SharedPtr<Type>::SharedPtr(SharedPtr<Type> & other) : ptrstruct_(other.ptrstruct_)
{
	ptrstruct_ -> counter_++;
}
 

template <typename Type>
Type SharedPtr<Type>::operator *()
{
	return *(ptrstruct_ -> ptr_);
}

template <typename Type>
Type* SharedPtr<Type>::operator ->()
{
	return ptrstruct_ -> ptr_;
}

template <typename Type>
SharedPtr<Type>::operator Type*()
{
	return ptrstruct_ -> ptr_;
}
