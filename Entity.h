#pragma once
/*
	Filename: Entity.h
	Description: Contains functions to track information about entities
	that will populate the grid environment.
*/
class Entity {

public:

	Entity(int posX, int posY, Environment environment);

	bool IsValidPosition(int posX, int posY);
	int GetEntityXPosition();
	int GetEntityYPosition();
	//void SetEntityPosition(const int posX, const int posY); 
	//void EntityRandomMovement?

	int EntityNormalMovement(const char positionChange, const int direction);
	
	
	

private:

	//{x position, y position}
	int entityPositionX;
	int entityPositionY;
	Environment environment;
	
	

};
