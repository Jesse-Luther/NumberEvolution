#pragma once
/*
	Filename: Environment.h
	Description: Contains functions to print and update the environment
	that the entities will exist in
*/

//includes


class Environment {

public:

	Environment();

	//different grid sizes
	const int GRIDW_10X10 = 10;
	const int GRIDH_10X10 = 10;

	std::vector<std::string> environmentGrid;

	void InitEnvironment(); 
	void UpdateEnivronment(const int posX, const int posY, const std::string updateValue);
	void PrintEnvironment();

private:


};
