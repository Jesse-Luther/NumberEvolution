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
#include "TraitInheritance.h"

//class Food;
//class Entity;

class Simulation {

public:

	Simulation(Environment* environmentO, const int numberOfEntities, std::mt19937 generator);

	void InitializeEntityListBasic(int numEntities);
	void InitializeEntityPointerList();
	void InitializePriorityQueue(const int size);
	void ClearPriorityQueue();

	//resolve the action of an EventObject who's currentSpeedTick is 0 or less, and then reinsert the EO into the PQ
	void ResolveTopAction();
	void RunSimulation(int numTicks, int numGens);

	std::mt19937 randomGenerator;
	TraitInheritance generationHandler;

private:
	int numEntities;
	Environment* environment;
	Food foodCreator{ environment, 5 }; 
	Entity basicEntity{ environment };
	//pointers for the Food and Basic entity, to be used in making an EventObject object
	Food* foodCreatorP = &foodCreator;
	Entity* basicEntityP = &basicEntity;

	std::vector<Entity> entityList;
	std::vector<Entity*> entityPointerList;
	std::priority_queue<EventObject, std::vector<EventObject>, std::greater<EventObject> > simEventHandler;


};
