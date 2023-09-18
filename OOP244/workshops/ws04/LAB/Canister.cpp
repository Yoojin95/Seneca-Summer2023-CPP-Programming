/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 8 2023
*******************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
//#include<string.h>

using namespace std;

const double PI = 3.14159265;   // a global constant double value

namespace sdds {
    // sets the attributes to their default values
    // sets the content name pointer to null, height to 13.0, diameter to 10.0, content volume to 0.0 and usable flag to true
    void Canister::setToDefault()
    {
        m_contentName = nullptr;    // points to a dynamically allocated Cstring
        m_height = 13.0;    // in centimeters 
        m_diameter = 10.0;  // in centimeters
        m_contentVolume = 0.0;   // in CCs
        m_usable = true;    // a flag to identify if the Canister is usable or unusable
    }

    // Sets the content name of the current Canister
    // Cstr is not null and the Canister is usable, it will delete the current content name, allocate memory to the length of Cstr (+1 for null) 
    // and copies the Cstr into the newly allocated memory. Otherwise, it will silently do nothing
    void Canister::setName(const char* Cstr)
    {
        if (Cstr != nullptr && m_usable)
        {
            delete[] m_contentName;
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
    }


    // Returns true is the content volume is less than 0.00001 CCs
    bool Canister::isEmpty()const
    {
        if (m_contentVolume < 0.00001) {
            return true;
        }
        return false;
        //return (m_contentVolume < 0.00001);
    }

    // Compares the content name of this Canister with the one received from the argument C
    //  returns true if both content names are not null and are identical. Otherwise, it returns false
    bool Canister::hasSameContent(const Canister& C)const {
        bool result = false;

        if (this->m_contentName != nullptr && C.m_contentName != nullptr) {
            if (strCmp(this->m_contentName, C.m_contentName) == 0)     // 0 means content names are identical
                result = true;
        }
        return result;
    }

    // Constructors

    // sets the attributes to their default values
    Canister::Canister()
    {
        setToDefault();
    }

    // sets the attributes to their default values (note: reuse code)
    // sets the Name to the incoming contentName argument.
    Canister::Canister(const char* contentName)
    {
        setToDefault();
        setName(contentName);
    }


    Canister::Canister(double height, double diameter, const char* contentName)
    {
        // sets the attributes to their default values
        setToDefault();

        // If the dimensions are within acceptable values
        //  - set the m_height and m_diameter to the corresponding argument values
        //  - set the content volume to 0
        //  - set the content name to the corresponding argument value


        // The smallest Canister height and diameter: 10.0 by 10.0 centimetres and the largest one can be 40 by 30

        if (height >= 10.0 && diameter >= 10 && height <= 40 && diameter <= 30)
        {
            m_height = height;
            m_diameter = diameter;
            m_usable = true;
            //set the content name to the corresponding argument value?
            setName(contentName);
        }
        else {
            m_usable = false;
        }
    }


    // Destructor 

    // Deallocates the dynamic memory pointed by the content name attribute
    Canister::~Canister()
    {
        if (m_contentName) {
            delete[] m_contentName;
        }
    }
    /*

    Deallocation

    ~stuff() {
    delete[] name;
    }

    deallocate () {
    delete[] name;
    name = nullptr;

    */


    // Clears an unusable Canister back to an empty Canister
    void Canister::clear()
    {
        // deallocating the memory pointed by the content name attribute
        // sets the content name attribute to nullptr
        // sets the content volume attribute to 0.0
        // set the usable flag attribute to true
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    // returns the capacity as stated in Calculating the capacity
    double Canister::capacity()const
    {   // capacity = PI x (H - 0.267) x (D/2) x (D/2)
        return  PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
        
    }

    double Canister::volume()const
    {
        return m_contentVolume;
    }

    // set the Content name of the canister using rule and then returns the reference of the current object (i.e. *this):
    Canister& Canister::setContent(const char* contentName)
    {
        // if the contentName is null, it will render the Canister unusable
        //  bool m_usable;
        if (contentName == nullptr || contentName[0] == '\0') {
            m_usable = false;
        }
        
        // else if the Canister is empty it will 'set the Name' to the value pointed by the argument
        else if (isEmpty()) {
            setName(contentName); // if Canister's content is empty, set the name of the Canister by calling the setName() function
        }
        
        // if the name of the Canister is not the same as the contentName argument it will render the Canister unusable
        // checks whether the Canister already has content
        else if (!hasSameContent(contentName)) { // ? strCmp / !hasSameContent(contentName)
            m_usable = false;
        }
        
        return *this; // returns a reference to the current Canister object
    }


    // Adds the quantity argument to the content volume of the Canister if the quantity fits in the Canister. 
    // Otherwise, it will render the Canister unusable and then returns the reference of the current object.
    Canister& Canister::pour(double quantity)
    {
        //bool result = false;
        // If the Canister is usable and the quantity is more than zero and if the sum of the quantity and the volume() is less than or equal to the capacity(),
        if (m_usable && quantity > 0.0 && (quantity + volume()) <= capacity()) {
            // add the quantity to the content volume
            m_contentVolume += quantity;
            //result = true; // 생략가능?
        }
        // otherwise set usable flag attribute to false.
        else {
            m_usable = false; // return result는 왜 안됨?
        }
        return *this;
    }


    Canister& Canister::pour(Canister& C)
    {
        // Set the content name to the Canister argument using setContent().
        setContent(C.m_contentName);

        // if the volume() of the argument is greater than the capacity() minus the volume()
        if (C.volume() > (this->capacity() - this->volume())) {
            // Reduce the content volume of the argument by capacity() minus volume() 
            C.m_contentVolume -= (this->capacity() - this->volume());
            // and then set the content volume to capacity()
            this->m_contentVolume = capacity();
        }
        else {
            // else pour the content volume of the argument using pour() method 
            pour(C.m_contentVolume);
            // and set the content volume of the argument to 0.0.return the reference of the current object at the end.
            C.m_contentVolume = 0.0;
        }
        return *this;
    }


    std::ostream& Canister::display()const
    {
        //double cap = capacity();
        cout << setw(7) << fixed << setprecision(1) << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
        
        if (!m_usable) {
            cout << " of Unusable content, discard!";
        }
        
        else if (m_contentName != nullptr) {
            cout << " of " << setw(7) << fixed << setprecision(1) << m_contentVolume << "cc   " << m_contentName;
        }
       // cout << endl;

        return cout;
    }
}