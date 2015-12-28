//This program writes either a square, rectangle or a triangle where the use specifies the dimensions.
#include <iostream>
#include <string>

using std::cout;

enum ShapeID
{
	SQUARE,
	RECTANGLE,
	TRIANGLE
};

int main()
{
	//Asking the user what shape to draw.
	cout << "What shape do you want me to draw?" << std::endl;
	cout << "Square : " << SQUARE << " " << ", Rectangle : " << RECTANGLE << ", Triangle : " << TRIANGLE << std::endl;
	int id;
	std::cin >> id;

	//Asking for the dimensions.
	int height, width;
	switch(id)
	{
		case SQUARE:
			cout << "Please Enter the Square side length." << std::endl;
			std::cin >> width;
			break;
		case RECTANGLE:
			cout << "Please enter the rectangle width." << std::endl;
			std::cin >> width;
			cout << "Please enter the rectangle height." << std::endl;
			std::cin >> height;
			if (height <= 0)
			{
				cout << "Height should be positive, exiting.";
				return -1;
			}
			break;
		case TRIANGLE:
			cout << "Please enter the triangle width.(The triangle width should be an odd integer.)" << std::endl;
			std::cin >> width;
			if (width % 2 != 1)
			{
				cout << "Width is not an odd integer, exiting." << std::endl;
				return -1;
			}
			break;
	}
	if (width < 0)
	{
		cout << "Width should be positive, exiting." << std::endl;
		return -1;
	}

	//Drawing the shape.
	switch(id)
	{
		case SQUARE:
			{
				std::string stars(width, '*');
				for(int height_counter = 0; height_counter < width; height_counter++)
					//loop_invariant : height_counter rows have been printed.
					cout << stars << std::endl;
				break;
			}
		case RECTANGLE:
			{

				std::string stars(width, '*');
				for(int height_counter = 0; height_counter < height; height_counter++)
					//loop_invariant : height_counter rows have been printed.
					cout << stars << std::endl;
				break;
			}
		case TRIANGLE:
			{

				int numHalfSpaces = (width-1)/2;

				for(int numStars = 1; numStars != width+2; numStars += 2, numHalfSpaces -= 1)
				{
					//loop_invariant : (numStars-1)/2 rows have been printed.
					std::string stars(numStars, '*');
					if (numStars != width)	
					{
						std::string halfSpaces(numHalfSpaces, ' ');
						cout << halfSpaces << stars << halfSpaces << std::endl;
					}
					else
						cout << stars << std::endl;

				}

				break;
			}
	}

	return 0;
}
