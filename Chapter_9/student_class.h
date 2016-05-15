#include <iostream>
#include <string>
#include <istream>


class student_class
{
	public:
		void show_info() const;
		student_class(std::istream &in);

	private:
		std::string name;
		double midTerm;
		double finalExam;
		double totalGrade;

};
