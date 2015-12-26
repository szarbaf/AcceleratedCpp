//This program reads multiple words from stdin and counts the number of repetition for each word.

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

#define WORD_NOT_SEEN -1
typedef vector<string>::size_type st_vec_size;
int word_ind(vector<string> words, string tmp_word);


int main()
{
	//Welcoming message.
	cout << "Please enter a bunch of words, spaces delimited and end with a EOF singal." << endl;
	
	//Reading words.
	vector<string> words;
	vector<int> counts;
	string tmp_word;

	st_vec_size num_words;
	int tmp_ind;
	while(cin >> tmp_word)
	{
		if ( (tmp_ind = word_ind(words, tmp_word)) == WORD_NOT_SEEN ) 
		{
			//Word no seen before.
			words.push_back(tmp_word);
			counts.push_back(1);
		}
		else
			counts[tmp_ind] += 1;
	}
	
	//Outputting the words.
	num_words = words.size();
	if(num_words == 0)
	{
		cout << "No valid words entered, exiting." << endl;
		return -1;
	}
	cout << "The words and corresponding counts are as follows:" << endl;
	for (int counter=0; counter < num_words; counter++)
		cout << words[counter] << " : " << counts[counter] << "\t";
	cout << endl;
}

int word_ind(vector<string> words, string tmp_word)
{
	for (int counter=0; counter < words.size(); counter++)
		if (words[counter] == tmp_word)
			return counter;

	return WORD_NOT_SEEN;
}
