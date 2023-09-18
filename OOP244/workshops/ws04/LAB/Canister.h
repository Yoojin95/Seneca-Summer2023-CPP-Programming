/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 8 2023
*******************************************************************/
#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds {
    class Canister {
        // member variables
        char* m_contentName; 
        double m_diameter;   
        double m_height;     
        double m_contentVolume; 
        bool m_usable;  

        void setToDefault();
        void setName(const char* Cstr);
        bool isEmpty()const;
        bool hasSameContent(const Canister& C)const;
    
    public:
        // Constructors
        Canister(); // default constructor
        Canister(const char* contentName);  // One argument Constructor:
        Canister(double height, double diameter, 
            const char* contentName = nullptr);  
        ~Canister();
       
        Canister& setContent(const char* contentName);
        Canister& pour(double quantity);
        Canister& pour(Canister& C); // (Canister& )
        double volume()const;
        std::ostream& display()const;
        double capacity()const;
        void clear();
    };
}

#endif // !SDDS_BOX_H