#/*
	Filename: Environment.h
	Description: Contains functions to print and update the environment
	that the entities will exist in
*/

//includes


//defines
#define GRID_WIDTH 10
#define GRID_HEIGHT 10

class Environment {

public:

	Environment();

	std::string environmentGrid[GRID_WIDTH][GRID_HEIGHT];

	void InitEnvironment(); 
	void UpdateEnivronment(int posX, int posY, std::string updateValue);
	void PrintEnvironment();
};