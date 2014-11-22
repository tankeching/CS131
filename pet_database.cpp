/*****************main.cpp******************************
Kenneth Tam
Homework 2
Due: Wed, 12 Nov 14
Visual Studio 2010
Implemented search function to Hwk2 code. Created a array of NODE pointers.
Use hash function to index into the array by taking in owner/pet name and creating
a number between 0-99. Could not get collisions working. When search for a name,
the results would display all the proceeding nodes of the searched node. And when
two node have the exact same pet/owner name, the results are displayed in an infinite loop.
Decided to remove the collision check, since collisions generall happen only when two names
are exactly the same. Tried identical names like Kelvin and Kenneth and 
search worked optimally.
****************************************************/

#include "Profile.h"

//***struct public functions, etc.***

profile::profile()
{
	NODE *p;
	p = new NODE;
	head = nullptr;

	for(int i = 0; i < 20; i++)
	{
		p->pet_first_name[i] = NULL;
	}
	for(int j = 0; j < 30; j++)
	{
		p->owner_last_name[j] = NULL;
	}
	for(int k = 0; k < 12; k++)
	{
		p->pet_color[k] = NULL;
	}
	for(int l = 0; l < 10; l++)
	{
		p->DOB[l] = NULL;
	}

	for(int index = 0; index < 100; index++)
	{
		table[index] = NULL;
	}

}




//add a node to linked list
void profile::appendNode()
{
	NODE* newNode, *nodePtr, *hashPtr;
	string pname;
	string oname;
	string pcolor;
	string type;
	string dob;
	int index;

	newNode = new NODE;
	newNode->next = NULL;

	cout << "Enter pet's first name: ";
	cin >> pname;		

	cout << "Enter owner's last name: ";
	cin >> oname;

	cout << "Enter pet's primary color: ";
	cin >> pcolor;

	cout << "Enter pet type(dog,cat,bird,reptile,other): ";
	cin >> type;

	cout << "Enter pet's DOB(XX/XX/XXXX): ";
	cin >> dob;

	index = hash(pname,oname);


	int size = pname.length();
	for(int i = 0; i < size; i++)
	{
		newNode->pet_first_name[i] = pname[i];		
	}

	for(int i = 19; i >= size; i--)
	{
		newNode->pet_first_name[i] = ' ';
	}

	size = oname.length();
	for(int j = 0; j < size; j++)
	{
		newNode->owner_last_name[j] = oname[j];
	}

	for(int j = 29; j >= size; j--)
	{
		newNode->owner_last_name[j] = ' ';
	}

	size = pcolor.size();
	for(int k = 0; k < size; k++)
	{
		newNode->pet_color[k] = pcolor[k];
	}

	for(int k = 11; k >= size; k--)
	{
		newNode->pet_color[k] = ' ';
	}

	size = dob.length();
	for(int l = 0; l < size; l++)
	{
		newNode->DOB[l] = dob[l];
	}

	if(type == "dog" || type == "Dog")
	{
		newNode->pet_type = NODE::Dog;		
	}

	else if(type == "cat" || type == "Cat")
	{
		newNode->pet_type = NODE::Cat;
	}

	else if(type == "bird" "" || type == "Bird")
	{
		newNode->pet_type = NODE::Bird;
	}

	else if(type == "reptile" || type == "Reptile")
	{
		newNode->pet_type = NODE::Reptile;
	}

	else
	{
		newNode->pet_type = NODE::Other;
	}
	

//adding to hash table

	table[index] = newNode;

//adding to linked list
	if (!head)
	{
		head = newNode;
	}

	else
	{
		nodePtr = head;

		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
	}
}

