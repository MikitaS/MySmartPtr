#include <iostream>
#include <string>

#include "smartptr.hpp"

using namespace std;

bool TestUniPtr();

bool TestUniPtr()
{
	UniPtr<int> intptr;
	
	string str = "hello world";
	UniPtr<string> strptr(str);
	
	if(*strptr != str)
		return false;
		
	if(*(string*)strptr != str)
		return false;
		
	if(strptr->length() != str.length())
		return false;
	
	return true;
}

int main()
{
	if(TestUniPtr())
		cout << " + Test of unique pointer passed correctly" << endl;
	else
		cout << " - Test of unique pointer failed" << endl;
	return 0;
}
