/*
Natalie Carlson
Extra Credit Animated Doodlebug
5/4/2018
*/

#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "Organism.h"

#include <string>
using namespace std;

class Doodlebug : public Organism
{
public:
	Doodlebug();
	~Doodlebug();

	//modified parent functions
	void move(Organism* org[][SIZE], int i, int j);
	void breed(Organism* org[][SIZE], int i, int j);
	void die(Organism* org[][SIZE], int i, int j);
};
#endif


