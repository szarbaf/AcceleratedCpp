//This program tries to imitate the partition function from standard library.
#include <iostream>
#include <algorithm>
#include <time.h>
#include <vector>

using namespace std;

#define MAX_NUM 10
typedef vector<double>::const_iterator const_iter;
typedef vector<double>::iterator iter;


void my_partition(iter, iter, bool (*)(double) );
bool pred(double);

int main(){
	
	//Generating random data.
	srand(time(NULL));
	double orig[MAX_NUM];
	vector<double> my_alg, lib_alg;
	for (int i = 0; i < MAX_NUM; i++){
		orig[i] = (rand()*1.0)/RAND_MAX;
		my_alg.push_back(orig[i]);
		lib_alg.push_back(orig[i]);
	}

	//Partitioning using my own function.
	my_partition(my_alg.begin(), my_alg.end(), pred);
	//Partitioning using library function.
	stable_partition(lib_alg.begin(), lib_alg.end(), pred);
	
	//Showing the results.
	cout << "The results are as follows: Original/my_partition/lib_partition" << endl;
	for(int i=0; i < MAX_NUM; i++)
		cout << orig[i] << "/" << my_alg[i] << "/" << lib_alg[i] << endl;

	return 0;

}

bool pred(double num){
	return num < 0.5;
}

void my_partition(iter b, iter e, bool (*pred)(double) ){
	
	iter f, t;
	
	for (t = b; t != e; t++){

		//Finding a false member.
		while(t != e && pred(*t))
			t++;

		f = t;
		//Finding a true member to replace.
		while(f != e && !pred(*f))
			f++;
		if (f == e)
			break;
		//swaping the two values.
		else
			iter_swap(t, f);
	}
}
