#pragma once
/*
	Filename: TraitInheritance.h
	Description: Contains functions to store information about the traits that will be passed
	from parent to offspring entities, as well as functions to determine if and how traits
	will be passed.
*/

struct EntityData {
	string id = "0";

	int foodEaten = 0;
	int offSpringNum = 0;
};

class TraitInheritance {

public:
	//determines if the passed entity has eaten enough food. Returns 1 if it has, and 0 if it has not. Also, 
	//stores data about how much food it consumed and 
	int checkSurvival(Entity &entity);

private:
	std::vector<EntityData> generationalDataStorage;

};