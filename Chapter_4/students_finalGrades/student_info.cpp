#include <iostream>
#include <vector>
#include <stdexcept>

#include "student_info.h"
#include "grading.h"

using std::vector;			using std::string;
using std::istream;			using std::cout;
using std::domain_error;	using std::max;
using std::endl;

void read_info(istream &in, vector<student_info_t> &students, string::size_type &max_len)
{
	student_info_t student;
	double mid, final, overall;
	vector<double> hw;
	max_len = 0;
	cout << "Please enter name, midterm, final and hw grades(at least one hw grade for per student) for each student." << endl;
	while ( read_info(in, student.name, mid, final, hw) )
	{
		try
		{
			overall = grade(mid, final, hw, median);
			student.overall_grade = overall;
			max_len = max(max_len, student.name.size());
			students.push_back(student);
		}
		catch (domain_error e)
		{
			cout << e.what();
		}

	}
}

istream &read_info(istream &in, string &name, double &mid, double &final, vector<double> &hw)
{
	in >> name >> mid >> final;
	if (in)
	{
		hw.clear();
		double tmp;
		while (in >> tmp)
			hw.push_back(tmp);
		
		in.clear();
	}

	return in;
}

bool student_compare(student_info_t A, student_info_t B)
{
	return A.name < B.name;
}
