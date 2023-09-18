/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 1 2023
*******************************************************************/
#include <iostream>
#include "cstring.h"
#include "Item.h"
#include <iomanip> // needed for formatting cout in display
using namespace std;
namespace sdds {
    // set the itemName variable to the name argument up to 20
    void Item::setName(const char* name)
    {
        strnCpy(m_itemName, name, 20);
    }

    // safe empty state
    void Item::setEmpty()
    {
    
        *m_itemName = '\0'; // setting the m_itemName to a blank string (null)
        m_price = 0.0;      // setting the price to an impossible value
    }

    void Item::set(const char* name, double price, bool taxed)
    {
        // Check price is less than 0 or name is null
        if (name != nullptr && price > 0)
        {
            // Enter the corresponding values
            setName(name);   
            m_price = price;
            m_taxed = taxed;
        }
    }

    void Item::display() const {

        if (!isValid()) {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
        else {
            cout << "| " << setfill('.') << setw(20) << left << m_itemName;
            cout << " | " << setfill(' ') << setw(7) << right << fixed << setprecision(2) << m_price;
            cout << " | " << (m_taxed ? "Yes" : "No ") << " |" << endl;
        }

    }

    bool Item::isValid() const
    {
        bool result = false;

        if (*m_itemName != '\0' && m_price > 0)
            result = true;

        return result;
        
        // return m_itemName[0] != '\0' && m_price > 0;
    }

    double Item::price() const
    {
        return m_price;
    }

    double Item::tax() const
    {
        double result = 0.0;

        if (m_taxed) {
            result = (m_price * 0.13);
        }

        return result;
    }



}
