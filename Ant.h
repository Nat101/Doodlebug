/*
Natalie Carlson
Homework4 Doodlebug
4/20/2018
*/


#ifndef ANT_H
#define ANT_H




#include "Organism.h"

#include <string>
using namespace std;


class Ant : public Organism
{
public:
	Ant();
	~Ant();

	//modified parent functions
	void move(Organism* org[][SIZE], int i, int j);
	void breed(Organism* org[][SIZE], int i, int j);
	void die(Organism* org[][SIZE], int i, int j);
};

#endif

