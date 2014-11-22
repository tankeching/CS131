/*****************Profile.h******************************
Kenneth Tam
Homework 4
Due: Wed, 12 Nov 14
Visual Studio 2010
Implemented search function to Hwk2 code. Created a array of NODE pointers.
Use hash function to index into the array by taking in owner/pet name and creating
a number between 0-99. Could not get collisions working. When search for a name,
the results would display all the proceeding nodes of the searched node. And when
two node have the exact same pet/owner name, the results are displayed in an infinite loop.
Decided to remove the collision check, since collisions generall happen only when two names
are exactly the same. Tried identical names like Kelvin and Kenneth and search worked optimally.
****************************************************/
#ifndef __Pet__Profile__
#define __Pet__Profile__


#include <iostream>
#include <string>
using namespace std;

void display_menu()
{
	cout << "MENU" << endl;
	cout << "[E]nter - Enter in a pet's data" << endl;
	cout << "[S]earch - Search database for a pet by the pet's first name" << endl;
	cout << "[D]isplay - Displays all data in the databse" << endl;
	cout << "[C]lear - Clear the entire database" << endl;
	cout << "[Q]uit - Quit the program" << endl << endl;
}

class profile
{
public:

	profile();
	
	void appendNode();
	void deleteList();
	void displayList();
	void searchList();
	int hash(string pet, string owner);

private:
	struct NODE
	{

		char pet_first_name[20];
		char owner_last_name[30];
		char pet_color[12];
		enum TYPE {Dog, Cat, Bird, Reptile, Other};
		TYPE pet_type;
		char DOB[10];

		struct NODE* next;
	};

	NODE* head;
	NODE* table[100];

};


#endif