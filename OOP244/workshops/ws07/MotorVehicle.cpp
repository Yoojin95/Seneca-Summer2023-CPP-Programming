// place your function definitions in an implementation file named MotorVehicle.cpp
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;

/*
Design and code a class named MotorVehicle that holds information about a vehicle with an engine

Private Members
- a license plate number as a statically allocated array of characters of size 9.
- the address where the vehicle is at a given moment as a statically allocated array of characters of size 64.
- the year when the vehicle was built. 

Public Members
- a custom constructor that receives as parameters the license plate number and the year when the vehicle was built. Set the location of the vehicle at Factory. Assume all data is valid.
- void moveTo(const char* address): moves the vehicle to the new address if the new address is different from the current address. Prints to the screen the message
	|[LICENSE_PLATE]| |[CURRENT_ADDRESS] ---> [NEW_ADDRESS]|<ENDL>
	
	where
	the license plate is a field of 8 characters aligned to the right
	current address is a field of 20 characters aligned to the right
	new address is a field of 20 characters aligned to left

- ostream& write(ostream& os): a query that inserts into os the content of the object in the format

	| [YEAR] | [PLATE] | [ADDRESS]	

- istream& read(istream& in): a mutator that reads from the stream in the data for the current object

	Built year: [USER TYPES HERE]
	License plate: [USER TYPES HERE]
	Current location: [USER TYPES HERE]

	
- Helper Functions
overload the insertion and extraction operators to insert a MotorVehicle into a stream and extract a MotorVehicle from a stream. 
These operators should call the write/read member functions in the class MotorVehicle.	
	
*/

namespace sdds 
{
	char pNum[9];
	char cAddress[62];
	int year;

	MotorVehicle::MotorVehicle(const char* pNum, int year, const char* cAddress)
	{



	


		/*
		
		- a custom constructor that receives as parameters the license plate number and the year when the vehicle was built. 
		  Set the location of the vehicle at Factory. Assume all data is valid.
		- void moveTo(const char* address): moves the vehicle to the new address if the new address is different from the current address. Prints to the screen the message
			|[LICENSE_PLATE]| |[CURRENT_ADDRESS] ---> [NEW_ADDRESS]|<ENDL>

			where
			the license plate is a field of 8 characters aligned to the right
			current address is a field of 20 characters aligned to the right
			new address is a field of 20 characters aligned to left
		*/
		
		};
}