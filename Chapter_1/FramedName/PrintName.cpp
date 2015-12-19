#include <iostream>
#include <string>

int main()
{
	std::string name;

	std::cout << "Please enter your name" << std::endl;
	std::cin >> name;

	//Generating output strings.
	std::string greeting = "Hello " + name + " !";

	const std::string spaces(greeting.size(), ' ');

	const std::string fourth = "* " + spaces + " *";

	greeting = "* " + greeting + " *";

	const std::string stars(fourth.size(), '*');

	//Printing the lines one by one.
	
	std::cout << std::endl;
	std::cout << stars << std::endl;
	std::cout << fourth << std::endl;
	std::cout << greeting << std::endl;
	std::cout << fourth << std::endl;
	std::cout << stars << std::endl;

	return 0;
}
