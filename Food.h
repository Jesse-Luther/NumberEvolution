#pragma once
/*
	Filename: Food.h
	Description: Handles processes involving the spawning and removing of food 
	from the grid environment.
*/

//includes
#include <random>

//class Environment;

class Food {
public:
	Food(Environment* environmentO);
	Food(Environment* environmentO, const int spawnRate);

	int AddFood(const int posX, const int posY);
	int RandomFoodSpawn(std::mt19937 &generator);
	//void RemoveFood   to be used in future if food has a time limit 
	void SetSpawnRate(int spawnRate);
	int GetSpawnRate();
	//void EatFood???
	
private:
	//food spawn rate
	Environment* environment;
	int foodSpawnRate = 0;
};