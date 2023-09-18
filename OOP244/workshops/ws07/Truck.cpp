// Design and code a class named Truck that holds information about a motor vehicle that can carry cargo. This class should inherit from MotorVehicle class.

/* 

* Truck Private Members
  The class should be able to store the following data (on top of data coming from the parent class):

- a capacity in kilograms as a floating-point number in double precision; this is the maximum weight of the cargo the truck can carry.
- the current cargo load (in kilograms) is a floating-point number in double precision; the load cannot exceed the capacity.

* Truck Public Members
- a custom constructor that receives as parameters the license plate number, the year when the truck was built, the capacity of the truck and the current address. Call the constructor from the base class and pass the license number and year to it. Set the current cargo to 0 and move the truck to the address specified in the last parameter.
- bool addCargo(double cargo): a mutator that adds to the attribute that stores the current cargo load the weight specified as a parameter. Do not exceed the capacity! If the current load has been changed, return true, otherwise return false.
- bool unloadCargo(): a mutator that unloads current cargo (sets the attribute to 0). If the current load has been changed, return true, otherwise, return false.
- ostream& write(ostream& os): a query that inserts into os the content of the object in the format
	| [YEAR] | [PLATE] | [ADDRESS] | [CURRENT_CARGO]/[CAPACITY]
- istream& read(istream& in): a mutator that reads from the stream in the data for the current object
	Built year: [USER TYPES HERE]
	License plate: [USER TYPES HERE]
	Current location: [USER TYPES HERE]
	Capacity: [USER TYPES HERE]
	Cargo: [USER TYPES HERE]
- Helper Functions
   overload the insertion and extraction operators to insert a Truck into a stream and extract a Truck from a stream. These operators should call the write/read member functions in the class Truck.
*/

