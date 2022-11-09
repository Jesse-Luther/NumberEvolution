/*
	Filename: Simulation.cpp
	Description: Handles processes that are involved in running the simulation
	by controlling the entities, entity movements, and food generation. In other 
	words, a sort of event handler. Core of sim event handler uses Priority Queue.
*/

//includes
#include <queue>
#include <string>
#include <vector>
#include <memory>

#include "Simulation.h"
#include "EventObject.h"

Simulation::Simulation(Environment* environmentO, const int numberOfEntities) : environment{ environmentO }, numEntities{ numberOfEntities } {

}

/*
	Initialize the EntityList with 4 entities, one in each corner of the grid.
*/
void Simulation::InitializeEntityListBasic(int eCount) {
	for (int i = 0, j = 0; i < eCount; ++i) {
		entityList.push_back(Entity(i % environment->GetGridDimensions().GRID_WIDTH, j, environment, std::to_string(i + 1), i));

		if ((i % environment->GetGridDimensions().GRID_WIDTH) == 4) {
			++j;
		}
	}
}

void Simulation::InitializeEntityPointerList() {
	int eListSize = entityList.size();
	for (int i = 0; i < eListSize; ++i) {
		entityPointerList.push_back(& entityList[i]);
	}
	std::cout << "ID is " << entityPointerList[1]->GetEntityID() << std::endl;
}

/*
	Overload the greater than operator, so that it can be used to compare two EventObjects
*/
bool operator > (EventObject const& a, EventObject const& b) { return a.currentSpeedTick > b.currentSpeedTick; }



/*

*/
void Simulation::InitializePriorityQueue(const int size) {
	simEventHandler.push(EventObject('f', basicEntityP, foodCreatorP));


	//for (int i = 0; i < size - 1; ++i) {
	
	//	simEventHandler.push(EventObject('e', entityList[i], foodCreator));
	
	//}

	std::cout << "Size of PQ is: " << simEventHandler.size() << std::endl;
	//std::cout << simEventHandler.top().entityProxy;

}

