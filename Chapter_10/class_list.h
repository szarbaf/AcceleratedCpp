#ifndef _CLASS_LIST_
#define _CLASS_LIST_

#include <iostream>
#include <string>

#include "class_iterator.h"


class class_list{
	public:

		class_iterator& begin() {return *first_element_;}
		class_iterator& end() {return *(first_element_+num_elements_+1);}
		//reverse_iterator rbegin();
		//reverse_iterator rend();
		
		class_list();
		void push_back(std::string);
		std::string pop();
		size_t size() {return num_elements_;}


	private:
		int num_elements_;
		class_iterator *first_element_;

};
#endif



