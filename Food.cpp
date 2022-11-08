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
#include <chrono>
#include <thread>

Food::Food(Environment* environmentO) : environment{ environmentO } {

}

Food::Food(Environment* environmentO, const int spawnRate) : environment{ environmentO }, foodSpawnRate{ spawnRate } {

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
	if (isdigit(environment->GetValue(posX, posY)[0])) {
		std::cout << "There is an entity here" << std::endl;
		return 0;
	}

	environment->UpdateEnvironment(posX, posY, "F");
	environment->PrintEnvironment();
	return 1;
}

int Food::RandomFoodSpawn(std::mt19937 &generator) {

	int gridSize = environment->GetGridDimensions().GRID_WIDTH * environment->GetGridDimensions().GRID_WIDTH;

	//set up psuedo-random generator. Use the following at the start of each thread to init with different seed
	//std::random_device rd; 
	//std::mt19937 generator(rd());
	std::uniform_int_distribution<> distribution(0, (gridSize - 1));


	int randLocation = distribution(generator);
	
	int xDim = randLocation % environment->GetGridDimensions().GRID_WIDTH;
	int yDim = floor(randLocation / environment->GetGridDimensions().GRID_WIDTH);


	int successIndicator = AddFood(xDim, yDim);

	return successIndicator;
}

/*
	Sets the foodSpawnRate for the food class object.

	Parameters:
		-spawnRate: the rate at which food will spawn into the grid environment

	
*/
void Food::SetSpawnRate(int spawnRate) {
	foodSpawnRate = spawnRate;
}

/*
	Get the spawn rate of a Food object.
*/
int Food::GetSpawnRate() {
	return foodSpawnRate;
}