// Place your class definition in a header file named MotorVehicle.h
#ifndef SDDS_MOTORVEHICLE_H_
#define SDDS_MOTORVEHICLE_H_

#include <iostream>

namespace sdds 
{
	class MotorVehicle
	{
	/*
		Private Members
		- a license plate number as a statically allocated array of characters of size 9.
		- the address where the vehicle is at a given moment as a statically allocated array of characters of size 64.
		- the year when the vehicle was built.
		*/
		char pNum[9];
		char cAddress[62];
		int year;
	/*
	
	*/
	public:
		MotorVehicle() {};
		MotorVehicle(const char *pN, int y, const char *cAdd = "Factory");
		~MotorVehicle() {};

		void moveTo(const char* address); 
		std::ostream& write(std::ostream& os) const; // display the information of MotorVehicle
		std::istream& read(std::istream& in); // receive new information from the user
	};

	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& src);
	std::istream& operator>>(std::istream& istr, MotorVehicle& src);
}

#endif // !SDDS_MOTORVEHICLE_H_
