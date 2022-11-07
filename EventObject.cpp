/*
	Filename: EventObject.cpp

	Contains a container class for all objects that are part of the simEventHandler
	Priority Queue. Each object of this class contains references to
*/

//includes

#include "Entity.h"
#include "Food.h"
#include "EventObject.h"

EventObject::EventObject(char oType, Entity& eRef, Food& fRef) : type{ oType }, entityProxy{ eRef }, foodProxy{ fRef } {
	if (oType == 'e') {
		currentSpeedTick = entityProxy.GetEntityMovementSpeed().baseMovementSpeed;
	}
	else if (oType == 'f') {
		currentSpeedTick = foodProxy.GetSpawnRate();
	}
	else {
		std::cout << "AN ERROR HAS OCCURRED" << std::endl;
	}
}

int EventObject::getCurrentSpeedTick() {
	return currentSpeedTick;
}