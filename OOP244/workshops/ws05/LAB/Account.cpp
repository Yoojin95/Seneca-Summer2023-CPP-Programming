/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 15 2023
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;

namespace sdds {
    
    // invalid empty state
    // Account is in invalid state if invalid info is fed into the account
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }

    // New account
    // 'New': just created account, 'Not Set': not assigned account
    Account::Account() {
        m_number = 0;   // Account class is flagged by setting the account number
        m_balance = 0.0;
    }

    // Valid account 
    // Account is considered valid if ACC# is a 5 digit integer with a zero or positive balance
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }

    // | 11111 |       111.11 | 
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }


    /*************** type conversion operators *****************/

    // returns true if the account is valid
    Account::operator bool() const {
        return (this->m_number >= 10000 && this->m_number <= 99999
            && m_balance >= 0);
    }

    // returns the account number
    Account::operator int() const {
        return m_number;
    }

    // returns the balance value
    Account::operator double() const {
        return m_balance;
    }

    /**************** Unary member operator *********************/

    // returns true is the account is new or not set
    bool Account::operator ~() const {
        return m_number == 0;
    }

    /***************** Binary member operators(6) *********************/
   // NEW account can be set to an integer
    Account& Account::operator=(const int num) {
        // set New account to an integer
        if (m_number == 0) {
            m_number = num;
        }
        // If the integer value is an invalid account number, the object should be set to an invalid empty state instead
        else if (num < 0) {
            setEmpty();
        }
        return *this;
    }

    // NEW account can be set to another Account
    Account& Account::operator=(Account& move) {
        if (this->m_number == 0 && move.m_number > 0) {
            this->m_number = move.m_number;
            this->m_balance = move.m_balance;

            // set another account to New account
            move.m_number = 0;
            move.m_balance = 0;
        }
        return *this;
    }

    // depositing money into an account
    Account& Account::operator+=(const double money) {
        if (m_number > 0 && m_balance >= 0.0 && money > 0.0) {
            this->m_balance += money;
        }
        return *this;
    }

    // withdrawing money from an account
    Account& Account::operator-=(const double money) {
        if (m_number > 0 && m_balance >= money && money>= 0.0) {
            this->m_balance -= money;
        }
        return *this;
    }
   
    // move funds from the right account to the left
    Account& Account::operator<<(Account& move) {
        if (this->m_number > 0 && move.m_number > 0 && this->m_number != move.m_number) {
            this->m_balance += move.m_balance;
            move.m_balance = 0;
        }
        return *this;
    }

    // move funds from the left account to the right
    Account& Account::operator>>(Account& move) {
        if (this->m_number > 0 && move.m_number > 0 && this->m_number != move.m_number) {
            move.m_balance += this->m_balance;
            this->m_balance = 0;
        }
        return *this;
    }

    /**************** Binary helper operators(2) ************************/
    // double value should be the sum of the balances of the two accounts
    double operator+(const Account& left, const Account& right) {
        double sum = 0.0;
        if (left.m_number > 0 && right.m_number > 0) {
            sum = left.m_balance + right.m_balance;
        }
        return sum;
    }

    // The value of the balance of the right operand (account reference) should be added to the left operand (double reference)
    double operator+=(double& value, const Account& add) {
        if (add.m_balance > 0) {
            value += add.m_balance;
        }
        return value;

    }

}