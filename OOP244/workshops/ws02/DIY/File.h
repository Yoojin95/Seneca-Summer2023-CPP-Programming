/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, May 30 2023
*******************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds
{
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	bool read(char* p_code);
	bool read(int& population);
}
#endif // !SDDS_FILE_H_
