/*
	Filename: EventObject.cpp

	Contains a container class for all objects that are part of the simEventHandler
	Priority Queue. Each object of this class contains references to
*/

//includes
#include <string>
#include "Entity.h"
#include "Food.h"
#include "EventObject.h"

EventObject::EventObject(char oType, Entity* eRef, Food* fRef) : type{ oType }, entityProxy{ eRef }, foodProxy{ fRef } {
	if (oType == 'e') {
		currentSpeedTick = entityProxy->GetEntityMovementSpeed().baseMovementSpeed;
	}
	else if (oType == 'f') {
		currentSpeedTick = foodProxy->GetSpawnRate();

	}
	else {
		std::cout << "AN ERROR HAS OCCURRED" << std::endl;
	}
}

int EventObject::GetCurrentSpeedTick() const{
	return currentSpeedTick;
}

char EventObject::GetType() const{
	return type;
}

/*
	Performs the action corrosponding to the type of object that the EventObject is representing.
	If it is a Food object, it spawns a random food, and if it an entity, it makes a random 
	movement. Will return 0 if it failed to take its action (entity tried to move to an invalid
	location or food tried to spawn in invalid location), and 1 if it succeeded. More action types 
	or EventObject types may be added in the future. 

	Parameters:
		-generator: a generator created using a random device in main. Note: this functionality has 
		only been tested in visual studio, and may not work using compilers from other environments.
		A possible failure state would be lack of proper randomization. 
*/
int EventObject::PerformTypeAction(std::mt19937& generator) {
	if (type == 'f') {
		if (foodProxy->RandomFoodSpawn(generator) == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else if (type = 'e') {
		if (entityProxy->EntityRandomMovement(generator) == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else {
		assert(type == 'f' || type == 'e');
	}
}

