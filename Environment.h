#pragma once
/*
	Filename: Environment.h
	Description: Contains functions to print and update the environment
	that the entities will exist in
*/

//includes
#include <string>
#include <vector>

struct GridDimensions {
	//different grid sizes
	 int GRID_WIDTH = 10;
	 int GRID_HEIGHT = 10;
};

class Environment {
public:

	Environment(const int width, const int height);

	void InitEnvironment(); 
	void UpdateEnvironment(const int posX, const int posY, const std::string updateValue);
	void PrintEnvironment();
	std::string GetValue(int posX, int posY);
	GridDimensions GetGridDimensions();
	bool IsValidPosition(int posX, int posY);

private:

	std::vector<std::string> environmentGrid;
	GridDimensions gridDimensions;


};
