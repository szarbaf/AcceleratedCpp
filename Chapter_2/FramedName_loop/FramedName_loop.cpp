//This program asks for the user's name and types a framed greeting using the name. The padding around the name is adjustable by PAD macro.
#include <iostream>
#include <string>

using std::cout;

#define PAD 3

int main()
{
	//Inputing the user's name and creating the greeting text.
	cout << "Please enter your name." << std::endl;
	std::string name;
	std::cin >> name;
	const std::string greeting = "Hello " + name + " !";
	const std::string::size_type greeting_length= greeting.size();
	
	//Calculating number of rows and columns using Padding and user's name length.
	const int total_rows = 2*(PAD + 1) + 1;
	const int total_columns = 2*(PAD + 1) + greeting_length;
	
	//Writing the padded greeting using a while loop.
	for(int cur_row=0; cur_row < total_rows; cur_row++)
	{
		//loop invariant: cur_row rows have been written so far.
		for (int cur_col=0; cur_col < total_columns; cur_col++)
		{
			//loop invariant: cur_col columns have been written so far.
			if (cur_row == PAD+1 && cur_col == PAD+1)
			{
				cout << greeting;
				cur_col += greeting_length;
			}
			if(cur_col == 0 || cur_col == total_columns-1 || cur_row == 0 || cur_row == total_rows-1)
				cout << "*";
			else 
			{
				int spaces_size;
				if (cur_row == PAD+1)
					spaces_size = PAD;
				else
					spaces_size = 2*PAD + greeting_length;
				std::string spaces(spaces_size, ' ');
				cout << spaces;
				cur_col += spaces_size-1;
			}

		}
		cout << std::endl;
	}

	return 0;
}
