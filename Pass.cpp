/*****************Pass.h*******************
Kenneth Tam
Homework 5
Due: Wed, 12 Nov 14
Visual Studio 2010
Ran into a problem with getline(). When trying to loop,
program would skip some lines. Fixed by making so that when
asking for user input, a new line is started rather than
continuing on same line as the question. Commented out section
of main code that was used to display values of the xor.
******************************************/


#include "Pass.h"

Pass::Pass()
{
	for(int i = 0; i <= 64; i++)
	{
		systemPass[i] = NULL;
		buffer[i] = NULL;
	}
}


void Pass::sysPass()
{
	cout << "Enter System Password: " << endl;
	cin.getline(systemPass,64);
	length = cin.gcount(); //get length of system password

	for(int i = 0; i < length; i++)
	{
		if(i == 0)
		{
			//xor first 2 chars
			pass = systemPass[i] ^ systemPass[i+1];
		}
		else
		{
			//xor of all chars after first 2
			pass = pass ^ systemPass[i+1];
		}
	}
}

void Pass::getPass()
{
	cout << "Enter Password: " << endl;
	cin.getline(buffer,64);

}

void Pass::compare()
{
	int xor; //holds xor resultof entered password
	for(int i = 0; i < length; i++)
	{
		if(i == 0)
		{
			xor = buffer[i] ^ buffer[i+1]; //xor first 2 chars
		}
		else
		{
			xor = xor ^ buffer[i+1]; //xor of all chars after first 2
		}
	}

	if(xor == pass)
	{
		cout << "Access Granted" << endl;
		//cout << "xor = " << xor << endl;
		//cout << "pass = " << pass << endl;
	}
	else
	{
		cout << "Access Denied" << endl;
		//cout << "xor = " << xor << endl;
		//cout << "pass = " << pass << endl;
	}
}

void Pass::reset()
{
	length = NULL;
	pass = NULL;
	//Sets all passwords to NULL
	for(int i = 0; i <= 64; i++)
	{
		systemPass[i] = NULL;
		buffer[i] = NULL;
	}
}
int main()
{
	Pass password;
	char response;

	do
	{
		password.sysPass();
		password.getPass();
		password.compare();

		cout << "Would you like to test another password(y/n)?" << endl;
		cin >> response;
		cin.ignore();
		response = tolower(response);
		

		cout << endl;
		password.reset();

	}while(response == 'y');
	
	return 0;

}