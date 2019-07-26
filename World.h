/*
Natalie Carlson
Homework4 Doodlebug
4/20/2018
*/

#ifndef WORLD_H
#define WORLD_H

#include "Globals.h"
#include "Organism.h"


class Organism;

class World
{
private:	
	Organism* organismAP[SIZE][SIZE]; //pointer to organisms locations
	//counters
	int turnCount = 0;
	int doodlebugCount = 0;
	int antCount = 0;
	
	
public:
	World();//constructor
	~World();//destructor

	void turn(); //intiates one turn
	void print();//prints world map
	
};
#endif

