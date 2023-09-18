/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 1 2023
*******************************************************************/
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
    class Item {
        char m_itemName[21]; // name of the item
        double m_price; // price of the item
        bool m_taxed;   // whether the items is taxed or not
        void setName(const char* name);
    
    public:
        void setEmpty(); // safe empty state
        void set(const char* name, double price, bool taxed); // sets the value of Item if the provided name is not null and the price is greater than 0
        void display()const; // display the item info including name, price, tax
        bool isValid()const; // checks if Item is valid by verifying the name is not empty and the price is greater than 0
        double price()const; // returns the price of item
        double tax()const;   // returns the tax amount for item
    };
}

#endif // !SDDS_SUBJECT_H
