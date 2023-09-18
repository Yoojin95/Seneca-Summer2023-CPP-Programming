/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, May 30 2023
*******************************************************************/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#define DATAFILE "PCpopulationsComplete.csv"

namespace sdds 
{
	struct PCpopulations {
		char* p_code;
		int population;
	};

	bool load(const char* filename);
	bool load(PCpopulations& PCpop);
	void sumPopulation();
	void sort();
	void display(const PCpopulations& PCpop);
	void display();
	void deallocateMemory();
}

#endif // !SDDS_POPULATION_H_

