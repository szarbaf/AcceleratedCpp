//This file contains functions for creating and using a grammar to create a sentence.

#include "grammar.h"
#include <fstream>
#include "split.h"
#include <cstdlib>
#include <cmath>
#include <algorithm>

using std::vector;		using std::string;
using std::ifstream;	using std::getline;
using std::rand;		using std::floor;
using std::copy;		using std::back_inserter;

Grammar read_grammar(string grammar_file){

	Grammar ret;

	ifstream fp;
	fp.open(grammar_file.c_str());
	if (fp.fail() || fp.bad())
		throw "Failed to open the file : " + grammar_file + "\n";
	string line;
	while(getline(fp, line)){		
		Rule splitted = split(line);
		if (!splitted.empty())
			ret[splitted[0]].push_back(
					Rule(splitted.begin()+1, splitted.end()) );
	}
	
	fp.close();
	return ret;
}

Rule gen_sentence(Grammar gram){

	Rule ret;
	ret = gen_aux(gram, "<sentence>");
	return ret;
}

Rule gen_aux(const Grammar &gram, string category){

	//Retrieving the rules for the category.
	Grammar::const_iterator rule_col_iter = gram.find(category);
	if (rule_col_iter == gram.end())
		throw "Empty rule.";
	//Choosing one of the rules randomly.
	const Rule_collection &rule_col = rule_col_iter->second;
	int rand_num = randn_gen(rule_col.size());
	Rule chosen_rule = rule_col[rand_num];
	//Expanding the rule.
	Rule ret;

	for (iter_Rule iter = chosen_rule.begin(); iter != chosen_rule.end(); iter++){
		if (!bracketed(*iter))
			ret.push_back(*iter);
		else{
			Rule tmp_sentence = gen_aux(gram, *iter);
			copy(tmp_sentence.begin(), tmp_sentence.end(), back_inserter(ret));
		}
	}
	
	return ret;
		
}

int randn_gen(Rule_col_num range){
	
	//Calculating bucket size.
	double buck = ((double) RAND_MAX)/range;
	Rule_col_num ret;
	//Generating a random number using the library.
	//Mapping [i*buck (i+1)*buck) --> i .
	do
		ret = floor(rand()/buck);
	while (ret == range);
	
	return ret;

}


bool bracketed(string name){
	if (name[0] == '<' && name[name.size()-1] == '>')
		return true;
	else
		return false;
}
