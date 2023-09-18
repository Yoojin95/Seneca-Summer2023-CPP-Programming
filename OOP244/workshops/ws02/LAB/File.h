/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, May 24 2023
*******************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare read prototypes
	bool read(char* empName);
	bool read(int& empNumber);
	bool read(double& empSalary);
}
#endif // !SDDS_FILE_H_
