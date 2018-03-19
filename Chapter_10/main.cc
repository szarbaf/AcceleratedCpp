#include <iostream>
#include <string>
#include "split.h"
#include "class_list.h"
#include "class_iterator.h"

//This program tests a class that implements a list of strings with bidirectional iterators.

using std::string;		using std::cout;
using std::endl;

int main()
{
	//Creating an arbitrary string.
	string test("Hello My friend! How are you doing?");
	class_list list = split(test);
	cout << "The number of elements are : " << list.size() << endl;
	//Traversing to the end and printing.
	
	cout << "Printing the string backward." << endl;

	while(list.size() != 0)
			cout << list.pop() << " ";
	cout << endl;
	

/*
	for(class_iterator iter = list.begin(); iter != list.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
*/
	return 0;
}
