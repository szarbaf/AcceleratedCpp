//This code implements median function written as template.

#include <iostream>
#include <vector>
#include "template_funs.h"

using std::cout;		using std::cin;
using std::vector;		using std::endl;

int main(){
	
	//Reading an arbitrary array.
	vector<double> input;
	double tmp;
	cout << "Please eneter an array of numbers." << endl;
	while (cin >> tmp)
		input.push_back(tmp);
	
	//Finding the median.
	double median_num = template_median(input);

	//Outputting the result.
	cout << "The median of the vector is : " << median_num << endl;

	return 0;
	
}
