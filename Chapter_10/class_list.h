#include <iostream>
#include <string>

class class_list{
	public:

		class iterator;
		class reverse_iterator;
		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
		
		class_list();
		void push_back(std::string);
		int size();


	private:
		int num_elements;
		iterator *first_element, *last_element;

};

/////////// CLASS_LIST::ITERATOR ///////////

class class_list::iterator{

	public:
		iterator(std::string);
		void operator ++();
		void operator --();
		std::string operator *();

	friend std::string operator + (iterator, iterator);
	friend void class_list::push_back(std::string);

	
	private:
		std::string item;
		iterator *prev_element, *next_element;
};

class_list::iterator::iterator(std::string new_item){
	item = new_item;
}

void class_list::iterator::operator++(){
	if (next_element != NULL)
		item = next_element->item;

	next_element++;
	prev_element++;
}

std::string class_list::iterator::operator*(){
	return item;
}

std::string operator + (class_list::iterator first, class_list::iterator second){
	return *first + *second;
}

void class_list::iterator::operator--(){
	if (prev_element != NULL)
		item = prev_element->item;

	next_element--;
	prev_element--;
}

/////////// CLASS_LIST::ITERATOR ///////////

class_list::class_list(){
	num_elements = 0;
	first_element = last_element = NULL;
}

void class_list::push_back(std::string new_element){
	
	iterator *new_iter = new class_list::iterator(new_element);

	new_iter->next_element = first_element;
	first_element->prev_element = new_iter;

	if (num_elements == 0)
		first_element = last_element = new_iter;
	
}

int class_list::size(){
	return num_elements;
}
