#pragma once
/*
	Filename: Entity.h
	Description: Contains functions to track information about entities
	that will populate the grid environment.
*/
class Entity {

public:

	Entity(int posX, int posY);
	void UpdateEntityPosition(char positionChange, int amount);
	//int[] GetEntityPosition();
	//void SetEntityPosition(int posX, int posY); used for placing directly on the board onces instantiated
	

private:

	int entityPosition[2] = { 0,0 };
	

};