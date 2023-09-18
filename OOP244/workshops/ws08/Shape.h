/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 19 2023
***********************************************************************/
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>

namespace sdds
{
    class Shape
    {
    public:
        /*
            Create a virtual empty destructor for the shape interface.
            this guarantees that any dynamically allocated derived class from the shape interface pointed by a base class pointer will be removed properly from memory when deleted.
        */
        virtual ~Shape() {}
        /*
            Returns void and receives a reference to ostream as an argument. This pure virtual function can not modify the current object.
        */
        virtual void draw(std::ostream& os) const = 0;
        /*
            Returns void and receives a reference to istream as an argument.
        */
        virtual void getSpecs(std::istream& is) = 0;
    };

    std::ostream& operator<<(std::ostream& os, const Shape& src);
    std::istream& operator>>(std::istream& is, Shape& src);
}

#endif
