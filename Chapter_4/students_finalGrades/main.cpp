//This program reads in from standard input students' grades; each line should be of the following format:
//StudentName MidTermGrade FinalGrade MultipleHomeWorkGrade
//The number of homework grades for each student might be a different.
//The overall grade is calculated as : 0.2*Midterm + 0.4*Final + 0.4*AverageHW

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

#include "student_info.h"

using std::cout;		using std::cin;
using std::string;		using std::vector;
using std::sort;		using std::endl;	
using std::streamsize;	using std::setprecision; 

int main()
{
	//Reading the students info from the stdin.
	vector<student_info_t> students;
	string::size_type max_len;
	read_info(cin, students, max_len);
	
	//Sorting the info alphabetically.
	sort(students.begin(), students.end(), student_compare);
	
	//Displaying the overall grades.
	if (students.size() == 0)
	{
		cout << "No student info was succesfully received, exiting." << endl;
		return 1;
	}
	cout << endl << "The students overall grades are : " << endl;
	for (vector<student_info_t>::size_type st_counter = 0; st_counter < students.size(); st_counter++)
	{
		student_info_t &student = students[st_counter];
		//Printing whitespaces.
		cout << student.name 
			 << string(max_len - student.name.size() + 1, ' ');

		streamsize prec = cout.precision();
		cout << setprecision(3) << student.overall_grade 
			 << setprecision(prec) << endl;
	}

	return 0;
	
}
