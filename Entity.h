#pragma once
/*
	Filename: Entity.h
	Description: Contains functions to track information about entities
	that will populate the grid environment.
*/
class Entity {

public:

	Entity(int posX, int posY);

	//int[] GetEntityPosition();
	void SetEntityPosition(int posX, int posY); 

	void UpdateEntityPosition(char positionChange, int amount);
	
	

private:

	//{x position, y position}
	int entityPosition[2];
	

};
