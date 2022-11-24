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

int TraitInheritance::CheckSurvival(Entity entity) {
	tempDataStorage.id = entity.GetEntityID();
	tempDataStorage.baseSpeed = entity.GetEntityMovementSpeed().baseMovementSpeed;
	tempDataStorage.foodEaten = entity.foodEaten;
	tempDataStorage.offSpringNum = entity.offspringNum;
	
	generationalDataStorage.push_back(tempDataStorage);

	if (entity.foodEaten < 3) {
		return 0;
	}
	else {
		return 1;
	}
}

void TraitInheritance::DisplayGenerationData() {
	int size = generationalDataStorage.size();
	//generation number the data is displaying data for
	int generationNum = 1;

	for (int i = 0; i < size; ++i) {
		//output new generation number if all the data for the previous generation has been displayed
		if (generationalDataStorage[i].id == "1") {
			std::cout << std::endl << std::endl;
			std::cout << "Generation " << generationNum << std::endl;
		}

		std::cout << "Data for entity line " << generationalDataStorage[i].id << ": " << std::endl;
		std::cout << "Offspring number: " << generationalDataStorage[i].offSpringNum << std::endl;
		std::cout << "Base movement speed: " << generationalDataStorage[i].baseSpeed << std::endl;
		std::cout << "Food eaten: " << generationalDataStorage[i].foodEaten << std::endl << std::endl << std::endl;
	}

}

