/*
	Filename: Entity.cpp
	Description: Contains functions to track information about entities
	that will populate the grid environment.
*/

//includes
#include "Entity.h"

//defines

Entity::Entity(int posX, int posY) {
	std::cout << "Entity Created";
}

/*
	Allows the entity to move in a single direction (up/down = X, left/right = Y)
	by a specified amount. Notably, downards is positive X, while upwards is negative X. 

	Parameters:
		-postionChange: either 'x' or 'y' to represent which positional value is being 
		changed
		-amount: the amount the prior value is being changed by (can be positive or 
		negative
*/
void Entity::UpdateEntityPosition(char positionChange, int amount) {
	if (positionChange == 'x') {
		entityPosition[0] += amount;
	}
	else if (positionChange == 'y') {
		entityPosition[1] += amount;
	}
	
	//TODO: make the final else throw an exception instead of stating an error
	else {
		std::cout << "An improper position type has been provided";
	}
}
