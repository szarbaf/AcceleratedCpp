//This program reads multiple words from stdin and determines the length of the shortest and longest names.

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;


int main()
{
	//Welcoming message.
	cout << "Please enter a bunch of words, spaces delimited and end with a EOF singal." << endl;
	
	//Reading words.
	string max_word, min_word, tmp_word;
	string::size_type max = 0, min = max_word.max_size(), tmp_size;

	bool checker = false;
	while(cin >> tmp_word)
	{
		tmp_size = tmp_word.size();
		if ( tmp_size > max ) 
		{
			max = tmp_size;
			max_word = tmp_word;
		}
		else if ( tmp_size < min)
		{
			min = tmp_size;
			min_word = tmp_word;
		}
		checker = true;
	}

	if(checker == false)
	{
		cout << "No valid words entered, exiting." << endl;
		return -1;
	}	

	//If only one word is read.
	if (max == 0)
		max = min;
	else if (min == min_word.max_size() && max != min_word.max_size())
		min = max;
		

	//Outputing the longest and shortest words.
	cout << "Longest and shortest words are as follows:" << endl;
	cout << "Max word : " << max_word << " = " << max << endl;
	cout << "Min word : " << min_word << " = " << min << endl;
	
	return 0;
}


