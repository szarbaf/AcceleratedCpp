//This program creates a cross reference out of an input text where for each word all the lines that it occurs in will be printed.

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>

using std::map;		using std::vector;
using std::cin;		using std::cout;
using std::ifstream;using std::string;
using std::endl;	using std::getline;
using std::find;	using std::isspace;
using std::find_if;

typedef map<string, vector<int> >::const_iterator map_iter;
typedef string::const_iterator iter_string;

vector<string> split(string);
map <string, vector<int> > xref(ifstream&);

int main(){

	//Calling the cross-reference function.
	ifstream fp;
	fp.open("main.cpp");
	map <string, vector<int> > table = xref(fp);
	fp.close();
	
	//Printing the results.
	cout << endl << "The cross-reference is as follows:" << endl;
	for (map_iter word = table.begin(); word != table.end(); word++){

		//Printing the word.
		cout << word->first << " : ";
		//Printing the line numbers.
		vector <int> lines = word->second;
		cout << lines[0];
		for (vector<int>::const_iterator iter = lines.begin()+1; iter != lines.end(); iter++)
			cout <<", " << *iter;
		cout << endl;
	}

	return 0;
	
}

map <string, vector<int> > xref(ifstream &is){
	
	string line;
	int line_counter = 1;
	map <string, vector<int> > ret;
	while(getline(is, line)){
		vector <string> splitted = split(line);

		for(vector<string>::const_iterator word = splitted.begin(); word != splitted.end(); word++){
			vector<int> line_nums = ret[*word];
			if(line_nums.empty() || (find(line_nums.begin(), line_nums.end(), line_counter) == line_nums.end()) )
				ret[*word].push_back(line_counter);
		}

		line_counter++;
	}

	return ret;
}

bool not_space(char c){
	return isalpha(c);
}

bool space(char c){
	return !not_space(c);
}


vector<string> split(string line){

	vector<string> ret;
	iter_string b = line.begin(), e = line.end();
	
	while(b != e){

		//Skipping the leading spaces.
		b = find_if(b, e, not_space);
		//Finding the end of the word.
		iter_string tmp = find_if(b, e, space);
		//Adding the word
		if (b != e)
			ret.push_back(string(b, tmp));
		b = tmp;
	}

	return ret;
}
