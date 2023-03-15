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
#include <random>

#include "Simulation.h"
#include "EventObject.h"

Simulation::Simulation(Environment* environmentO, const int numberOfEntities, std::mt19937 generator) : environment{ environmentO }, numEntities{ numberOfEntities }, randomGenerator{ generator } {

}

/*
	Initialize the EntityList with a number of entities equal to eCount
*/
void Simulation::InitializeEntityListBasic(int eCount) {
	std::uniform_int_distribution<> distribution(1, 10);

	for (int i = 0, j = 0; i < eCount; ++i) {
		entityList.push_back(Entity(i % environment->GetGridDimensions().GRID_WIDTH, j, environment, std::to_string(i + 1), distribution(randomGenerator)));

		//increment the y value (height) if a row gets filled with entities. That way, entities start spawning on the next row
		if ((i % environment->GetGridDimensions().GRID_WIDTH) == (environment->GetGridDimensions().GRID_WIDTH - 1)) {
			++j;
		}
	}
}

void Simulation::InitializeEntityPointerList() {
	int eListSize = entityList.size();
	for (int i = 0; i < eListSize; ++i) {
		entityPointerList.push_back(& entityList[i]);
	}
	std::cout << "ID of Pointer List at [1] is " << entityPointerList[1]->GetEntityID() << std::endl;
}

/*
	Overload the greater than operator, so that it can be used to compare two EventObjects
*/
bool operator > (EventObject const& a, EventObject const& b) { return a.GetCurrentSpeedTick() > b.GetCurrentSpeedTick(); }



/*
		Initializes the PQ with a 1 food Event Object, and size - 1 entity Event Objects.

		Parameters:
			-size: the number of Event Objects that will be stored in the PQ. This value
			will be num entities + 1.
*/
void Simulation::InitializePriorityQueue(const int size) {
	simEventHandler.push(EventObject('f', basicEntityP, foodCreatorP));
	for (int i = 0; i < size - 1; ++i) {
	
		simEventHandler.push(EventObject('e', entityPointerList[i], foodCreatorP));
	}

	std::cout << "Size of PQ is: " << simEventHandler.size() << std::endl;
	std::cout << "Current Tick of top Event Object is " << simEventHandler.top().GetCurrentSpeedTick() << std::endl;

}

/*
	Clears all elements of the priority queue SimEventHandler, leaving it empty
*/
void Simulation::ClearPriorityQueue() {
	simEventHandler = std::priority_queue<EventObject, std::vector<EventObject>, std::greater<EventObject> >();
}


/*
		Resolve the action of an EventObject who's currentSpeedTick currently the lowest, and then reinsert the EO into the PQ.
		Type of action taken is determined by the type of the Event Object. 
*/
void Simulation::ResolveTopAction() {

		//create a copy of the top element of the simEventHandler PQ, so that it can be safely reinserted
		EventObject tempEO = simEventHandler.top();
		
		//the number of attemps an EventObject has to succeed in an action. If it fails 10 times in a row, it is skipped, and will 
		//be reinserted into the queue
		int numAttempts = 0;
		
		//whether or not an event successfully performed its action. If it does, this is switched to true, and the function
		//should stop calling for any more movement. 
		bool eventSuccess = false;

		//try to resolve the EventObject's action 10 times. Upon first success, it should end. Therefore, an EventObject should only 
		//ever take 1 successful action before being reset and reinserted into the queue.
		while (numAttempts < 10 && eventSuccess == false) {
			if (tempEO.PerformTypeAction(randomGenerator) == 1) {
				eventSuccess = true;
			}	
			++numAttempts;
		}
		
		if (tempEO.GetType() == 'e') {
			std::cout << "Entity " << tempEO.entityProxy->GetEntityID() << " has moved." << std::endl;
		}
		if (tempEO.GetType() == 'f') {
			std::cout << "Food has spawned!" << std::endl;
		}
		

		//pop the used EventObject off of the front of the PQ
		simEventHandler.pop();

		//update the EventObject's current tick speed to its new value (previous value + baseValue)
		tempEO.UpdateCurrentSpeedTick();


		//reinsert an EventObject into the queue with the same data as it originally had.
		simEventHandler.push(tempEO);

} 


void Simulation::RunSimulation(int numTicks, int numGens) {
	
	for (int j = 0; j < numGens; ++j) {


		//perform an amount of actions equal to numTicks. This set of actions constitutes a single cycle
		for (int i = 0; i < numTicks; ++i) {
			std::cout << "Action " << i + 1 << std::endl;
			ResolveTopAction();
		}

		for (int i = 0; i < entityList.size(); ++i) {

			//in this loop, we start by storing the data of each entity that was in the previous cycle
			generationHandler.StoreGenerationData(entityList[i]);

			if (generationHandler.CheckSurvival(entityList[i]) == true) {
				std::cout << "entity survived" << std::endl;
				entityList[i].foodEaten = 0;
			}
			else if (generationHandler.CheckSurvival(entityList[i]) == 0) {
				std::cout << "entity did not survive" << std::endl;
				entityList[i].foodEaten = 0;
				++entityList[i].offspringNum;

				//generate new random speed
				std::uniform_int_distribution<> distribution(1, 10);
				entityList[i].SetEntityBaseMovementSpeed(distribution(randomGenerator));

			}
			else {
				std::cout << "Error has occurred in Simulation::RunSimulation" << std::endl;
			}
		}

	}

	//display the data for all entities that were part of the simulation
	generationHandler.DisplayGenerationData();
}


