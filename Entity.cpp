/*
	Filename: Entity.cpp
	Description: Contains functions to track information about entities
	that will populate the grid environment.
*/

//includes
#include "Entity.h"

//defines

Entity::Entity(const int posX, const int posY, Environment environment) : entityPositionX{ posX }, entityPositionY{ posY }, environment{ environment } {
	
	try {
		if (IsValidPosition(posX, posY) == false) {
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
bool Entity::IsValidPosition(int posX, int posY) {
	if (posX < 0 || posX >= this->environment.GRID_WIDTH) {
		std::cout << "X position error" << std::endl;
		return false;
	}
	if (posY < 0 || posY >= this->environment.GRID_HEIGHT) {
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
	Allows the entity to move a single space in a single direction, given the movement is valid
	If it successfully moves, it returns 1. Otherwise, if it was unable to move, it returns 0.

	Parameters:
		-positionChange: either 'x' or 'y', depending on if the width or height poistion is
		changing
		-direction: either 1 or -1, indicating a positve or negative direction. Note, upwards
		is considered negative y, while downwards is positive y
*/

int Entity::EntityNormalMovement(const char positionChange, const int direction) {
	int x = GetEntityXPosition();
	int y = GetEntityYPosition();

	if (positionChange == 'x') {
		x = x + direction;
		if (IsValidPosition(x, y) == false) {
			std::cout << "That is not a valid movement" << std::endl;
			return 0;
		}

		else {
			entityPositionX = x;
		}
	}

	if (positionChange == 'y') {
		y = y + direction;
		if (IsValidPosition(x, y) == false) {
			std::cout << "That is not a valid movement" << std::endl;
			return 0;
		}

		else {
			entityPositionY = y;
		}
	}
}
