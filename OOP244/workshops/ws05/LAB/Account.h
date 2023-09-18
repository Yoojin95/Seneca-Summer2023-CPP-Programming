/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 15 2023
***********************************************************************/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        // 2 attributes (함수나 전역변수의 속성을 지정) attribute vs member variables
        int m_number;   // account number
        double m_balance;   // account balance
        void setEmpty();
    public:
        // Account can be created in 2 different ways

        Account(); // default constructor : set the account as NEW with a balance of 0
        Account(int number, double balance);  // 2 arg constructor: sets the account number and balance to incoming arguments only if both values are valid
                                              // If an invalid account number or a negative balance is passed to the constructor, the object will be set into an invalid empty state
        
        // display function
        // invalid account prints 'Bad Account'
        // new account prints 'New' instead of ACC#
        // At the end, returns the cout obj // cout 리턴은 뭘까?
        std::ostream& display()const;


        // ************************ To be implemented *******************************
        
        //*************** type conversion operators *****************/
        operator bool() const;
        operator int() const;
        operator double() const;

        /**************** Unary member operator *********************/
        bool operator ~() const;

        /***************** Binary member operators(6) *********************/
        // NEW account can be set to an integer
        Account& operator=(const int num);

        // NEW account can be set to another Account
        Account& operator=(Account& move);

        // depositing money into an account
        Account& operator+=(const double money);

        // withdrawing money from an account
        Account& operator-=(const double money);

        // move funds from the right account to the left
        Account& operator<<(Account& move);

        // move funds from the left account to the right
        Account& operator>>(Account& move);
        
        
        
        /**************** Binary helper operators(2) ************************/
        // Return the double value should be the sum of the balances of the two accounts
        friend  double operator+(const Account& left, const Account& right);

        // The value of the balance of the right operand should be added to the left operand
        friend double operator+=(double& value, const Account& add);

    };


}
#endif // SDDS_ACCOUNT_H_
