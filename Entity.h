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

	Entity(int posX, int posY, Environment environment, std::string id);

	bool IsValidPosition(int posX, int posY);
	int GetEntityXPosition();
	int GetEntityYPosition();
	//void SetEntityPosition(const int posX, const int posY); 
	
	int EntityRandomMovement();
	int EntityNormalMovement(const char positionChange, const int direction);
	
	
	

private:

	//{x position, y position}
	int entityPositionX;
	int entityPositionY;
	Environment environment;
	std::string entityID = "0";
	

};
