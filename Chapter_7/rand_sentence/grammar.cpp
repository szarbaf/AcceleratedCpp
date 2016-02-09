//This file contains functions for creating and using a grammar to create a sentence.

#include "grammar.h"
#include <fstream>
#include "split.h"

using std::vector;		using std::string;
using std::ifstream;	using std::getline;


Grammar read_grammar(string grammar_file){

	Grammar ret;

	ifstream fp;
	fp.open(grammar_file.c_str());
	string line;
	while(getline(fp, line)){
		
		Rule splitted = split(line);
		if (!splitted.empty())
			ret[splitted[0]].push_back(
					Rule(splitted.begin()+1, splitted.end()) );
	}

	return ret;
}


