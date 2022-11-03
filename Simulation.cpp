/*
	Filename: Simulation.cpp
	Description: Handles processes that are involved in running the simulation
	by controlling the entities, entity movements, and food generation. In other 
	words, a sort of event handler. Core of sim event handler uses Priority Queue.
*/

//includes
#include <queue>

#include "Simulation.h"

Simulation::Simulation(Environment& environmentO, const int numberOfEntities) : environment{ environmentO }, numEntities{ numberOfEntities } {
	try {
		if (numberOfEntities >= 1000) {
			throw numberOfEntities;
		}

	}


	catch (const int numberOfEntities) {
		std::cout << "Error: Too many entities have been added to the queue" << std::endl;
	}
}

void Simulation::InitializePriorityQueue(const int size) {

}