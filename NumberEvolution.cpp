// NumberEvolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Environment.cpp"
#include "Entity.cpp"



int main()
{

   Environment environment1(5, 5);
   environment1.InitEnvironment();
   environment1.UpdateEnvironment(0, 0, "F");
   Entity entity1(1, 1, environment1, "1");

   
   std::cout << "Entity X pos is: " << entity1.GetEntityXPosition() << std::endl;
   std::cout << "Entity Y pos is: " << entity1.GetEntityYPosition() << std::endl;
   std::cout << "Grid Width and Height is: " << environment1.GetGridDimensions().GRID_WIDTH << ", " << environment1.GetGridDimensions().GRID_HEIGHT << std::endl;
   std::cout << "The value at position 0,0 is " << environment1.GetValue(0, 0) << std::endl;

   int a = entity1.EntityRandomMovement();
   std::cout << "Movement was " << a << std::endl;
   int posX1 = entity1.GetEntityXPosition();
   int posY1 = entity1.GetEntityYPosition();
   std::cout << "X pos: " << posX1 << "Y pos: " << posY1;
   
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
