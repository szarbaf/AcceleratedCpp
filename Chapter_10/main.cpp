#include <iostream>
#include <string>
#include "split.h"
#include "class_list.h"

//This program tests a class that implements a list of strings with bidirectional iterators.

using std::string;		using std::cout;
using std::endl;

int main()
{
	//Creating an arbitrary string.
	string test("Hello My friend! How are you doing?");
	class_list list = split(test);
	int num_items = list.size();
	//Traversing to the end and printing.
	
	cout << "Printing the string forward." << endl;
	for(class_list::iterator iter = list.begin(); iter != list.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	//Traversing to the beginning and printing.
	cout << "Printing the string backward." << endl;
	for (class_list::reverse_iterator riter = list.rbegin(); riter != list.rend(); riter++)
		cout << *riter << " ";
	cout << endl;

	return 0;
}
