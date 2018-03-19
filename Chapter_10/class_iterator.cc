#include <string>
#include "class_iterator.h"

using namespace std;

class_iterator::class_iterator(std::string new_item){
		item_ = new_item;
}

std::string& class_iterator::operator*(){
		return item_;
}

class_iterator& class_iterator::operator++(){
		if (next_element_ != NULL){
				item_ = **next_element_;

				next_element_ = next_element_->get_next_element();
				prev_element_ = this;
		}

		return *this;
}



std::string operator + (class_iterator first, class_iterator second){
		return *first + *second;
}

class_iterator& class_iterator::operator--(){
		if (prev_element_ != NULL){
				item_ = **prev_element_;

				next_element_ = this;
				prev_element_ = prev_element_->get_prev_element();
		}
		return *this;
}

bool operator!=(class_iterator first, class_iterator second){
		return (*first != *second && first.get_prev_element() != second.get_prev_element() && first.get_next_element() != second.get_next_element());
}

