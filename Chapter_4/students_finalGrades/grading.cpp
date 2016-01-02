#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "grading.h"

using std::vector;		using std::domain_error;
using std::string;		using std::sort;

double grade(double mid, double final, const vector<double> &hw, double (*hw_reduce) (const vector<double> &hw))
{
	if (hw.size() == 0)
		throw domain_error("No hw entered for student.");
	
	double reduced_hw = hw_reduce(hw);

	return grade(mid, final, reduced_hw);
}

double grade(double mid, double final, double reduced_hw)
{
	return 0.2 * mid + 0.4 * final + 0.4 * reduced_hw; 
}

double median(const vector<double> &hw)
{
	vector<double> tmp = hw;
	sort(tmp.begin(), tmp.end());
	vector<double>::size_type count = tmp.size();

	vector<double>::size_type mid = count/2;
	return count % 2 == 0? (hw[mid-1]+hw[mid])/2 : hw[mid];
}

double average (const vector<double> &hw)
{
	vector<double>::size_type count = hw.size();
	double ave = 0;
	for (int counter = 0; counter < count; counter++)
		ave += hw[counter];
	
	return ave/count;
}		

