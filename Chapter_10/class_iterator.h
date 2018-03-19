#ifndef _CLASS_ITERATOR_
#define _CLASS_ITERATOR_

#include <string>



class class_iterator{

	public:
		class_iterator(std::string);
		class_iterator& operator ++();
		class_iterator& operator --();
		std::string& operator *();
		

		void push_back(std::string);
		class_iterator* get_next_element() {return next_element_;}
		class_iterator* get_prev_element() {return prev_element_;}

		void assign_next_element_(class_iterator* next) {next_element_ = next;}
		void assign_prev_element_(class_iterator* prev) {prev_element_ = prev;}



	
	private:
		std::string item_;
		class_iterator *prev_element_, *next_element_;
};

bool operator!=(class_iterator first, class_iterator second);

#endif
