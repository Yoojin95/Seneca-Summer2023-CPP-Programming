/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 1 2023
*******************************************************************/
#include <iostream>
#include "cstring.h"
#include "Bill.h"

using namespace std;

namespace sdds {

    double Bill::totalTax() const
    {
        double result = 0.0;
        for (int i = 0; i < m_noOfItems; i++) {
            // Adds all the taxes of the items
            result += m_items[i].tax(); // calls the tax() member function on the Item object at index 
        }

        return result;
    }

    double Bill::totalPrice() const
    {
        double result = 0.0;

        for (int i = 0; i < m_noOfItems; i++) {
            // Adds all the prices of the items
            result += m_items[i].price(); 
        }

        return result;
    }

    void Bill::Title() const
    {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(36);
            cout << m_title << " |" << endl;
            cout.unsetf(ios::left);
            // cout << "| " << setw(36) << left << m_title << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+" << endl;

        if (isValid()) {
            cout << "|                Total Tax: ";
            display(totalTax());
            cout << "|              Total Price: ";
            display(totalPrice());
            cout << "|          Total After Tax: ";
            display(totalTax() + totalPrice());
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+--------------------------------------+" << endl;
    }

    void Bill::setEmpty()
    {
        *m_title = '\0';
        m_items = nullptr;
    }

    // check validation of Bill object
    bool Bill::isValid() const
    {
        bool result = true;
        bool flag = true;   // for loop execution
        /* 
         flag vs break
         * flag
          : more control and flexibility within the loop
            useful when performing additional actions or checks after the loop terminates, based on the value of the flag
        
         * break
          : clear and concise way to exit a loop early when a certain condition is met
        */ 

        // Check m_title, m_items and all the Items in the m_items array are valid.
        for (int i = 0; i < m_noOfItems; i++) {
            
            // checks if an individual Item is considered valid
            if (!m_items[i].isValid()) {    // checks whether the current Item is valid by calling 'isValid()' member function of the "Item" class
                result = false;
                flag = false;
            }
        }
        return result;
    }

    //  initializing the Bill object with the provided title and number of items
    //  ex. B.init("Quick Shopping", 5);
    void Bill::init(const char* title, int noOfItems)
    {
        if (title == nullptr || noOfItems < 0) {
            setEmpty(); // invalid
        }
        else {
            m_noOfItems = noOfItems;

            m_itemsAdded = 0;   //  keeps track of the number of items added

            strnCpy(m_title, title, 36);

            // dynamic allocate memory
            m_items = new Item[noOfItems];

            // iterates over the newly allocated m_items array
            for (int i = 0; i < noOfItems; i++) {
                // sets the Item to an empty state, likely by resetting member variables to default values
                // ensures that each element of the m_items array is in a well-defined state before any items are added
                m_items[i].setEmpty();
            }
        }
    } // after the loop, Bill object is ready to be used


    // checks if there is space available in the m_items array and, if so, adds a new item by setting the properties of the next available Item object
    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        bool result = false;

        if (m_itemsAdded < m_noOfItems) {

            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;

            result = true;
        }

        return result;
    }

    void Bill::display() const
    {
        Title();

        // loop through the m_items elements, printing every one of them
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }

        footer();
    }

    void Bill::display(double price) const
    {
        cout.width(10);
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << price << " |" << endl;
        cout.unsetf(ios::fixed);
    }

    void Bill::deallocate()
    {
        delete[] m_items;
        m_items = nullptr;
    }
}