//Austin Huerta's program 4 for CS162
//on 11/24/23
//this file contains the definitions of the of the class pokedex as well as 
//the struct pokemon. The class accesses the struct via pointer, and the rest of the program
//accesses it indirectly via the class.
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int NAME = 30;
const int TYPE = 150;
const int MOVES = 150;
//
//
//this struct hold the details of the pokemon as described by the user, and is accessed via the class
struct pokemon
{
	char name[NAME];
	char type[TYPE];
	int candy;
	char moves[MOVES];
	int hp;
	

	
};
//This class is responsible for grouping the necessary data and functions together in one place
//see pokedex.cpp for implementation of functions and respective comments
class pokedex
{
	public:
		pokedex();
		~pokedex();
		void pListHelper();
		void mListHelper();
		void addP();
		void displayP();
		void displayPType();

	private:
		pokemon *pList;//pointer to dynamic array of user defined size to hold the pokemon the user enters
		int pListCap;
		int pListCount;

		pokemon *mList;//pointer to dynamic array of user defined size which contains the moves each pokemon has
		int mListCap;
};

