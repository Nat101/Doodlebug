/*
Natalie Carlson
Homework4 Doodlebug
4/20/2018
*/

#include "World.h"
#include "Organism.h"

#include <iostream>
using namespace std;

int main() {

	
	World x; //create world object
	
	cout << "Press \"enter\" to move through timesteps." << endl;;
	while (cin.get()){
		x.turn();
		
	}
	
	//system("pause"); //visual studio code to prevent viewing window from closing
	return 0;

}