#include <iostream>
#include <string>

#include "smartptr.hpp"

using namespace std;

bool TestUniPtr();
bool TestSharedPtr();

bool TestUniPtr()//done, code was covered
{
	UniPtr<int> intptr;
	intptr.kill();
	
	string str = "hello world";
	UniPtr<string> strptr(str), str2ptr(new string("hello Uniqual pointer"));
	
	if(*str2ptr != "hello Uniqual pointer")
		return false;
	
	if(*strptr != str)
		return false;
		
	if(*(string*)strptr != str)
		return false;
		
	if(strptr->length() != str.length())
		return false;
		
	strptr.move(str2ptr);
	
	if( *strptr != "hello Uniqual pointer")
		return false;
	
	if( *str2ptr != str)
		return false;
	
	return true;
}

bool TestSharedPtr()//code needs to be covered
{
	return true;
}

int main()
{
	cout << "______________________________________________________" << endl << endl;
	
	if(TestUniPtr())
		cout << " + Test of unique pointer passed correctly" << endl;
	else
		cout << " - Test of unique pointer failed" << endl;
		
	if(TestSharedPtr())
		cout << " + Test of shared pointer passed correctly" << endl;
	else
		cout << " - Test of shared pointer failed" << endl;
		
	cout << endl << "______________________________________________________" << endl << endl;
	return 0;
}
