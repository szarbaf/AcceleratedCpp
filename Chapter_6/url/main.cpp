//This code extracts from a string of characters valid urls and push them into an array.
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::cout;		using std::cin;
using std::endl;		using std::string;
using std::vector;		using std::find_if;
using std::search;

typedef vector<string>::iterator iter;

int main(){

	string sample_input("http://shapal.com ghoombol https://www.mapal.com boro baba!");

	//Extracting urls
	vector<string> extracted_urls = extract_url(sample_input);
	//Outputing the results.
	cout << "The original string was : " << sample_input << endl 
		 << "The extracted urls are : " << endl;
	for (iter tmp = extracted_urls.begin(); tmp != extracted_urls.end(); tmp++)
		cout << *tmp << endl;

	return 0;
}

vector<string> extract_url(const string &input){
	
	vector<string> extracted_urls;
	iter b = input.begin(), e = input.end();

	while(b != e){
	
		//Finding the start of the url.
		b = url_beg(b, e);
		//Finding the end of the url.
		if (b != e){
			iter after = url_end(b, e);
			//Inserting the url.
			if(after != e)
				extracted_urls.push_back(string(b, after));
			b = after;
		}

	}
	
	return extracted_urls;
}

iter url_beg(iter b, iter e){

	const string sep = "://";
	iter i, beg = e;

	if ( (i = search(b, e, sep.begin(), sep.end())) != e){
		
		//Checking whether the separation string is at the beginning or end.
		if (i != b && i+sep.size() != e){
			
		}

	}

}
