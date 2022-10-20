/*
	Filename: Entity.cpp
	Description: Contains functions to track information about entities
	that will populate the grid environment.
*/

//includes
#include "Entity.h"

//defines

Entity::Entity(const int posX, const int posY, Environment environment) : entityPositionX{ posX }, entityPositionY{ posY } {
	
	try {
		if (IsValidPosition(posX, posY, environment) == false) {
			throw posX;
		}

	}


	catch (const int pos) {
		std::cout << "Error: Positional value outside of the range 0 <= pos <= Width/Height was used." << std::endl;
	}

	std::cout << "Entity Created";\

}

/*

*/
bool Entity::IsValidPosition(int posX, int posY, Environment environment) {
	if (posX < 0 || posX >= environment.GRID_WIDTH) {
		std::cout << "X position error" << std::endl;
		return false;
	}
	if (posY < 0 || posY >= environment.GRID_HEIGHT) {
		std::cout << "Y position error" << std::endl;
		return false;
	}

	return true;
}

int Entity::GetEntityXPosition() {
	return entityPositionX;
}

int Entity::GetEntityYPosition() {
	return entityPositionY;
}

/*
	Sets the entity's position to the specified coordinates. 

	Parameters:
		-posX: X position on the grid environment (in other words, row number)
		-posY: Y position on the grid environment (in other words, column number)

void Entity::SetEntityPosition(const int posX, const int posY) {
	entityPosition[0] = posX;
	entityPosition[1] = posY;
}
*/


/*
	Allows the entity to move in a single direction (up/down = X, left/right = Y)
	by a specified amount. Notably, downards is positive X, while upwards is negative X. 

	Parameters:
		-postionChange: either 'x' or 'y' to represent which positional value is being 
		changed
		-amount: the amount the prior value is being changed by (can be positive or 
		negative
*/

//void Entity::EntityNormalMovement(const char positionChange) {
	
//}
