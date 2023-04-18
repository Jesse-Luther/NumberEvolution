/*
	Filename: Entity.cpp
	Description: Contains functions to track information about entities
	that will populate the grid environment. Entity names MUST be integer
	values.
*/

//includes
#include "Entity.h"
#include <cstdlib>
#include <time.h>
#include <random>


/*
	Basic level constructor to create a dummy Entity that doesn't actually get spawned
	onto the grid environment. Used for the EventObject.h class.
*/
Entity::Entity(Environment* environmentO) : environment{ environmentO } {

}

Entity::Entity(const int posX, const int posY, Environment* environmentO, const std::string id, const int speedBase) : entityPositionX{ posX }, entityPositionY{ posY }, environment{ environmentO }, entityID{ id }, movementSpeed{speedBase, speedBase} {
	
	//set to false if an erreneous spawn occurs, to prevent the print attempt later on
	bool spawnErrorCheck = 1;

	try {
		if (IsValidPosition(posX, posY) == false) {
			throw posX;
		}

	}


	catch (const int pos) {
		std::cout << "Error: Positional value outside of the range 0 <= pos <= Width/Height was used, or the location was already occupied" << std::endl;
		spawnErrorCheck = 0;
	}

	std::cout << "Entity Created"; \
	
	if (spawnErrorCheck == 1) {
		environmentO->UpdateEnvironment(posX, posY, id);
		environmentO->PrintEnvironment();
	}

}

/*
	Checks if a location is a valid position for an entity to go to. A location is valid if 
	it is within the confines of the current grid, and is not already occupied by another entity. 
*/
bool Entity::IsValidPosition(int posX, int posY) {
	if (posX < 0 || posX >= this->environment->GetGridDimensions().GRID_WIDTH) {
		//std::cout << "X position error" << std::endl;
		return false;
	}
	if (posY < 0 || posY >= this->environment->GetGridDimensions().GRID_HEIGHT) {
		//std::cout << "Y position error" << std::endl;
		return false;
	}
	//get the current grid value at the location. If it contains a digit, it is an entity, 
	//and therefore, the position is occupied and not a valid place to go
	if (isdigit(environment->GetValue(posX, posY)[0])) {
		//std::cout << "Location Occupied error" << std::endl;
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

std::string Entity::GetEntityID() {
	return entityID;
}

MovementSpeed Entity::GetEntityMovementSpeed() {
	return movementSpeed;
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
	Allows the entity to move a single space in a single direction, given the movement is valid,
	and calls for the grid to be updated if the move was successful.
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
			//std::cout << "That is not a valid movement" << std::endl;
			return 0;
		}

		else {
			//first set initial position to "O", 
			environment->UpdateEnvironment(GetEntityXPosition(), GetEntityYPosition(), "O");
			this -> entityPositionX = x;

			//output text indicating the new position that the entity will exist in
			std::cout << "Entity " << this->GetEntityID() << " has moved to X: " << this->GetEntityXPosition() << ", Y: " << this->GetEntityYPosition() << std::endl;
			
			//check if the entity is about to move over food. If it is, it is considered eating, and will increase foodEaten.
			if (environment->GetValue(GetEntityXPosition(), GetEntityYPosition()) == "F") {
				foodEaten++;
				std::cout << "Entity " << this->GetEntityID() << " has eaten food!" << std::endl;
			}

			//set new position value to the entity's ID, and complete the "move"
			environment->UpdateEnvironment(GetEntityXPosition(), GetEntityYPosition(), GetEntityID());
			
			environment->PrintEnvironment();
			return 1;
		}
	}

	if (positionChange == 'y') {
		y = y + direction;
		if (IsValidPosition(x, y) == false) {
			//std::cout << "That is not a valid movement" << std::endl;
			return 0;
		}

		else {
			//first set initial position to "O"
			environment->UpdateEnvironment(GetEntityXPosition(), GetEntityYPosition(), "O");
			this -> entityPositionY = y;

			//output text indicating the new position that the entity will exist in
			std::cout << "Entity " << this->GetEntityID() << " has moved to X: " << this->GetEntityXPosition() << ", Y: " << this->GetEntityYPosition() << std::endl;

			//check if the entity is about to move over food. If it is, it is considered eating, and will increase foodEaten.
			if (environment->GetValue(GetEntityXPosition(), GetEntityYPosition()) == "F") {
				foodEaten++;
				std::cout << "Entity " << this->GetEntityID() << " has eaten food!" << std::endl;
			}
			
			//set new position value to the entity's ID, and complete the "move"
			environment->UpdateEnvironment(GetEntityXPosition(), GetEntityYPosition(), GetEntityID());
			
			environment->PrintEnvironment();
			return 1;
		}
	}
	return 0;
}

/*
	Generates a random positional value(x or y), and a random direction(1, -1)
	for the EntityNormalMovement function, and then calls that function with the randomly 
	generated values. Returns 0 if the movement failed, and 1 if it succeeded.
*/
int Entity::EntityRandomMovement(std::mt19937& generator) {
	//set up the range of value outputs (in this case, it's either 0 or 1)
	std::uniform_int_distribution<> distribution(0, 1);
	
	char positionType;

	int rand1 = distribution(generator);
	int rand2 = distribution(generator);
	
	//determine random position type (x or y)
	if (rand1 == 0) {
		positionType = 'x';
	}
	else if (rand1 == 1) {
		positionType = 'y';
	}
	else {
		std::cout << "Error: Failure in function Entity::EntityRandomMovement()" << std::endl;
		return -1;
	}

	//determine direction (1 or -1)
	if (rand2 == 0) {
		rand2 = -1;
	}

	//make random movement, with movementIndicator to check if it was successful
	//std::cout << "Rand1 is " << rand1 << " and Rand2 is " << rand2 << "." << std::endl;
	int movementIndicator = EntityNormalMovement(positionType, rand2);
	
	return movementIndicator;


}

/*
	Set the base movement speed for the entity

		Parameters:
		-speed: the speed to set base movement speed to
*/
void Entity::SetEntityBaseMovementSpeed(const int speed) {
	movementSpeed.baseMovementSpeed = speed;
}