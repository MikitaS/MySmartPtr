#pragma once

template <typename Type>
class UniPtr //Done and tested
{
public:
	UniPtr();
	UniPtr(Type & object);
	UniPtr(Type * ptr);
	~UniPtr();
	
	
	Type operator *();
	operator Type* ();
	Type* operator ->();
	UniPtr & operator = (Type * ptr);
	
	bool is_null() const;
	void kill();
	void move(UniPtr<Type> & other);
	
	UniPtr(const UniPtr<Type> & other) = delete;
	UniPtr & operator = (const UniPtr<Type> & other) = delete;

private:
	Type * pointer_;
};



template <typename Type>
struct ShrPointerStruct
{
	int counter_;
	Type * ptr_;
};

template <typename Type>
class SharedPtr
{
public:
	SharedPtr();//done, tested
	SharedPtr(SharedPtr<Type> & other);//done
	SharedPtr(Type * ptr);//done, tested
	SharedPtr(Type & other);//done, tested
	~SharedPtr();//done, tested
	
	bool is_null() const;
	int counter() const;
	void swap();
	void reset();
	
	SharedPtr & operator =(SharedPtr & other);
	
	Type operator *(); //done, tested
	Type* operator ->();
	operator Type* ();
	
private:
	ShrPointerStruct<Type> * ptrstruct_;
};


#include "sharedptr.hpp"
#include "uniptr.hpp"
