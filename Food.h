#pragma once
/*
	Filename: Food.h
	Description: Handles processes involving the spawning and removing of food 
	from the grid environment.
*/

//includes

class Food {
public:
	Food(Environment &environmentO);

	//void AddFood
	//void RandomFoodSpawn
	//void spawnFoodLoop    this uses AddFood to spawn food over a period of time
	//void RemoveFood   to be used in future if food has a time limit 
	//void setSpawnRate 
	
private:
	//food spawn rate
	Environment &environment;

};