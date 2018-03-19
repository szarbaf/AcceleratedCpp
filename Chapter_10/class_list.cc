#include <string>
#include "class_list.h"
#include "class_iterator.h"

using namespace std;

class_list::class_list(){
	num_elements_ = 0;
	first_element_ = NULL;
}

void class_list::push_back(string new_element){
	
	class_iterator *new_iter = new class_iterator(new_element);


	new_iter->assign_next_element_(first_element_);
	if (num_elements_ != 0)
		first_element_->assign_prev_element_(new_iter);

	first_element_ = new_iter;

	num_elements_++;	
}

string class_list::pop(){

		if (num_elements_ == 0)
				return string();

		class_iterator copy = *first_element_;
		delete first_element_;
		num_elements_--;

		first_element_ = copy.get_next_element();
		return *copy;

}
