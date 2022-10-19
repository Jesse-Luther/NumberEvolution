/*
	Filename: Environment.cpp
	Description: Contains functions to print and update the environment
	that the entities will exist in
*/

//includes
#include "Environment.h"

//defines

Environment::Environment(const int width, const int height) :  {
	try {
		if (width <= 0) {
			throw width;
		}

		if (height <= 0) {
			throw height;
		}
	}

	catch (const int size) {
		std::cout << "ERROR: size value less than 1 used. The invalid size used was " << size << "." << std::endl;
	}
}


/*
	Generate initial grid and set all values to 0. Then, print all values.
*/
void Environment::InitEnvironment() {
	int totalGridSize = this->GRID_WIDTH * this->GRID_HEIGHT;

	for(int i = 0; i < totalGridSize; ++i){
		environmentGrid.push_back("0");
	}

	Environment::PrintEnvironment();
}


/*
	Print each value of the grid environment in proper format.
*/
void Environment::PrintEnvironment() {
	int totalGridSize = this->GRID_WIDTH * this->GRID_HEIGHT;

	for (int i = 0, j = 0; i < totalGridSize; ++i, ++j) {
		if (j == 0) {
			std::cout << std::endl;
		}
		
		std::cout << environmentGrid[i];

		if (j >= GRID_WIDTH) {
			j = -1;
		}
		
		
	}

	std::cout << std::endl;
	std::cout << "***************************************************************************************" << std::endl;
}

/*
	Update the value at a position on the grid with the given value, and then print the grid using PrintEnvironment()

	Parameters:
		-posX: the row being accessed (from 0 to (#rows - 1))
		-posY: the column being accessed (from 0 to (#col - 1))
		-updateValue: the value for the specified location to be updated to

void Environment::UpdateEnivronment(const int posX, const int posY, const std::string updateValue) {
	environmentGrid[posX][posY] = updateValue;

	Environment::PrintEnvironment();
}
*/