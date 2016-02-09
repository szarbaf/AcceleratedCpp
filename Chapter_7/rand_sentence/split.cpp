#include "split.h"
#include <cctype>

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
