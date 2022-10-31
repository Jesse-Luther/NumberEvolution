/*
	Filename: Food.cpp
	Description: Handles processes involving the spawning and removing of food 
	from the grid environment.
*/

//includes
#include "Food.h"
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <random>

Food::Food(Environment& environmentO) : environment{ environmentO } {

}

/*
	Calls upon the Environment::UpdateEnvironment function to change
	a value at the specified coordinates to the string "F", which represents 
	food. 

	Parameters:
		-posX: X position on the grid environment (in other words, row number)
		-posY: Y position on the grid environment (in other words, column number)
*/
int Food::AddFood(const int posX, const int posY) {
	if (isdigit(environment.GetValue(posX, posY)[0])) {
		return 0;
	}

	environment.UpdateEnvironment(posX, posY, "F");
	environment.PrintEnvironment();
	return 1;
}

int Food::RandomFoodSpawn(std::mt19937& generator) {

	int gridSize = environment.GetGridDimensions().GRID_WIDTH * environment.GetGridDimensions().GRID_WIDTH;

	//set up psuedo-random generator. Use the following at the start of each thread to init with different seed
	//std::random_device rd; 
	//std::mt19937 generator(rd());
	std::uniform_int_distribution<> distribution(0, (gridSize - 1));


	int randLocation = distribution(generator);
	
	int xDim = randLocation % environment.GetGridDimensions().GRID_WIDTH;
	int yDim = floor(randLocation / environment.GetGridDimensions().GRID_WIDTH);


	int successIndicator = AddFood(xDim, yDim);

	return successIndicator;
}


