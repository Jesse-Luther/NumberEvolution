/*
	Filename: Environment.cpp
	Description: Contains functions to print and update the environment
	that the entities will exist in
*/

//includes
#include "Environment.h"

//defines

Environment::Environment() {
	std::cout << "Test" << std::endl;
}


/*
	Generate initial grid and set all values to 0. Then, print all values.
*/
void Environment::InitEnvironment() {
	for (int i = 0; i < GRID_WIDTH; ++i) {
		for (int j = 0; j < GRID_WIDTH; ++j) {
			environmentGrid[i][j] = "0";
		}
	}
	Environment::PrintEnvironment();
}


/*
	Print each value of the grid environment in proper format.
*/
void Environment::PrintEnvironment() {
	for (int i = 0; i < GRID_WIDTH; ++i) {

		std::cout << std::endl;

		for (int j = 0; j < GRID_WIDTH; ++j) {
			std::cout << environmentGrid[i][j] << " ";
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
*/
void Environment::UpdateEnivronment(const int posX, const int posY, const std::string updateValue) {
	environmentGrid[posX][posY] = updateValue;

	Environment::PrintEnvironment();
}
