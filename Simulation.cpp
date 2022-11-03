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

#include "Simulation.h"

Simulation::Simulation(Environment& environmentO, const int numberOfEntities) : environment{ environmentO }, numEntities{ numberOfEntities } {

}

/*
	Initialize the EntityList with 4 entities, one in each corner of the grid.
*/
void Simulation::InitializeEntityListBasic() {
			entityList.push_back(Entity(0, 0, environment, "1", 1));
			entityList.push_back(Entity(0, environment.GetGridDimensions().GRID_WIDTH - 1, environment, "2", 2));
			entityList.push_back(Entity(environment.GetGridDimensions().GRID_HEIGHT - 1, 0, environment, "3", 3));
			entityList.push_back(Entity(environment.GetGridDimensions().GRID_WIDTH - 1, environment.GetGridDimensions().GRID_HEIGHT - 1, environment, "4", 4));
}

void Simulation::InitializePriorityQueue(const int size) {
	//simEventHandler.push(entityList[0].)
}

