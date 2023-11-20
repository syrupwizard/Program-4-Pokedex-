#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int NAME = 30;
const int TYPE = 150;
const int MOVES = 150;

struct pokemon
{
	pokemon();
	~pokemon();
	char name[NAME];
	char type[TYPE];
	char moves[MOVES];
	int candy;
	int hp;
};

class pokedex
{
	public:
		pokedex();
		~pokedex();
		void pListHelper();
		void addP();
		void displayP();
		void displayPType();

	private:
		pokemon *pList;
		int pListCap;
		int pListCount;
};

