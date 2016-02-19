//This program generates random sentences according to a grammmar file.
#include <iostream>
#include <map>
#include <vector>
#include "grammar.h"
#include <cstdlib>
#include <ctime> 

using std::cout;		using std::map;
using std::vector;		using std::endl;
using std::string;		using std::srand;
using std::time;		using std::cin;

int main(){

	//Reading the grammar.
	Grammar gram;
	try{
		gram = read_grammar("grammar.txt");
	}
	catch (string error){
		cout << error << endl;
		return -1;
	}

	//Generating random sentences.
	Rule_collection sentences;
	Rule tmp;
	srand(time(NULL));
	cout << "Please enter the number of sentences you would like to be generated." << endl;
	int num_sentences;
	cin >> num_sentences;
	for (int i=0; i < num_sentences; i++){
		tmp = gen_sentence(gram);
		sentences.push_back(tmp);
	}

	//Outputting the sentences.
	cout << "The generated sentences are as follows:" << endl;
	for (iter_Rule_col iter_col = sentences.begin(); iter_col != sentences.end(); iter_col++){
		iter_Rule iter_rule = iter_col->begin();
		cout << *iter_rule->begin();
		iter_rule++;
		for (; iter_rule != iter_col->end(); iter_rule++)
			cout << " " << *iter_rule;
		cout << "." << endl;
	}

	return 0;
}
