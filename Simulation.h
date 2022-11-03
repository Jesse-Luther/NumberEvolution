#pragma once
/*
	Filename: Simulation.h
	Description: Handles processes that are involved in running the simulation
	by controlling the entities, entity movements, and food generation. In other 
	words, a sort of event handler. Core of sim event handler uses Priority Queue.
*/

//includes
#include <vector>
#include <string>
#include <queue>

class Simulation {

public:

	Simulation(Environment& environmentO, const int numberOfEntities);
	void InitializeEntityListBasic();
	void InitializePriorityQueue(const int size);
	//void StartSimulation
	//void HandleMovements
	//void UpdatePositionDis()
	//void createEntity();

private:
	int numEntities;
	Environment& environment;
	Food foodCreator{ environment, 5 }; 

    std::vector<Entity> entityList;
	std::priority_queue<int, std::vector<int>, std::greater<int> > simEventHandler;

};