/*
	Filename: Food.cpp
	Description: Handles processes involving the spawning and removing of food 
	from the grid environment.
*/

//includes
#include "Food.h"

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
void Food::AddFood(const int posX, const int posY) {
	environment.UpdateEnvironment(posX, posY, "F");
	environment.PrintEnvironment();
}

