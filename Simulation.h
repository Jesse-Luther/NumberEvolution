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

class Simulation {

public:

	Simulation(Environment environmentO);
	
	//void InitializePriorityQueue(int size)
	//void StartSimulation
	//void HandleMovements
	//void UpdatePositionDis()
	//void createEntity();
	
private:
	Environment& environment;
	Food foodCreator(environment, 5);
	std::vector<Entity> entityList;

};