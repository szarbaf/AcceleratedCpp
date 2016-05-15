#include <iostream>
#include "student_class.h"


using std::cin;     using std::cout;
using std::endl;

int main(){

	student_class shapal(cin);

	cout << "The student info are as follows:" << endl;
	shapal.show_info();
    return 0;

}

