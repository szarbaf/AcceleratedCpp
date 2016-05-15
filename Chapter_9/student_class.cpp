#include <iostream>
#include <istream>

#include "student_class.h"

using std::istream;		using std::endl;
using std::cout;		using std::cin;

student_class::student_class(istream &in)
{
	cout << "Please enter student's name:" << endl;
	in >> name;

	cout << "Please enter student's midterm exam grade:" << endl;
	in >> midTerm;

	cout << "Please enter student's Final exam grade:" << endl;
	in >> finalExam;

	totalGrade = (midTerm+finalExam)/2;
	
}

void student_class::show_info() const
{
	cout << "The student name is : " << name << endl
		 << "The student total grade is : " << totalGrade << endl;


}
