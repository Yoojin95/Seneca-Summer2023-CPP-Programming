// Final Project Milestone 3 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
/***********************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 29 2023
************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"

namespace sdds
{
    // Add the following global variable (for testing purposes) to the top of the sdds namespace in Date.cpp
    bool sdds_test = false;
    int sdds_year = 2023;
    int sdds_mon = 12;
    int sdds_day = 25;
    
    bool Date::validate()
    {
        errCode(NO_ERROR);
        if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
            errCode(YEAR_ERROR);
        }
        else if (m_mon < 1 || m_mon > 12) {
            errCode(MON_ERROR);
        }
        else if (m_day < 1 || m_day > mdays()) {
            errCode(DAY_ERROR);
        }
        return !bad();
    }

    int Date::mdays()const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
    }

    int Date::systemYear()const {
        int theYear = sdds_year;
        if (!sdds_test) {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            theYear = lt.tm_year + 1900;
        }
        return theYear;
    }

    void Date::setToToday() {
        if (sdds_test) {
            m_day = sdds_day;
            m_mon = sdds_mon;
            m_year = sdds_year;
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            m_day = lt.tm_mday;
            m_mon = lt.tm_mon + 1;
            m_year = lt.tm_year + 1900;
        }
        errCode(NO_ERROR);
    }

    int Date::daysSince0001_1_1()const
    { // Rata Die day since 0001/01/01 
        int ty = m_year;
        int tm = m_mon;
        if (tm < 3)
        {
            ty--;
            tm += 12;
        }
        return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
    }

    Date::Date() :m_CUR_YEAR(systemYear())
    {
        setToToday();
    }

    Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear())
    {
        m_year = year;
        m_mon = mon;
        m_day = day;
        validate();
    }

    const char* Date::dateStatus()const
    {
        return DATE_ERROR[errCode()];
    }

    int Date::currentYear()const
    {
        return m_CUR_YEAR;
    }

    void Date::errCode(int readErrorCode)
    {
        m_ErrorCode = readErrorCode;
    }

    int Date::errCode()const
    {
        return m_ErrorCode;
    }

    bool Date::bad()const
    {
        return m_ErrorCode != 0;
    }




    // reads a date from the console in a format, validates inputs and returns the istream object
    istream& Date::read(istream& is)
    {
        errCode(NO_ERROR); // Clears the error code
        is >> m_year;
        is.ignore();  // ignores a single character after the year and the month values to bypass the Slashes.
        is >> m_mon;
        is.ignore();
        is >> m_day;

        /*
        fail() �Լ��� std::istream Ŭ������ ��� �Լ���, �Է� ��Ʈ��(std::istream)�� ���¸� Ȯ���ϴ� �� ���˴ϴ�.
        fail() �Լ��� �Է� �۾� �߿� ������ �߻��ϰų� �߸��� ������ �����Ͱ� �ԷµǾ��� �� true�� ��ȯ�ϰ�, �׷��� ������ false�� ��ȯ�մϴ�.
        */
        if (is.fail())
        {
            errCode(CIN_FAILED); // ���ڰ� �ǹ��ϴ°� ����?
            /*
              ignore �Լ��� �Է� ��Ʈ������ ���ڸ� �ǳʶٰų� ���۸� ���� �� ���Ǹ�,
              clear �Լ��� ���� ���� �÷��׸� ����� �Է� ��Ʈ���� �ʱ�ȭ�ϴ� �� ���˴ϴ�.
            */
            is.clear();
            /*
                remove "flushing the keyboard" (i.e. cin.ignore(1000,'\n')) at the end of your read function. 
                The read function should not flush the keyboard when the reading process is done
            */
            //is.ignore(200, '\n');
        }
        // validate the values entered
        else
        {
            validate();
            is.clear();
        }

        return is;
    }

    // prints the dateStatus() if the object is in a bad state, or prints the date in a specific format using ostream object
    ostream& Date::write(ostream& os)const
    {
        if (bad())
        {
            os << dateStatus();
        }
        else
        {
            os << m_year << "/";
            os << setw(2) << setfill('0') << m_mon << "/";
            os << setw(2) << setfill('0') << m_day;
            os << setw(0) << setfill(' '); // reset padding to spaces (padding�� �⺻���� �������� �缳��)          
        }

        return os;
    }


    //================= Comparison operator overload methods ================/

    // returns true if the right Date is equal to the current Date object
    bool Date::operator==(const Date& right)const
    {
        return daysSince0001_1_1() == right.daysSince0001_1_1();

    }

    // returns true if the right Date is not equal to the current Date object
    bool Date::operator!=(const Date& right)const
    {
        return daysSince0001_1_1() != right.daysSince0001_1_1();
    }

    // returns true if the current Date object is more recent than or equal to the right Date
    bool Date::operator>=(const Date& right)const
    {
        return daysSince0001_1_1() >= right.daysSince0001_1_1();
    }

    // returns true if the right Date is more recent than or equal to the current Date object
    bool Date::operator<=(const Date& right)const
    {
        return daysSince0001_1_1() <= right.daysSince0001_1_1();
    }

    // returns true if the right Date is more recent than the current Date object
    bool Date::operator<(const Date& right)const
    {
        return daysSince0001_1_1() < right.daysSince0001_1_1();
    }

    // returns true if the current Date object is more recent than the right Date
    bool Date::operator>(const Date& right)const
    {
        return daysSince0001_1_1() > right.daysSince0001_1_1();
    }


    // returns the difference between two Dates in days
    int Date::operator-(const Date& right)const
    {
        int difference;
        difference = daysSince0001_1_1() - right.daysSince0001_1_1();
        return difference;
    }

    // returns true if the Date is valid and false otherwise
    Date::operator bool() const
    {
        return (!bad());
    }

    ostream& operator<<(ostream& os, const Date& RO)
    {
        return RO.write(os);
    }

    istream& operator>>(istream& is, Date& RO)
    {
        return RO.read(is);
    }

}