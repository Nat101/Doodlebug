/*
Natalie Carlson
Homework4 Doodlebug
4/20/2018
*/

#ifndef ORGANISM_H
#define ORGANISM_H

#include "Globals.h"
#include "World.h"

#include <cstdlib>//needed for random
#include <string>
using namespace std;

class World;

class Organism
{
protected:
	string name;
	char symbol;
	int lifespan;
	int hungry;
	bool hasMoved;
	
	
public:
	Organism();
	Organism(string name, char symbol, int lifespan, int hungry, bool hasMoved);
	~Organism();

	string getName();
	char getSymbol();
	int getLifespan();
	int getHungry();
	bool getHasMoved();
	void setLifespan(int ls);
	void setHungry(int h);
	void setHasMoved(bool m);

	
	virtual void move(Organism* org[][SIZE], int i , int j);
	virtual void breed(Organism* org[][SIZE], int i, int j);
	virtual void die(Organism* org[][SIZE], int i, int j);
};

#endif