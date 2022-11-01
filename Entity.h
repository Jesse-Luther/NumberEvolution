#pragma once
/*
	Filename: Entity.h
	Description: Contains functions to track information about entities
	that will populate the grid environment.
*/

//includes
#include<string>

class Entity {

public:

	Entity(int posX, int posY, Environment &environmentO, const std::string id);

	bool IsValidPosition(int posX, int posY);
	int GetEntityXPosition();
	int GetEntityYPosition();
	//void SetEntityPosition(const int posX, const int posY); 
	
	int EntityRandomMovement(std::mt19937& generator);
	int EntityNormalMovement(const char positionChange, const int direction);

	std::string GetEntityID();
	

	

private:

	//{x position, y position}
	int entityPositionX;
	int entityPositionY;
	Environment &environment;
	std::string entityID = "0";
	//int foodConsumed = 0;
	//int movementSpeed = 0;
	

};
