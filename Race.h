/******************Header.h****************************************************
Kenneth Tam
Homework 3
Due: Wed, 15 Oct 2014
Visual Studio 2010

Included functions to calculate lap times and fuel required for certain laps.
Had to overload operator= in order to setup instace of classes inside an array.
Total fuel required for race is calculated using the data inside the constructor.
*******************************************************************************/



#ifndef __Class__Track__
#define __Class__Track__

#include <iostream>
#include <string>
using namespace std;


class Track
{
public:
	Track();
	Track(string _name, double rlength, double clength, int laps, double time, double fuel);

	void lap_time(); //calculate lap time of specific lap
	void calc_fuel(); // calculate fuel required for lap
	
	string name; //Track name
	double race_length; //total race length
	double circuit_length; //length of a lap

	double total_fuel; //fuel required to finished race
		
	int max_laps; //total laps
	double initial_time; //first lap time

	Track& operator=(const Track& rhs);
	
};

#endif