//display linked list
void profile::displayList(void)
{
	NODE* nodePtr;
	nodePtr = head;
	if(nodePtr == NULL)
	{
		cout << "Database is empty." << endl;
	}

	while (nodePtr)
	{
		
		cout << "Pet Name: ";

		for(int i = 0; i < 20; i++)
		{
			cout << nodePtr->pet_first_name[i];
		}

		cout << endl;
		cout << "Owner's Last Name: ";

		for(int j = 0; j < 30; j++)
		{
			cout << nodePtr->owner_last_name[j];
		}

		cout << endl;
		cout << "Pet's color: ";

		for(int k = 0; k < 12; k++)
		{
			cout << nodePtr->pet_color[k];
		}

		cout << endl;

		cout << "Pet Type: ";

		switch(nodePtr->pet_type)
		{
		case NODE::Dog: cout << "Dog";
			break;
		case NODE::Cat: cout << "Cat";
			break;
		case NODE::Bird: cout << "Bird";
			break;
		case NODE::Reptile: cout << "Reptile";
			break;
		case NODE::Other: cout << "Other - Not Listed or Invalid Type";
			break;
		default:
			break;
		}
		cout << endl;
		cout << "Pet's DOB: ";

		for(int l = 0; l < 10; l++)
		{
			cout << nodePtr->DOB[l];
		}

		cout << endl << endl;
		nodePtr = nodePtr->next;
	}


}


//clear entire list
void profile::deleteList(void)
{
	NODE* nodePtr;
	while (head)
	{
		nodePtr = head;
		head = head->next;
	for(int i = 0; i < 20; i++)
	{
		nodePtr->pet_first_name[i] = '\0';
	}
	for(int j = 0; j < 30; j++)
	{
		nodePtr->owner_last_name[j] = '\0';
	}

	for(int k = 0; k < 12; k++)
	{
		nodePtr->pet_color[k] = '\0';
	}

	for(int l = 0; l < 10; l++)
	{
		nodePtr->DOB[l] = '\0';
	}

	nodePtr->pet_type = NODE::Other;
	
	delete nodePtr;
	nodePtr = head;
		
	}

	nodePtr = NULL;
}

//hash function
int profile::hash(string pet, string owner)
{

	int key = 31;

	key = key * (owner[0] ^ pet.length()) * (pet[0] ^ owner.length());

	return key%100;


}


//Search List

void profile::searchList()
{
	int index;
	NODE* ptr;
	string pname;
	string oname;

	cout << "Enter pet's name: ";
	cin >> pname;

	cout << "Enter owner's name: ";
	cin >> oname;

	cout << endl;
	index = hash(pname,oname);
	
	cout << "---RESULTS---" << endl << endl;
	
	if(table[index] != NULL)
	{
		ptr = table[index];
	
			cout << "Pet Name: ";

			for(int i = 0; i < 20; i++)
			{
				cout << ptr->pet_first_name[i];
			}

			cout << endl;
			cout << "Owner's Last Name: ";

			for(int j = 0; j < 30; j++)
			{
				cout << ptr->owner_last_name[j];
			}

			cout << endl;
			cout << "Pet's color: ";

			for(int k = 0; k < 12; k++)
			{
				cout << ptr->pet_color[k];
			}

			cout << endl;

			cout << "Pet Type: ";

			switch(ptr->pet_type)
			{
			case NODE::Dog: cout << "Dog";
				break;
			case NODE::Cat: cout << "Cat";
				break;
			case NODE::Bird: cout << "Bird";
				break;
			case NODE::Reptile: cout << "Reptile";
				break;
			case NODE::Other: cout << "Other - Not Listed or Invalid Type";
				break;
			default:
				break;
			}
			cout << endl;
			cout << "Pet's DOB: ";

			for(int l = 0; l < 10; l++)
			{
				cout << ptr->DOB[l];
			}

			cout << endl;		
	}
	else
	{
		cout << "No results found." << endl << endl;
	}
	
}

//******main code*******

int main()
{	

	profile list;
	char choice;
	bool program = true;


	do
	{
		display_menu();
		cin >> choice;
		choice = tolower(choice);
		if(choice == 'e')
		{
			list.appendNode();
		}
		else if(choice == 's')
		{
			list.searchList();
		}
		else if(choice == 'd')
		{
			list.displayList();
		}
		else if(choice == 'c')
		{
			list.deleteList();
		}
		else if(choice == 'q')
		{
			program = false;
		}
		else
		{
			cout << "INVALID CHOICE" << endl;
		}

		cout << endl;


	}while(program == true);

	cout << "Exiting Program..." << endl;
}