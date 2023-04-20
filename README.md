
# Number Evolution
## Application Functionality
The purpose of this app is to simulate a general case of natural selection. A population of entities (represented by numeric values) inhabit a grid-based environment, 
and are each given a random movement speed. Over time, food (represented by the letter 'F') spawns around the environment, and the entities are given the opportunity 
to eat it while they roam the environment at various speeds. The simulation runs through multiple generations, and at the end of each generation, each entity is 
evaluated by the amount of food they consumed. If an entity eats enough food to pass a given threshold, with 15 being the default, its offspring will be given its 
movement speed. If, however, an entity fails to consume enough food, it will be replaced by a new, randomly generated entity. 


![Image showing the simulation in progress. Each tick is listed, starting at number 297 and going until 301. Throughout each step, different events happen. For example,
in the first tick shown, entity 1 moves to specified coordinates and consumes food. For tick 298, food spawns.](https://user-images.githubusercontent.com/57116656/233339683-b259e0ac-62fc-46d0-8028-19ebb7f62f66.png)

## Movement Speed

In this simulation, movement speed value corresponds to how many ticks it takes for an entity to move, so a lower value is indicative of a faster movement speed. 
For example, if entity A has a movement speed of 2, and entity B has a movement speed of 8, entity A will move 4 times for every 1 time entity B moves. 

## Slots and Lineages
The amount of entities that can exist in the environment is limited to the chosen number of entity slots. The slots are represented numerically. For example, if we 
have 4 entity slots, then the grid will be occupied by entities 1, 2, 3, and 4. The number of slots serves as an artificial carrying capcity for the environment. If 
entity 1 does not survive a generation, a new entity with a new movement speed will fill its slot, and as such, the new entity will now be represented by the number 1.

At the end of the simulation, data for each slot during each generation is provided. This data includes how much food a specific entity ate during its generation, 
what its movement speed was, whether or not it survived, and the number of unique lineages that occupied the specified slot. At the start of the simulation, the number 
of unique lineages per slot is 1. If the entity occupying a slot survives the generation and reproduces, that number will remain the same. However, if the entity does
not survive the generation and gets replaced by a random new entity, the number increases, since a new, genetically unrelated entity now occupies the slot. 

![Image displaying end of simulation data. At the top, it states that 15 food is required for survival. Then, it shows data , starting with generation 1, entity slot 1. The information
it shows includes the number of unique lineages, the base movement speed, the amount of food eaten, and whether or not the entity ate 
enough food to survive.](https://user-images.githubusercontent.com/57116656/233339928-d74e09a4-0340-430c-b0f8-e28358f8e38c.png)
![Image displaying the last generation's data for the simulation, generation 5. Slot 1 had 5 unique lineages, a base movement speed of 5, and ate 18 food,
therefore surviving. Slot 2 had 2 unique lineages, a base movement speed of 10, and ate 15 food, therefore survivng. Slot 3 had 4 unique lineages, a base
movement speed of 7, and ate 13 food, therefore not surviving. Finally, slot 4 had 1 unique lineage, 2 base movement speed, and ate 39 food, therefore surviving.
](https://user-images.githubusercontent.com/57116656/233340037-b89aa7a9-4bf4-4e55-96bd-62e0ece70305.png)
