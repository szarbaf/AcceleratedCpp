#include <iostream>
#include <vector>
#include <map>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection > Grammar;

typedef Rule::const_iterator iter_Rule;
typedef Rule_collection::const_iterator iter_Rule_col;
