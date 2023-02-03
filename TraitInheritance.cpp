/*
	Filename: TraitInheritance.cpp
	Description: Contains functions to store information about the traits that will be passed 
	from parent to offspring entities, as well as functions to determine if and how traits 
	will be passed.
*/


#include <vector>
#include <string>

#include "TraitInheritance.h"

TraitInheritance::TraitInheritance() {

}

//returns true if the entity has eaten the requisite amount of food to survive
bool TraitInheritance::CheckSurvival(Entity entity) {
	if (entity.foodEaten < 15) {
		return false;
	}
	else {
		return true;
	}
}

void TraitInheritance::DisplayGenerationData() {
	int size = generationalDataStorage.size();
	//generation number the function is displaying data for
	int generationNum = 0;

	for (int i = 0; i < size; ++i) {

		//output new generation number if all the data for the previous generation has been displayed
		//A new generation can include surviving members of a prior generation, and is ultimately defined 
		//a new cycle
		if (generationalDataStorage[i].id == "1") {
			//if we are displaying data for the entity with id = 1, that means we have reached the start of a new 
			//generation, and need to display the new generation number (data is displayed for each entity 1 through X, and then 
			//we move on to the next generation and display 1 through X again).
			++generationNum;
			
			std::cout << std::endl << std::endl;
			std::cout << "Generation " << generationNum << std::endl;
		}

		std::cout << "Data for entity line " << generationalDataStorage[i].id << ": " << std::endl;
		std::cout << "Offspring number: " << generationalDataStorage[i].offSpringNum << std::endl;
		std::cout << "Base movement speed: " << generationalDataStorage[i].baseSpeed << std::endl;
		std::cout << "Food eaten: " << generationalDataStorage[i].foodEaten << std::endl << std::endl << std::endl;
	}

}

void TraitInheritance::StoreGenerationData(Entity entity) {
	tempDataStorage.id = entity.GetEntityID();
	tempDataStorage.baseSpeed = entity.GetEntityMovementSpeed().baseMovementSpeed;
	tempDataStorage.foodEaten = entity.foodEaten;
	tempDataStorage.offSpringNum = entity.offspringNum;

	generationalDataStorage.push_back(tempDataStorage);
}

