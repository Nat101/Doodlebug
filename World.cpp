/*
Natalie Carlson
Homework4 Doodlebug
4/20/2018
*/

#include "World.h"
#include "Doodlebug.h"
#include "Ant.h"

#include <iostream>
using namespace std;


//constructor
World::World()
{
	
	//initialize empty world (all nullptr);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			organismAP[i][j] = nullptr;
		}
	}

	//random starting doodlebug placement
	int orgCount = 0;
	while (orgCount <SDB) {
		int i = (rand() % (SIZE));
		int j = (rand() % (SIZE));
		if (organismAP[i][j] == nullptr) {
			organismAP[i][j] = new Doodlebug;
			orgCount++;
		}
	}
	//random starting ant placement
	orgCount = 0;
	while (orgCount <SA) {
		int i = (rand() % (SIZE));
		int j = (rand() % (SIZE));
		if (organismAP[i][j] == nullptr) {
			organismAP[i][j] = new Ant;
			orgCount++;
		}
	}

	cout << "start:" << " doodlebug count: " << SDB << ", ant count: " << SA << endl;
	print();
}

//destructor
World::~World()
{
	//delete world
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			delete organismAP[i][j];
		}
	}	
}

//action methods:
void World::turn()
{
	turnCount++; //increase turn count
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (organismAP[i][j] != nullptr) { //only act on indexes containing organisms
				if (organismAP[i][j]->getName() == "doodlebug") {
					organismAP[i][j]->setHasMoved(false);//reset all doodlebugs to not moved
				}
				else if (organismAP[i][j]->getName() == "ant") {
					organismAP[i][j]->setHasMoved(false);//reset all ants to not moved
				}
			}
		}
	}
	///////////////////////////////////////doodlebug turn////////////////////////
	//doodlebug move
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if ((organismAP[i][j] != nullptr) && (organismAP[i][j]->getName() == "doodlebug") && organismAP[i][j]->getHasMoved() == false) {  
			//only act on indexes containing doodlebugs that have not moved this turn			
				organismAP[i][j]->setLifespan(1);//increase doodlebug lifespan by one
				organismAP[i][j]->move(organismAP, i, j); //initiate movements
			}
		}
	}
	//doodlebug breed
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if ((organismAP[i][j] != nullptr) && (organismAP[i][j]->getName() == "doodlebug")) {//only act on indexes containing doodlebugs	
				if (organismAP[i][j]->getLifespan() == 8) {//checking lifespan (doodlebugs breed every 8 turns)
					organismAP[i][j]->breed(organismAP, i, j); //initiate breeding
				}
			}
		}
	}
	//doodlebug die
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if ((organismAP[i][j] != nullptr) && (organismAP[i][j]->getName() == "doodlebug")) {//only act on indexes with doodlebugs
				if (organismAP[i][j]->getHungry() == 3) {//checking hunger (doodlebugs starve at the end of three turns w/ out food)
					organismAP[i][j]->die(organismAP, i, j); //initiate dying
				}
			}
		}
	}
	///////////////////////////////////////ants turn//////////////////////////////
	//ant move
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if ((organismAP[i][j] != nullptr) && (organismAP[i][j]->getName() == "ant") && (organismAP[i][j]->getHasMoved() == false)) { 
			//only act on indexes containing ants that have not moved this turn			
				organismAP[i][j]->setLifespan(1);//increase organisms lifespan by one
				organismAP[i][j]->move(organismAP, i, j); //initiate movements
			}
		}
	}
	//ant breed
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if ((organismAP[i][j] != nullptr) && (organismAP[i][j]->getName() == "ant")) {//only act on indexes containing ants	
				if (organismAP[i][j]->getLifespan() == 3) {//checking lifespan (ants breed every three turns)
					organismAP[i][j]->breed(organismAP, i, j); //initiate breeding
				}
			}
		}
	}
	/////////////////////////////////////////////////////////////////////////////////
	
	doodlebugCount = 0; //reset counter for new calculations
	antCount = 0; //reset counter for new calculations
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (organismAP[i][j] != nullptr) { //only act on indexes containing organisms
				if (organismAP[i][j]->getName() == "doodlebug") { //only act on indexes containing doodlebugs	
					doodlebugCount++; //count current number of doodlebugs in world
					organismAP[i][j]->setHasMoved(false);//reset all doodlebugs to not moved
				}
				else if (organismAP[i][j]->getName() == "ant") { //only act on indexes containing ants	
					antCount++; //count current number of ants in world
					organismAP[i][j]->setHasMoved(false);//reset all ants to not moved
				}
			}
		}
	}
	//system("CLS"); //visual studio command to clear screen
	//output updated state of world
	cout << "after " << turnCount << " timesteps: doodlebug count: "<<doodlebugCount<<", ant count: "<<antCount<<endl;
	print(); 
}

void World::print()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (organismAP[i][j] == nullptr) {
				//cout << "[" << i << "][" << j << "]  ";
				cout << ".";
			}
			else {
				cout <<organismAP[i][j]->getSymbol(); //prints symbol of organism at address being pointed to.
			}
		}
		cout << endl; //starts new row
	}
	cout << endl; //space between print calls
}



