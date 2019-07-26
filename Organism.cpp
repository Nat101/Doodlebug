/*
Natalie Carlson
Homework4 Doodlebug
4/20/2018
*/

#include "Organism.h"

#include <iostream>
#include <string>
using namespace std;

//constructor
Organism::Organism() : name("org"), symbol('B'), lifespan(0), hungry(0), hasMoved(false)
{
}
Organism::Organism(string name, char symbol, int lifespan, int hungry, bool hasMoved)
	: name(name), symbol(symbol), lifespan(lifespan), hungry(hungry), hasMoved(false)
{
}
//destructor
Organism::~Organism()
{
}
//getters & setters
string Organism::getName()
{
	return name;
}
char Organism::getSymbol()
{
	return symbol;
}
int Organism::getLifespan()
{
	return lifespan;
}
int Organism::getHungry()
{
	return hungry;
}
bool Organism::getHasMoved()
{
	return hasMoved;
}
void Organism::setLifespan(int ls)
{
	if (ls > 0)
		lifespan = lifespan + ls; //increase lifespan count
	else
		lifespan = 0; //reset lifespan(just bred)
}
void Organism::setHungry(int h)
{
	if (h > 0)
		hungry = hungry + h;//increase hunger count
	else
		hungry = 0;//reset hunger count(just fed)
}
void Organism::setHasMoved(bool m)
{
 	hasMoved = m; //set to true or false based on input
}

//action functions
void Organism::move(Organism * org[][SIZE], int i, int j)
{	
}

void Organism::breed(Organism * org[][SIZE], int i, int j)
{
}

void Organism::die(Organism * org[][SIZE], int i, int j)
{		
}
	