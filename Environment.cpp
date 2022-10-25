/*
	Filename: Environment.cpp
	Description: Contains functions to print and update the environment
	that the entities will exist in
*/

//includes
#include "Environment.h"
#include<assert.h>


//defines

Environment::Environment(const int width, const int height) : gridDimensions{width, height} {
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
	int totalGridSize = this->GetGridDimensions().GRID_WIDTH * this->GetGridDimensions().GRID_HEIGHT;

	for(int i = 0; i < totalGridSize; ++i){
		environmentGrid.push_back("0");
	}

	Environment::PrintEnvironment();
}


/*
	Print each value of the grid environment in proper format.
*/
void Environment::PrintEnvironment() {
	int totalGridSize = this->GetGridDimensions().GRID_WIDTH * this->GetGridDimensions().GRID_HEIGHT;

	for (int i = 0, j = 0; i < totalGridSize; ++i, ++j) {
		if (j == 0) {
			std::cout << std::endl;
		}
		
		std::cout << environmentGrid[i] << " ";

		if (j >= (GetGridDimensions().GRID_WIDTH - 1)) {
			j = -1;
		}
		
		
	}

	std::cout << std::endl;
	std::cout << "***************************************************************************************" << std::endl;
}
/*
	Determine if a given position exists on the current environment grid

		Parameters:
		-posX: the index position along the width being accessed (from 0 to (WIDTH - 1))
		-posY: the index position along the height being accessed (from 0 to (HEIGHT - 1))
*/
bool Environment::IsValidPosition(int posX, int posY) {
	if (posX < 0 || posX >= this->GetGridDimensions().GRID_WIDTH) {
		std::cout << "X position error" << std::endl;
		return false;
	}
	if (posY < 0 || posY >= this->GetGridDimensions().GRID_HEIGHT) {
		std::cout << "Y position error" << std::endl;
		return false;
	}

	return true;
}

/*
	Update the value at a position on the grid with the given value, and then print the grid using PrintEnvironment()

	Parameters:
		-posX: the index position along the width being accessed (from 0 to (WIDTH - 1))
		-posY: the index position along the height being accessed (from 0 to (HEIGHT - 1))
		-updateValue: the value for the specified location to be updated to
*/
void Environment::UpdateEnivronment(const int posX, const int posY, const std::string updateValue) {
	//ensure idex value isn't greater than the length/height of the grid
	assert(IsValidPosition(posX, posY) == true);
	
	
	int updateLocation = (posY * this->GetGridDimensions().GRID_WIDTH) + posX;
	
	environmentGrid[updateLocation] = updateValue;

	Environment::PrintEnvironment();
}

GridDimensions Environment::GetGridDimensions() {
	return gridDimensions;
}

/*
	Retrieve the value at a valid location on the grid.

	Parameters:
		-posX: the index position along the width being accessed (from 0 to (WIDTH - 1))
		-posY: the index position along the height being accessed (from 0 to (HEIGHT - 1))
*/
std::string Environment::GetValue(int posX, int posY) {
	assert(IsValidPosition(posX, posY) == true);
	
	int valueLocation = (posY * this->GetGridDimensions().GRID_WIDTH) + posX;

	return environmentGrid[valueLocation];
}