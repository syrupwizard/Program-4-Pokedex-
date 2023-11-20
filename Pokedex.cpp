#include "Pokedex.h"
//Struct constructor/destructor
pokemon::pokemon()
{
	cout << "Pokemon has been constructed!" << endl;
}

pokemon::~pokemon()
{
}



pokedex::pokedex()
{
	pList  = nullptr;
	pListCount = 0;
	pListCap = 0;
}

pokedex::~pokedex()
{
	if(pList != nullptr)
	{
		delete [] pList;
		pList = 0;
		pListCap = 0;
		pListCount = 0;
	}
}

void pokedex::pListHelper()
{
	if(!pList)
	{
		cout << "How many Pokemon should your Pokedex hold?: ";
		cin >> pListCap;
		cin.ignore(100,'\n');

		while(pListCap <= 0)
		{
			cout << "Please enter a positive number" << endl;
			cout << "How many pokemon should your Pokedex hold: ";

			cin >> pListCap;
			cin.ignore(100,'\n');
		}
		
		pList = new pokemon[pListCap];

	}

}
/*
 * 	char name[NAME];
	char type[TYPE];
	char moves[MOVES];
	int candy;
	int hp;
*/
void pokedex::addP()
{
	if(pListCount < pListCap)
	{
		cout << "Name your Pokemon: ";
		cin.get(pList[pListCount].name, NAME, '\n');
		cin.ignore(100,'\n');

		cout << "What type is your Pokemon?: ";
		cin.get(pList[pListCount].type, TYPE, '\n');
		cin.ignore(100,'\n');

		cout <<  "Describe your Pokemon: ";
		cin.get(pList[pListCount].moves, MOVES, '\n');
		cin.ignore(100, '\n');
		
		cout << "Candy required to level-up your Pokemon: ";
		cin >> pList[pListCount].candy;
		cin.ignore(100,'\n');

		cout << "How many healthpoints does your Pokemon have?: ";
		cin >> pList[pListCount].hp;
		cin.ignore(100,'\n');
		
		pListCount++;
	}
	else
	{
		cout << "Your Pokedex is full!" << endl;
	}
}

void pokedex::displayP()
{
	for(int i = 0; i < pListCount; ++i)
	{
		cout << "Pokemon #" << i+1 << endl;
		cout << "Name: " << pList[i].name << endl;
		cout << "Type: " << pList[i].type << endl;
		cout << "Candies req: " << pList[i].candy << endl;
		cout << "HP: " << pList[i].hp << endl;
		
	}
}
/*
class pokedex
{
	public:
		pokedex();
		~pokedex();
		void pListHelpgter();
		void addP();
		void displayP();
		void displayPType();

	private:
		pokemon pList[];
		int pListCap;
		int pListCount;
	
};

struct pokemon
{
	char name[NAME];
	char type[TYPE];
	char moves[MOVES];
	int candy;
	int hp;
};
*/


