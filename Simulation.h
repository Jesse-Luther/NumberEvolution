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

#include "EventObject.h"
class Simulation {

public:

	Simulation(Environment* environmentO, const int numberOfEntities);
	void InitializeEntityListBasic(int numEntities);
	void InitializeEntityPointerList();
	void InitializePriorityQueue(const int size);
	//void StartSimulation
	//void HandleMovements
	//void UpdatePositionDis()
	//void createEntity();


//private:
	int numEntities;
	Environment* environment;
	Food foodCreator{ environment, 5 }; 
	Entity basicEntity{ environment };
	Food* foodCreatorP = &foodCreator;
	Entity* basicEntityP = &basicEntity;

	std::vector<Entity> entityList;
	std::vector<Entity*> entityPointerList;
	std::priority_queue<EventObject, std::vector<EventObject>, std::greater<EventObject> > simEventHandler;


};