/*
	Filename: Entity.cpp
	Description: Contains functions to track information about entities
	that will populate the grid environment.
*/

//includes
#include "Entity.h"

//defines

Entity::Entity(const int posX, const int posY) : entityPosition{ posX, posY } {
	
	try {
		if (posX < 0 || posX > 9) {
			throw posX;
		}

		if (posY < 0 || posY > 9) {
			throw posY;
		}
	}

	catch (const int pos) {
		std::cout << "Error: Positional value outside of the range 0 <= pos <= 9 was used." << std::endl;
		std::cout << "Value that caused error is " << pos << std::endl;

	}

	std::cout << "Entity Created";
}


/*
	Sets the entity's position to the specified coordinates. Used when instantiating 
	an entity object to set its initial position, and will possible be used in other 
	instances

	Parameters:
		-posX: X position on the grid environment (in other words, row number)
		-posY: Y position on the grid environment (in other words, column number)
*/
void Entity::SetEntityPosition(const int posX, const int posY) {
	entityPosition[0] = posX;
	entityPosition[1] = posY;
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
void Entity::UpdateEntityPosition(const char positionChange, const int amount) {
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

