#include <iostream>
#include <istream>

#include "student_class.h"

using namespace std;

student_class::student_class(istream &in)
{
	cout << "Please enter student's name:" << endl;
	in >> name_;

	cout << "Please enter student's midterm exam grade:" << endl;
	in >> mid_term_;

	cout << "Please enter student's Final exam grade:" << endl;
	in >> final_exam_;

	total_grade_ = (mid_term_+final_exam_)/2;
	
}

void student_class::show_info() const
{
	cout << "The student name is : " << name_ << endl
		 << "The student total grade is : " << total_grade_ << endl;


}

bool student_class::grade(){
		if (valid()){
				total_grade_ = (mid_term_+final_exam_)/2;
				return true;
		}
		else{
				cout << "The student " << name_ << " fields are not populated." << endl;
				return false;
		}

}
