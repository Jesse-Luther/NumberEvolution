#pragma once
/*
	Filename: Environment.h
	Description: Contains functions to print and update the environment
	that the entities will exist in
*/

//includes


class Environment {

public:

	Environment(const int width, const int height);

	std::vector<std::string> environmentGrid;

	void InitEnvironment(); 
	void UpdateEnivronment(const int posX, const int posY, const std::string updateValue);
	void PrintEnvironment();
	//std::string getValue(int posX, posY);
	//int getGridWidth();
	//int getGridHeight();

private:
	struct GridDimensions {
		//different grid sizes
		const int GRID_WIDTH = 10;
		const int GRID_HEIGHT = 10;
	}gridDimensions;

};
