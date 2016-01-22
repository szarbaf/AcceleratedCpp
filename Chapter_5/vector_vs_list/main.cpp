//This program measures the performance of vector and list containers for random index deletion .
#include <iostream>
#include <list>
#include <vector>
#include "student_info.h"
#include <cstdlib>
#include <ctime>

#define NUM_INPUTS 25000

using std::cout;		using std::cin;
using std::vector;		using std::list;
using std::string;		using std::time;
using std::endl;

bool pgrade(double);

int main(){

	//Generating random student vector and lists.
	student_info_t good_student = {"Good", 100}, bad_student = {"Bad", 40};
	std::srand(time(NULL));
	vector<student_info_t> all_students;
	vector<student_info_t>::size_type good_counter = 0;
	for (int i = 0; i < NUM_INPUTS; i++){
		int random = 2*(rand()%2) - 1;
		if(random > 0){
			all_students.push_back(good_student);
			good_counter++;
		}
		else
			all_students.push_back(bad_student);
	}
	cout << good_counter << " good and " << NUM_INPUTS - good_counter << " bad students are generated." << endl;
	//Creating and testing a vector.
	vector<student_info_t> vector_students = all_students;
	vector<student_info_t>::iterator vec_iter = vector_students.begin();
	time_t vec_begin, vec_end;
	time(&vec_begin);
	while ( vec_iter != vector_students.end()){
		if ( pgrade(vec_iter->overall_grade) )
			vec_iter++;
		else{
			vec_iter = vector_students.erase(vec_iter);
		}
	}
	time(&vec_end);
	//Creating and testing a list.
	list<student_info_t> list_students;
	for (vec_iter = all_students.begin(); vec_iter != all_students.end(); vec_iter++)
		list_students.push_back(*vec_iter);
	list<student_info_t>::iterator list_iter = list_students.begin();
	time_t list_begin, list_end;
	time(&list_begin);
	while ( list_iter != list_students.end()){
		if ( pgrade(list_iter->overall_grade) )
			list_iter++;
		else{
			list_iter = list_students.erase(list_iter);
		}
	}
	time(&list_end);
	//Outputing the results.
	
	cout << "The time spent for each container manipulation for total of " << NUM_INPUTS << " data points are as follows" << endl;
	cout << "Vector container : " << std::difftime(vec_end, vec_begin) << " Seconds." << endl;
	cout << "List container : " << std::difftime(list_end, list_begin) << " Seconds." << endl;

	return 0;

}

bool pgrade(double grade){
	return grade > 60;
}


