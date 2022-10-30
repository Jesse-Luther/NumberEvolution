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

	void AddFood(const int posX, const int posY);
	//void RandomFoodSpawn
	//void SpawnFoodLoop    this uses AddFood to spawn food over a period of time
	//void RemoveFood   to be used in future if food has a time limit 
	//void SetSpawnRate 
	//void EatFood???
	
private:
	//food spawn rate
	Environment &environment;

};