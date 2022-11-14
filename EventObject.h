#pragma once
/*
	Filename: EventObject.h

	Contains a container class for all objects that are part of the simEventHandler 
	Priority Queue. Each object of this class contains references to 
*/

//includes
#include <string> 

class EventObject {
public:

	EventObject(char oType, Entity* eRef, Food* fRef);
	int GetCurrentSpeedTick() const;
	void UpdateCurrentSpeedTick();
	char GetType() const;

	int PerformTypeAction(std::mt19937& generator);



//private:

	//e = entity, f = food.
	char type;
	

	Entity* entityProxy;
	Food* foodProxy;
	int currentSpeedTick = -1;
};