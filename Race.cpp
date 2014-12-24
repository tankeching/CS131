/******************Main.cpp****************************************************
Decided to hold data inside a array of classes. We know the number of tracks,
so an array seemed ideal and easy to go through when inquring user input.
Unhandled exception error would not allow me to run program, so had to expand array
by 1 element. Better thing to do might be introducing a secondary variable to
store user input. All time calculations are in minutes. Converted all the times
given to minutes first to make calculation easier.
*******************************************************************************/



#include "Header.h"

Track::Track()
{
	name = "N/A";
	race_length = 0;
	circuit_length = 0;
	max_laps = 0;
	initial_time = 0;
	total_fuel = 0;
}

Track::Track(string _name, double rlength, double clength, int laps, double time, double fuel)
{
	name = _name;
	race_length = rlength;
	circuit_length = clength;
	max_laps = laps;
	initial_time = time;
	total_fuel = fuel;
}

void Track::calc_fuel()
{
	int _lap;
	cout << "Enter a lap number: ";
	cin >> _lap;
	cout << "Fuel required to complete lap " << _lap << " : " 
		<< ((_lap * circuit_length) / 100) * 72 << " liters" << endl;

}


void Track::lap_time()
{
	int _lap;
	cout << "Enter a lap number: ";
	cin >> _lap;
	cout << "Time required to finish lap " << _lap << " : " 
		<< initial_time + ((_lap - 1) * 0.0833) - ((((_lap - 1) * (circuit_length/100) * 72)/10) * 0.0667)
		<< " minutes" << endl;

}

Track& Track::operator=(const Track& rhs)
{
	name = rhs.name;
	race_length = rhs.race_length;
	circuit_length = rhs.circuit_length;
	max_laps = rhs.max_laps;
	initial_time = rhs.initial_time;
	total_fuel = rhs.total_fuel;

	return *this;
}

int main()
{
	int num;
	int track_number;
	bool program = true;
	Track Tracks[6];

	Tracks[0] =  Track("Silverstone", 306.227, 5.891, 52, 1.51456, 220.483);
	Tracks[1] =  Track("SPA-Francorchamps", 308.052, 7.004, 44, 1.7518, 221.797);
	Tracks[2] =  Track("Monte Carlo", 260.520, 3.340, 78, 1.24065, 187.574);
	Tracks[3] =  Track("Fuji", 307.573, 5.807, 53, 1.52566, 221.453);
	Tracks[4] =  Track("Monza", 306.720, 5.793, 53, 1.3507, 220.838);
	Tracks[5] =  Track("Singapore", 304.327, 4.98897, 61, 1.8833, 219.115);

	do
	{
		cout << "Select a track or Quit" << endl;
		cout << "1. Silverstone" << endl;
		cout << "2. SPA-Francorchamps" << endl;
		cout << "3. Monte Carlo" << endl;
		cout << "4. Fuji" << endl;
		cout << "5. Monza" << endl;
		cout << "6. Singapore" << endl;
		cout << "7. Quit" << endl;
		cout << "Enter number: ";

		cin >> num;
		track_number = num - 1;

		if(num <= 6 && num > 0)
		{
			cout << "Fuel required to finish race: " << Tracks[track_number].total_fuel << " liters" << endl;

			cout << "Select another track or Quit" << endl;
			cout << "1. Select another track" << endl;
			cout << "2. Calculate time to complete a lap" << endl;
			cout << "3. Calculate fuel required to complete number of laps" << endl;
			cout << "4. Quit" << endl;
			cout << "Enter number: ";
			cin >> num;

			if(num == 1)
			{
				break;
			}

			else if(num == 2)
			{
				Tracks[track_number].lap_time();
				cout << endl;
			}

			else if(num == 3)
			{
				Tracks[track_number].calc_fuel();
				cout << endl;
			}

			else if(num == 4)
			{
				cout << "Exiting Program." << endl;
				program = false;
			}

			else
			{
				cout << "Invalid Choice." << endl;
			}

		}

		else if(num == 7)
		{
			cout << "Exiting Program..." << endl;
			program = false;
		}

		else
		{
			cout << "Invalid Choice" << endl << endl;
		}
	
	}while(program == true);
	
	return 0;
}