#pragma once
/*
	Filename: EventObject.h

	Contains a container class for all objects that are part of the simEventHandler 
	Priority Queue. Each object of this class contains references to 
*/

//includes



class EventObject {
public:

	EventObject(char oType, Entity& eRef, Food& fRef);

	int getCurrentSpeedTick();

	//e = entity, f = food.
	char type;
	
	Entity& entityProxy;
	Food& foodProxy;
	int currentSpeedTick = -1;
};