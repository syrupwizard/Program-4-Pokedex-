//Austin Huerta's program 4 for CS162
//on 11/24/23
//this file contains implementations of the member functions of the class pokedex. 
//The functions are individually described below

#include "Pokedex.h"

//This function is the constructor for pokedex class
//it simply sets the variables within the class to zero-equivalents
pokedex::pokedex()
{
	pList  = nullptr;
	pListCount = 0;
	pListCap = 0;
	mListCap = 0;
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
	if(mList != nullptr)
	{
		delete [] mList;
		mList = 0;
		mListCap = 0;
	}

}

//this function handles the creation of dynamic arrays, specifically an array of pokemon and
//The inputs are user defined lengths of the two arrays and the outputs are new dynamic arrays of user defined length
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

//this function handles the creation of dynamic array for handling just the move set. This allows the user to define the number of moves all of their pokemon should have. The input is the user's desired move list length and the output is a dynamic array of that length
void pokedex::mListHelper()
{
	if(!mList)
	{
		cout << "How many moves should your pokemon have: ";
		cin >> mListCap;
		cin.ignore(100,'\n');

		while(mListCap <= 0)
		{
			cout << "Please enter a positive number" << endl;

			cout << "How many moves should your pokemon have: ";
			cin >> mListCap;
			cin.ignore(100,'\n');
		}
		
		mList = new pokemon[mListCap];
	
	}
}
// this function prompts the user to enter the details about 1 pokemon at a time, and saves the data into pokemon struct
// and then into a dynamic array of pokemon. 
// Takes input from user and outputs an error if there is no more room in the array for more pokemon.
void pokedex::addP()
{
	if(pListCount < pListCap)
	{
		cout << "Pokemon name: ";
		cin.get(pList[pListCount].name, NAME, '\n');
		cin.ignore(100,'\n');

		cout << "Pokemon type: ";
		cin.get(pList[pListCount].type, TYPE, '\n');
		cin.ignore(100,'\n');

		for(int i = 0; i < mListCap; ++i)
		{
			cout <<  "Pokemon move #" << i+1 << ": ";
			cin.get(mList[i].moves,MOVES, '\n');
			cin.ignore(100, '\n');
		}		

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
//
//This function simply displays the entirety of the contents of the pList array of pokemon
//the function accesses the struct pokemon via the pointer to the dynamic array
//the output is a printed list of pokemon for the user.
void pokedex::displayP()
{
	for(int i = 0; i < pListCount; ++i)
	{
		cout << "\nPokemon #" << i+1 << endl;
		cout << "Name: " << pList[i].name << endl;
		cout << "Type: " << pList[i].type << endl;
		for (int i = 0; i < mListCap; ++i)
			cout << "Move " << i+1 << ": " << mList[i].moves << endl;
		cout << "Candies req: " << pList[i].candy << endl;
		cout << "HP: " << pList[i].hp << endl;
		
	}
}
// This function prompts the user to enter a pokemon type  and displays details of pokemon with that same type.
// Input includes the array of pokemon (pList) and its size (pListSize) for searching through and presenting the list.
// It interacts with the user, allowing them to input an type to search for, and then displays pokemon with matching abilities.
void pokedex::displayPType()
{
    char typeToFind[TYPE];

    cout << "Enter the type to search for: ";
    cin.get(typeToFind,TYPE, '\n');
    cin.ignore(100, '\n');

    bool found = false;

    for (int i = 0; i < pListCount; ++i)
    {
        if (strcmp(pList[i].type, typeToFind) == 0)
        {
            found = true;
			cout << "\n Pokemon #" << i+1 << endl;
			cout << "Name: " << pList[i].name << endl;
			cout << "Type: " << pList[i].type << endl;
			for (int i = 0; i < mListCap; ++i)
				cout << "Move " << i+1 << ": " << mList[i].moves << endl;
			cout << "Candies req: " << pList[i].candy << endl;
			cout << "HP: " << pList[i].hp << endl;
        }
    }

    if (!found)
    {
        cout << "No pokemon found of specified type." << endl;
    }
}

