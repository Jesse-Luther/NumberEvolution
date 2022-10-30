/*
	Filename: Food.cpp
	Description: Handles processes involving the spawning and removing of food 
	from the grid environment.
*/

//includes
#include "Food.h"

Food::Food(Environment& environmentO) : environment{ environmentO } {

}

void Food::AddFood(const int posX, const int posY) {
	environment.UpdateEnvironment(posX, posY, "F");
	environment.PrintEnvironment();
}

