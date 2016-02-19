#ifndef GAURD_student_info_H
#define GAURD_student_info_H

#include <iostream>
#include <vector>

typedef struct student_info
{
	std::string name;
	double overall_grade;
} student_info_t;

void read_info(std::istream &in, std::vector<student_info_t> &students, std::string::size_type &max_len);
std::istream &read_info(std::istream &in, std::string &name, double &mid, double &final, std::vector<double> &hw);

bool student_compare(student_info_t A, student_info_t B);

#endif
