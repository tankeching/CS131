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

#ifndef __Pass__Authentication__
#define __Pass__Authentication__

#include <iostream>
#include <string>
using namespace std;

class Pass
{
public:
	Pass(); //default constructor

	void sysPass(); //system password
	void getPass(); //entered password
	void compare(); //compare system vs entered pass
	void reset(); //
private:
	char systemPass[64]; //holds system password
	char buffer[64]; //holds entered password
	double length; //length of password
	int pass; //result from xor of system password
};


#endif
