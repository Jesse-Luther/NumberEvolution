#pragma once
/*
	Filename: Entity.h
	Description: Contains functions to track information about entities
	that will populate the grid environment.
*/
class Entity {

public:

	Entity(int posX, int posY, Environment environment);

	bool IsValidPosition(int posX, int posY, Environment environment);
	//int[] GetEntityPosition();
	void SetEntityPosition(const int posX, const int posY); 

	void UpdateEntityPosition(const char positionChange, const int amount);
	
	
	

private:

	//{x position, y position}
	int entityPositionX;
	int entityPositionY;
	
	

};
