#pragma once
/*
	Filename: Entity.h
	Description: Contains functions to track information about entities
	that will populate the grid environment. Entity names MUST be integer 
	values. 
*/

//includes
#include <string>

struct MovementSpeed {
	int baseMovementSpeed = 1;
	int currentMovementSpeedTick = 1;
};

class Entity {

public:

	Entity(Environment* environment0);
	Entity(int posX, int posY, Environment* environmentO, const std::string id, const int speedBase);


	bool IsValidPosition(int posX, int posY);
	int GetEntityXPosition();
	int GetEntityYPosition();
	MovementSpeed GetEntityMovementSpeed();
	//void SetEntityPosition(const int posX, const int posY); 
	
	int EntityRandomMovement(std::mt19937& generator);
	int EntityNormalMovement(const char positionChange, const int direction);

	std::string GetEntityID();

	//keeps track of the amount of food this entity has eaten. Eating food is displayed in EntityNormalMovement, and
	//occurs when an entity moves over food in the environment. 
	int foodEaten = 0;
	

private:

	int entityPositionX = 0;
	int entityPositionY = 0;
	Environment* environment;
	std::string entityID = "0";
	MovementSpeed movementSpeed;
	

};
