/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 1 2023
*******************************************************************/
#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Item.h"
namespace sdds {
    class Bill {

        /* Private Variables */
        char m_title[37];    // title of the shopping list
        Item* m_items;       // pointer to the dynamically allocated array of Items
        int m_noOfItems;     // size of the dynamically allocated array of Items
        int m_itemsAdded;    // number of Items added using 'add' method
        
        
        /* Private member functions */
        double totalTax()const;     
        double totalPrice()const;   
        void Title()const;          
        void footer()const;
        
        // set the Bill object to an empty state
        void setEmpty(); 
        
        // Check m_title, m_items and all the Items in the m_items array are valid.
        bool isValid()const; 
    
    
    public:
        // if the incoming arguments are valid, it will dynamically allocate an array of Items
        void init(const char* title, int noOfItems);    

        // this function will set the next available subject to the incoming argument values
        bool add(const char* item_name, double price, bool taxed);
        
        // display title, all m_items element and footer
        void display()const;

        // overloaded function to display total tax, price and final price wih tax
        void display(double price) const;

        // deallocates the m_items arrays
        void deallocate();
    };
}
#endif // !SDDS_TRANSCRIPT_H