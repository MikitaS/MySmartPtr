#pragma once

template <typename Type>
class UniPtr
{
public:
	UniPtr();//done
	UniPtr(Type & object);//done
	UniPtr(Type * ptr);//done
	~UniPtr();//done
	
	bool is_null() const;//done
	Type operator *();//done
	
	operator Type* ();//done
	Type* operator ->();//done
	UniPtr & operator = (Type * ptr);//done
	
	UniPtr(const UniPtr<Type> & other) = delete;
	UniPtr & operator = (const UniPtr<Type> & other) = delete;

private:
	
	
	Type * pointer_;
};

template <typename Type>
class SharedPtr
{
	
};


#include "sharedptr.hpp"
#include "uniptr.hpp"
