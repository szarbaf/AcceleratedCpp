#include <iostream>
#include <vector>
#include <map>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection > Grammar;

typedef Rule::const_iterator iter_Rule;
typedef Rule_collection::const_iterator iter_Rule_col;
typedef Rule_collection::size_type Rule_col_num;

Grammar read_grammar(std::string grammar_file);
Rule gen_sentence(Grammar gram);
Rule gen_aux(const Grammar &gram, std::string category);
int randn_gen(Rule_col_num range);
bool bracketed(std::string name);
