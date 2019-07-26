/*
Natalie Carlson
Homework4 Doodlebug
4/20/2018
*/

#include "Doodlebug.h"

#include <string>
using namespace std;


Doodlebug::Doodlebug() : Organism("doodlebug", 'X', 0, 0, false)
{
}


Doodlebug::~Doodlebug()
{
}

void Doodlebug::move(Organism * org[][SIZE], int i, int j)
{
	if ((i > 0) && (org[i-1][j] != nullptr) && (org[i][j]->getName() == "ant")) { //checking down for "not out of bounds" and not empty and has ant
		org[(i - 1)][j]->die(org, (i-1), j);//kill ant
		org[i][j]->setHungry(0);//reset doodlebug hunger level to zero
		org[(i - 1)][j] = org[i][j]; //move to new location
		org[(i - 1)][j]->setHasMoved(true);//mark organism as having moved this turn
		org[i][j] = nullptr;//empty orginal location
	}
	else if ((j < SIZE - 1) && (org[i][(j + 1)] != nullptr) && (org[i][j+1]->getName() == "ant")) { //checking right for "not out of bounds" and not empty and has ant
		org[i][(j + 1)]->die(org, i, (j+1)); //kill ant
		org[i][j]->setHungry(0);//reset doodlebug hunger level to zero
		org[i][(j + 1)] = org[i][j]; //move to new location
		org[i][(j + 1)]->setHasMoved(true);//mark organism as having moved this turn
		org[i][j] = nullptr;//empty orginal location
	}
	else if ((i < SIZE - 1) && (org[(i + 1)][j] != nullptr) && (org[i+1][j]->getName() == "ant")) { //checking down for "not out of bounds" and not empty  and has ant
		org[(i + 1)][j]->die(org, (i+1), j); //kill ant
		org[i][j]->setHungry(0);//reset doodlebug hunger level to zero
		org[(i + 1)][j] = org[i][j]; //move to new location
		org[i + 1][j]->setHasMoved(true);//mark organism as having moved this turn
		org[i][j] = nullptr;//empty orginal location
	}
	else if ((j > 0) && (org[i][(j - 1)] != nullptr) && (org[i][j-1]->getName() == "ant")) { //checking left for "not out of bounds" and not empty and has ant
		org[i][(j - 1)]->die(org, i, (j-1)); //kill ant
		org[i][j]->setHungry(0);//reset doodlebug hunger level to zero
		org[i][(j - 1)] = org[i][j]; //move to new location
		org[i][(j - 1)]->setHasMoved(true);//mark organism as having moved this turn
		org[i][j] = nullptr;//empty orginal location
	}
	else {
		org[i][j]->setHungry(1); //no adjacent ants to eat, increase doodlebug hunger one level
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
			if ((j < SIZE - 1) && (org[i][(j + 1)] == nullptr)) { //checking right for "not out of bounds" and empty
				org[i][(j + 1)] = org[i][j]; //move to new location
				org[i][(j + 1)]->setHasMoved(true);//mark organism as having moved this turn
				org[i][j] = nullptr;//empty orginal location
			}
			break;
		case 3:
			if ((i < SIZE - 1) && (org[(i + 1)][j] == nullptr)) { //checking down for "not out of bounds" and empty
				org[(i + 1)][j] = org[i][j]; //move to new location
				org[(i + 1)][j]->setHasMoved(true);//mark organism as having moved this turn
				org[i][j] = nullptr;//empty orginal location
			}
			break;
		}
	}
}

void Doodlebug::breed(Organism * org[][SIZE], int i, int j)
{
	if ((i > 0) && (org[(i - 1)][j] == nullptr)) { //checking down for "not out of bounds" and empty
		org[(i - 1)][j] = new Doodlebug; //create new "child" organism
		org[i][j]->setLifespan(0);//reset "mother" organism lifespan to zero
	}
	else if ((j < SIZE - 1) && (org[i][(j + 1)] == nullptr)) { //checking right for "not out of bounds" and empty
		org[i][(j + 1)] = new Doodlebug; //create new "child" organism
		org[i][j]->setLifespan(0);//reset "mother" organism lifespan to zerotion
	}
	else if ((i < SIZE - 1) && (org[(i + 1)][j] == nullptr)) { //checking down for "not out of bounds" and empty
		org[(i + 1)][j] = new Doodlebug; //create new "child" organism
		org[i][j]->setLifespan(0);//reset "mother" organism lifespan to zero
	}
	else if ((j > 0) && (org[i][(j - 1)] == nullptr)) { //checking left for "not out of bounds" and empty
		org[i][(j - 1)] = new Doodlebug; //create new "child" organism
		org[i][j]->setLifespan(0);//reset "mother" organism lifespan to zero
	}
	else {
		//do nothing, no room to breed
	}
}

void Doodlebug::die(Organism * org[][SIZE], int i, int j)
{
	delete org[i][j];//deletes organism object
	org[i][j] = nullptr; //switch pointer to null
}
