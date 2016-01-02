//This program reads in grades of a student from stdin and calculates the median.
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
	
	vector<double>::size_type count = grades.size();
	if (count == 0)
	{
		cout << "No valid grades entered, exiting." << endl;
		return -1;
	}
	//Sorting the input.
	sort(grades.begin(), grades.end());
	
	//Calculating the median.
	vector<double>::size_type mid = count/2;
	double median = count % 2 == 0 ? (grades[mid-1]+grades[mid])/2 : grades[mid];

	streamsize def_prec = cout.precision();
	
	cout << "The sorted grades are " << setprecision(3) << endl;
	for (int counter=0; counter < count; counter++)
		cout << grades[counter] << " ";
	cout << setprecision(def_prec) << endl;

	cout << "The median value is " << setprecision(3)
		 << median << setprecision(def_prec) << endl;
	
	return 0;
}
