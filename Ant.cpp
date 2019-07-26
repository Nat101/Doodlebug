/*
Natalie Carlson
Homework4 Doodlebug
4/20/2018
*/


#include "Ant.h"

#include <string>
using namespace std;


Ant::Ant() : Organism("ant", 'o', 0, 0, false)
{
}


Ant::~Ant()
{
}

void Ant::move(Organism * org[][SIZE], int i, int j)
{
	int direction = (rand() % 4);//select random direction to try to move
	switch (direction) {
		case 0:
			if ((j > 0) && (org[i][(j - 1)] == nullptr)) { //checking left for "not out of bounds" and empty
				org[i][(j - 1)] = org[i][j]; //move to new location
				org[i][(j - 1)]->setHasMoved(true);//mark organism as having moved this turn
				org[i][j] = nullptr;//empty orginal location
			}
			break;
		case 1:
			if ((i > 0) && (org[(i - 1)][j] == nullptr)) { //checking down for "not out of bounds" and empty
				org[(i - 1)][j] = org[i][j]; //move to new location
				org[(i - 1)][j]->setHasMoved(true);//mark organism as having moved this turn
				org[i][j] = nullptr;//empty orginal location
			}
			break;
		case 2:
			if ((j < SIZE-1) && (org[i][(j + 1)] == nullptr)) { //checking right for "not out of bounds" and empty
				org[i][(j + 1)] = org[i][j]; //move to new location
				org[i][(j + 1)]->setHasMoved(true);//mark organism as having moved this turn
				org[i][j] = nullptr;//empty orginal location
			}
			break;
		case 3:
			if ((i < SIZE-1) && (org[(i + 1)][j] == nullptr)) { //checking down for "not out of bounds" and empty
				org[(i + 1)][j] = org[i][j]; //move to new location
				org[(i + 1)][j]->setHasMoved(true);//mark organism as having moved this turn
				org[i][j] = nullptr;//empty orginal location
			}
			break;
	}
}

void Ant::breed(Organism * org[][SIZE], int i, int j)
{
	if ((i > 0) && (org[(i - 1)][j] == nullptr)) { //checking down for "not out of bounds" and empty
		org[(i - 1)][j] = new Ant; //create new "child" organism
		org[i][j]->setLifespan(0);//reset "mother" organism lifespan to zero
	}
	else if ((j < SIZE-1) && (org[i][(j + 1)] == nullptr)) { //checking right for "not out of bounds" and empty
		org[i][(j + 1)] = new Ant; //create new "child" organism
		org[i][j]->setLifespan(0);//reset "mother" organism lifespan to zerotion
	}
	else if ((i < SIZE-1) && (org[(i + 1)][j] == nullptr)) { //checking up for "not out of bounds" and empty
		org[(i + 1)][j] = new Ant; //create new "child" organism
		org[i][j]->setLifespan(0);//reset "mother" organism lifespan to zero
	}
	else if ((j > 0) && (org[i][(j - 1)] == nullptr)) { //checking left for "not out of bounds" and empty
		org[i][(j - 1)] = new Ant; //create new "child" organism
		org[i][j]->setLifespan(0);//reset "mother" organism lifespan to zero
	}
	else {
		//do nothing, no room to breed
	}
}

void Ant::die(Organism * org[][SIZE], int i, int j)
{
	delete org[i][j];//deletes organism object
	org[i][j] = nullptr; //switch pointer to null
}
