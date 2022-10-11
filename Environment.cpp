#/*
	Filename: Environment.cpp
	Description: Contains functions to print and update the environment
	that the entities will exist in
*/

//includes
#include "Environment.h"

//defines

Environment::Environment() {
	std::cout << "Testing" << std::endl;
}


/*
	Generate initial grid and set all values to 0. Then, print all values.
*/
void Environment::InitEnvironment() {
	for (int i = 0; i < GRID_WIDTH; ++i) {
		for (int j = 0; j < GRID_WIDTH; ++j) {
			environmentGrid[i][j] = 0;
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
}