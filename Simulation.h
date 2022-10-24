#pragma once
/*
	Filename: Simulation.h
	Description: Handles processes that are involved in running the simulation
	by controlling the entities, entity movements, and food generation.
*/

class Simulation {

public:

	//void AddFood
	//void StartMovements (maybe this shouldnt be here)
	//void HandleMovements
	//void UpdatePositionDis()
	void createEntity();

	std::vector<Entity> entityList;

};