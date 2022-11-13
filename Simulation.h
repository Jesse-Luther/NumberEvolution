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

//class Food;
//class Entity;

class Simulation {

public:

	Simulation(Environment* environmentO, const int numberOfEntities, std::mt19937 generator);
	void InitializeEntityListBasic(int numEntities);
	void InitializeEntityPointerList();
	void InitializePriorityQueue(const int size);

	//void RunSimulation();
	//resolve the action of an EventObject who's currentSpeedTick is 0 or less, and then reinsert the EO into the PQ
	void ResolveTopAction();

	//void HandleMovements
	//void UpdatePositionDis()
	//void createEntity();
	std::mt19937 randomGenerator;

private:
	int numEntities;
	Environment* environment;
	Food foodCreator{ environment, 1 }; 
	Entity basicEntity{ environment };
	//pointers for the Food and Basic entity, to be used in making an EventObject object
	Food* foodCreatorP = &foodCreator;
	Entity* basicEntityP = &basicEntity;

	std::vector<Entity> entityList;
	std::vector<Entity*> entityPointerList;
	std::priority_queue<EventObject, std::vector<EventObject>, std::greater<EventObject> > simEventHandler;


};