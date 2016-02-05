//This code extracts from a string of characters valid urls and push them into an array.
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

using std::cout;		using std::cin;
using std::endl;		using std::string;
using std::vector;		using std::find_if;
using std::search;		using std::isalnum;
using std::isalpha;		using std::find;

typedef vector<string>::iterator vector_iter;
typedef string::const_iterator string_iter;

vector<string> extract_url(const string &input);
string_iter url_beg(string_iter b, string_iter e);
string_iter url_end(string_iter b, string_iter e);
bool not_url_char(char c);

int main(){

	string sample_input("http://shapal.com ghoombol https://www.mapal.com boro baba!");

	//Extracting urls
	vector<string> extracted_urls = extract_url(sample_input);
	//Outputing the results.
	cout << "The original string was : " << sample_input << endl 
		 << "The extracted urls are : " << endl;
	for (vector_iter tmp = extracted_urls.begin(); tmp != extracted_urls.end(); tmp++)
		cout << *tmp << endl;

	return 0;
}

vector<string> extract_url(const string &input){
	
	vector<string> extracted_urls;
	string::const_iterator b = input.begin(), e = input.end();

	while(b != e){
	
		//Finding the start of the url.
		b = url_beg(b, e);
		//Finding the end of the url.
		if (b != e){
			string_iter after = url_end(b, e);
			//Inserting the url.
			if(after != e)
				extracted_urls.push_back(string(b, after));
			b = after;
		}

	}
	
	return extracted_urls;
}

string_iter url_beg(string_iter b, string_iter e){

	const static string sep = "://";
	string_iter i, beg = e;

	if ( (i = search(b, e, sep.begin(), sep.end())) != e){
		
		//Checking whether the separation string is at the beginning or end.
		if (i != b && i+sep.size() != e){
			
			//Finding the beginning of the url.
			beg = i;
			while(beg != b && isalpha(beg[-1]))
				beg--;
			
			//Checking whether there is at leat one char after the sep string.
			if (beg == i || not_url_char(i[sep.size()]) )
				beg = e;
		}

	}

	return beg;

}

string_iter url_end(string_iter b, string_iter e){

	return find_if(b, e, not_url_char);
}

bool not_url_char(char c){
	
	const static string special_url_chars = "~;/?:@=&$-_.+!*'(),";
	return !( isalnum(c) || 
			find(special_url_chars.begin(), special_url_chars.end(), c)!=special_url_chars.end() );
}
