//This program takes as the input multiple lines and tries to create a picture where lines are centered as evenly as possible by padding from left and right.


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cout;		using std::cin;
using std::string;		using std::vector;
using std::endl;		using std::max;
using std::getline;

vector<string> center(const vector<string> &);

int main(){

	//Reading from the input.
	cout << "Please enter the number of line you would like to enter." << endl;
	string tmp;
	getline(cin, tmp);
	int num_lines = atof(tmp.c_str());
	if (num_lines <= 0){
		cout << "Invalid number of lines entered, exiting." << endl;
		return -1;
	}
	cout << "Ok, please enter " << num_lines << " lines." << endl;

	vector<string> input;
	while(cin && num_lines-- > 0){
		getline(cin, tmp);
		input.push_back(tmp);
	}
	//Creating the centered image.
	vector<string> centered_input = center(input);

	//Printing the centered image.
	cout << "The centered input is as follows : " << endl;
	for(vector<string>::const_iterator iter = centered_input.begin(); iter != centered_input.end(); iter++)
		cout << *iter << endl;

	return 0;
}

vector<string> center(const vector<string> &input){

	//Finding the maximum width
	string::size_type max_len = 0;
	for(vector<string>::const_iterator iter = input.begin(); iter != input.end(); iter++)
		max_len = max(max_len, iter->size());

	//Creating the output.
	vector<string> centered_input;
	for(vector<string>::const_iterator iter = input.begin(); iter != input.end(); iter++){
		string::size_type cur_size = iter->size();
		string tmp = string((max_len-cur_size)/2, ' ') + *iter + string((max_len-cur_size) - (max_len-cur_size)/2, ' ');
		centered_input.push_back(tmp);
	}

	return centered_input;
}
