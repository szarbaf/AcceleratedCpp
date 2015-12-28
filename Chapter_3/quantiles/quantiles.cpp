//This program reads in grades of a student from stdin and calculates the median, 1/4 and 3/4 quartiles.
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::sort;
using std::streamsize;
using std::vector;
using std::setprecision;
using std::streamsize;

double median_calc(vector<double> inp, vector<double>::size_type begin, vector<double>::size_type end);


int main()
{
	//Reading the grades.
	cout << "Please enter the grades, space delimited and signal EOF at the end." << endl;
	
	vector<double> grades;
	double tmp;
	while(cin >> tmp)
		if (tmp >= 0)
			grades.push_back(tmp);
		else
			cout << "The grades should be non-negative." << endl;
	typedef vector<double>::size_type vec_size;
	vec_size count = grades.size();
	if (count == 0)
	{
		cout << "No valid grades entered, exiting." << endl;
		return -1;
	}
	//Sorting the input.
	sort(grades.begin(), grades.end());
	
	//Calculating the median.
	vec_size mid = count/2;
	double median = median_calc(grades, 0, count-1);

	//Calculating first and third quantiles.
	double first_q, third_q;
	if (count % 2 == 0)
	{
		first_q = median_calc(grades, 0, mid-1);
		third_q = median_calc(grades, mid, count-1);
	}
	else
	{
		first_q = median_calc(grades, 0, mid);
		third_q = median_calc(grades, mid, count-1);
	}

	streamsize def_prec = cout.precision();
	
	cout << "The sorted grades are " << setprecision(3) << endl;
	for (int counter=0; counter < count; counter++)
		cout << grades[counter] << " ";
	cout << setprecision(def_prec) << endl;

	cout << "The median value is " << setprecision(3)
		 << median << endl << "The first quantile is "
		 << first_q << endl << "The third quantile is "
		 << third_q << setprecision(def_prec) << endl;
	
	return 0;
}

double median_calc(vector<double> inp, vector<double>::size_type begin, vector<double>::size_type end)
{
	vector<double>::size_type count = end-begin+1;
	vector<double>::size_type mid = count/2 + begin;
	return count % 2 == 0 ? (inp[mid-1]+inp[mid])/2 : inp[mid];

}
