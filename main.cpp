#include "Pokedex.h"
void welcome();
void displayMenu();
void userChoice(int &userNum);
void runMenu(int &userNum);

int main()
{
	pokedex a_pokedex;
	int userNum = 0;
	welcome();
	userChoice(userNum);	
	while(userNum != 4)
		runMenu(userNum);
	return 0;
}

void welcome()
{
	cout << "PokeDex program. You are now enterying Hyrule!" << endl;
}


//This function displays to the user a list of options to allow them to interact with
//userChoice() and runMenu() functions.
//No input
//prints text to user
void displayMenu()
{
	cout << endl << endl << "Menu - enter number 1-4 to proceed:" << endl;
	cout << "1.	Enter a new Pokemon" << endl;
	cout << "2.	Display all Pokemon" << endl;
	cout << "3.	Display Pokemon of a certain Type" << endl;
	cout << "4.	Quit" << endl;

}

//This function takes userChoice in the form of an integer and sends it to runMenu()
//to select the appropriate menu option. Takes only valid menu options (1-7);
//takes integer and returns it to runMenu()
void userChoice(int &userChoice)
{
	cout << "Choose: ";
	cin >> userChoice;
	cin.ignore(100,'\n');

	while(userChoice < 1 || userChoice > 4)
	{
		cout << "Error! Please enter a number between 1 and 4!" << endl;
		cout << "Choose: ";
		cin >> userChoice;
		cin.ignore(100, '\n');
	}

}

//This function is the backbone of the user's interaction with this program
//it takes their choice as integer input from userChoice and selects from 7 options:
//1.	Enter a new Pokemon
//2.	Display all Pokemon
//3.	Display Pokemon by Type
//4.	Quit
//input includes int choice from userChoice and various other flags to keep things running
//smoothly
//no direct output
void runMenu (int &userNum)
{
	displayMenu();
	userChoice(userNum);
	switch(userNum)
	{
		case 1:
			//addPokemon();
			break;
		case 2:
			//displayPokemon();
			break;
		case 3:
			//displayBy();
			break;
		case 4:
			cout << endl;
			cout << "Come back soon!" << endl;
			return;
	}
}

