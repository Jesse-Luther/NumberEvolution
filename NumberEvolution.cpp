// NumberEvolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>

#include "Environment.cpp"
#include "Entity.cpp"
#include "Food.cpp"
#include "Simulation.cpp"
#include "EventObject.cpp"
#include "TraitInheritance.cpp"



int main()
{
	std::random_device rd1;
	std::mt19937 generator1(rd1());

	Environment environment1(5, 5);
	environment1.InitEnvironment();
	Environment* ePointer = &environment1;
	Simulation sim(ePointer, 4, generator1);
	//sim.InitializeEntityListBasic();
	//Entity entity1(0, 0, ePointer, "1", 8);
	Food foodOb(ePointer, 5);
	sim.InitializeEntityListBasic(4);
	sim.InitializeEntityPointerList();
	//EventObject ob('f', entity1, foodOb);
	sim.InitializePriorityQueue(5);
	
	//EventObject test = sim.simEventHandler.top();
	//std::cout << test.getCurrentSpeedTick() << std::endl;



	//sim.ResolveTopAction();
	sim.RunSimulation(500, 5);


	//EventObject ob('e', sim.entityList[0], foodOb);
	//std::cout << ob.getCurrentSpeedTick();
	
	/*
	std::random_device rd2;
	std::mt19937 generator2(rd2());

   Environment environment1(3, 3);
   environment1.InitEnvironment();
   Entity entity1(1, 1, environment1, "1");
   Entity entity2(2, 2, environment1, "2");

   
   std::cout << "Entity X pos is: " << entity1.GetEntityXPosition() << std::endl;
   std::cout << "Entity Y pos is: " << entity1.GetEntityYPosition() << std::endl;
   std::cout << "Grid Width and Height is: " << environment1.GetGridDimensions().GRID_WIDTH << ", " << environment1.GetGridDimensions().GRID_HEIGHT << std::endl;
   std::cout << "The value at position 0,0 is " << environment1.GetValue(0, 0) << std::endl;

   
   for (int i = 0; i < 3; ++i) {
	   std::cout << "1 moving" << std::endl;
	   int a = entity1.EntityRandomMovement(generator1);
	   std::cout << "2 moving" << std::endl;
	   entity2.EntityRandomMovement(generator1);
   }
   


   //std::cout << "Movement was " << a << std::endl;
   int posX1 = entity1.GetEntityXPosition();
   int posY1 = entity1.GetEntityYPosition();
   //std::cout << "X pos: " << posX1 << "Y pos: " << posY1;

   Food food1(environment1, 4);
   Food food2(environment1);
   std::cout << "Food Spawn Rate is: " << food1.GetSpawnRate() << " and " << food2.GetSpawnRate() << std::endl;

   Simulation simulation1(environment1, 4);
   simulation1.InitializeEntityListBasic();


   

   //generate food with two supposedly different seeds, and ensure the seeds are different by noting whether they give different values. Also tests food spawn distribution.
   /*
   Food food(environment1);
   for (int i = 0; i < 3; ++i) {
	   food.RandomFoodSpawn(generator1);
   }
   std::cout << "==========================================================================" << std::endl;
   for (int i = 0; i < 3; ++i) {
	   food.RandomFoodSpawn(generator2);
   }
  */

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
