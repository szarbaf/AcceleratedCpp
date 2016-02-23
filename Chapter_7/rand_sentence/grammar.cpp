//This file contains functions for creating and using a grammar to create a sentence.

#include "grammar.h"
#include <fstream>
#include "split.h"
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>

using std::list;		using std::string;
using std::ifstream;	using std::getline;
using std::rand;		using std::floor;
using std::copy;		using std::back_inserter;
using std::stack;

Grammar read_grammar(string grammar_file){

	Grammar ret;

	ifstream fp;
	fp.open(grammar_file.c_str());
	if (fp.fail() || fp.bad())
		throw "Failed to open the file : " + grammar_file + "\n";
	string line;
	while(getline(fp, line)){		
		Rule splitted = split(line);
		Rule::iterator first = splitted.begin();
		Rule::iterator second = first;
		second++;
		if (!splitted.empty())
			ret[*first].push_back(
					Rule(second, splitted.end()) );
	}
	
	fp.close();
	return ret;
}

Rule gen_sentence(Grammar gram){

	Rule ret;
	ret = gen_aux_nonRecursive(gram, "<sentence>");
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
	iter_Rule_col chosen_rule_iter = rule_col.begin();
	for (int i = 0; i < rand_num; i++)
		chosen_rule_iter++;
	Rule chosen_rule = *chosen_rule_iter;
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

Rule gen_aux_nonRecursive(const Grammar &gram, string category){

	Rule chosen_rule = grab_rule(gram, category) ;
		
	//Generating the output. Using stacks for the rule and output.
	//Initializing the rule stack.
	stack<string> rule_stack;
	for (Rule::const_iterator iter = chosen_rule.begin(); iter != chosen_rule.end(); iter++)
		rule_stack.push(*iter);
	
	stack<string> ret_stack;
	while (!rule_stack.empty()){
		const string &item = rule_stack.top();
		rule_stack.pop();
		if (bracketed(item)){
			Rule rule = grab_rule(gram, item);
			for (iter_Rule iter = rule.begin(); iter != rule.end(); iter++)
				rule_stack.push(*iter);
		}
		else
			ret_stack.push(item);
	}
	
	//Outputting and reversing the generated sentence.
	Rule ret;
	while (!ret_stack.empty()){
		ret.push_back(ret_stack.top());
		ret_stack.pop();
	}


	return ret;
}

Rule grab_rule(Grammar gram, string category){
	
	//Retrieving the corresponding rule collection.
	Grammar::const_iterator rules = gram.find(category);
	if (rules == gram.end())
		throw "Empty category.\n";
	//Choosing a random rule out of the collection.
	const Rule_collection &tmp = rules->second;
	int rand_num = randn_gen(tmp.size());

	iter_Rule_col chosen_rule_iter = tmp.begin();
	for (int counter = 0; counter < rand_num; counter++)
		chosen_rule_iter++;
	
	return *chosen_rule_iter;
}
