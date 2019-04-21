#pragma once

template <typename Type>
class UniPtr
{
public:
	UniPtr();
	UniPtr(Type & object);
	UniPtr(Type * ptr);
	~UniPtr();
	
	bool is_null() const;
	Type operator *();
	
	operator Type* ();
	Type* operator ->();
	UniPtr & operator = (Type * ptr);
	
	void kill();
	void move(UniPtr<Type> & other);
	
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
