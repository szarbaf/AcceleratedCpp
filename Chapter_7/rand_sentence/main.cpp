//This program generates random sentences according to a grammmar file.
#include <iostream>
#include <map>
#include <vector>
#include "grammar.h"

using std::cout;		using std::map;
using std::vector;		using std::endl;

#define NUM_SENTENCES 5

int main(){

	//Reading the grammar.
	Grammar gram = read_grammar("grammar.txt");

	//Generating random sentences.
	Rule_collection sentences;
	Rule tmp;
	for (int i=0; i < NUM_SENTENCES; i++){
		gen_sentence(gram, tmp);
		sentences.push_back(tmp);
	}

	//Outputting the sentences.
	cout << "The generated sentences are as follows:" << endl;
	for (iter_Rule_col iter_col = sentences.begin(); iter_col != sentences.end(); iter_col++){
		iter_Rule iter_rule = iter_col->begin();
		cout << iter_rule[0];
		iter_rule++;
		for (; iter_rule != iter_col->end(); iter_rule++)
			cout << " " << *iter_rule;
		cout << endl;
	}

	return 0;
}
