#ifndef _STUDENT_CLASS_
#define _STUDENT_CLASS_

#include <iostream>
#include <string>
#include <istream>


class student_class
{
	public:
		void show_info() const;
		student_class(std::istream &in);
		student_class(std::string name, double mid_term, double final_exam) : name_(name), mid_term_(mid_term), final_exam_(final_exam) {}
		std::string GetName() const {return name_;}
		
		double GetTotalGrade() const {return total_grade_;}
		bool grade();
		
		bool valid() {return name_.size();}

	private:
		std::string name_;
		double mid_term_;
		double final_exam_;
		double total_grade_;

};

#endif
