//This code employes a function for splitting a string of characters into different words.
#include <iostream>
#include <vector>
#include <cctype>

using std::cout;		using std::cin;
using std::string;		using std::getline;
using std::endl;		using std::isspace;
using std::vector;

vector<string> split(const string &);

int main(){
	
	//Reading a line of input from the stdin.
	cout << "Please enter a line of characters." << endl;
	string input;
	getline(cin, input);

	//Splitting the input.
	vector<string> splitted = split(input);

	//Showing the splitted version.
	cout << "The splitted line is : " << endl;
	for (vector<string>::const_iterator iter = splitted.begin(); iter != splitted.end(); iter++)
		cout << *iter << endl;

	return 0;

}

vector<string> split(const string &input){
	
	//i denotes the start of a new word.
	typedef string::size_type string_size;
	string_size i=0,j,input_size=input.size();
	
	vector <string> splitted;
	while (i < input_size){

		//Skipping the leading spaces
		while(i < input_size && isspace(input[i]))
			i++;

		//Incrementing j till hitting a new space character.
		for(j = i; j < input_size && !isspace(input[j]); j++)
			;

		//Checking whether a j is incremented and adding the new word to the output vector.
		if (j > i){
			splitted.push_back(input.substr(i, j-i));
			i = j;
		}

	}
	
	return splitted;
}
