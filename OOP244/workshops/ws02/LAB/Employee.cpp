/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, May 24 2023
*******************************************************************/

#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"

using namespace std;

namespace sdds {

    int noOfEmployees;
    Employee* employees;

    // sorting the array of employees based on the employee number
    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    //       reads one employee record from the file and loads it into the employee reference argument
    bool load(Employee& employees) { 
        // Employee& employees
        // -> employees is a reference to an 'Employee' object
        // -> allows to access and manipulate the original object directly, without creating a copy
        // -> using a reference as a parameter, any modifications made to reference employees will affect the original object
        bool ok = false;
        char name[128];
        /*
        struct Employee {
            char* m_name;
            int m_empNo;
            double m_salary;
            }
        */

        // if reading of employee number, salay and name are successful
        if (read(employees.m_empNo) && read(employees.m_salary) && read(name)) { // ?? ¿Ö employees.m_name ¾ÈµÊ? 
                                                                                 // employee.m_name is not yet pointing to valid memory until it is allocated using new char[len]
                                                                                 // it would result in undefined behavior or potential crash due to writing into an invalid memory location

            // find the length of the employee name using strLen and then add one for null termination
            int len = strLen(name) + 1;
            
            // allocate the same amount of characters in the name of the Employee parameter
            employees.m_name = new char[len];
            
            // copy the read name into newly allocated name of the Employee parameter
            strCpy(employees.m_name, name);
            
            ok = true;
        }
        return ok;
    }

    // TODO: Finish the implementation of the 0 arg load function 
    // figure out how many employees via noOfrecords func from file
    //bool load() {
    //    bool ok = false;
    //    int cnt = 0; // cnt is to check if the file is read successfully
    //    
    //    if (openFile(DATAFILE)) 
    //    {
    //        // Get the number of records(employees) from the file and store it into the global variable
    //        noOfEmployees = noOfRecords();
    //        
    //        // Create a dyanamically allocated array of Employee | Store its address into the global variable
    //        employees = new Employee[noOfEmployees];

    //        // In a loop load the employee records from the file into the dynamic array.
    //        for (int j = 0; j < noOfEmployees; j++) {
    //            cnt += load(employees[j]); 
    //        }
    //      
    //        // If the number of the records does not match the number of reads
    //        if (cnt != noOfEmployees) {
    //            cout << "Error: incorrect number of records read; the data is possibly corrupted";
    //        }
    //        else {
    //            ok = true;
    //        }

    //        closeFile();
    //    }

    //    else {
    //        cout << "Could not open data file: " << DATAFILE << endl;
    //    }
    //    return ok;
    //}
    
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE))
        {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees]; 

            while (i < noOfEmployees)
            {
                ok = load(employees[i]); // ok will become true everytime this loop happens.
                i++;
            }
            if (i != noOfEmployees)
            {
                ok = false;
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            // else ok = true;
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        closeFile();
        return ok;
    }



    // TODO: Implementation for the display functions go here
    
    // 1. receives a constant reference to an Employee object as a parameter and prints it
    // ex. 529967,80084.40,Abraham Simpson -> NUMBER: NAME, SALARY<NEWLINE>
    void display(const Employee& employees) { 
        cout << employees.m_empNo << ": " << employees.m_name << ", " << employees.m_salary << endl;
    }

    // 2. receives no parameters
    void display() {
        // print to the screen
        cout << "Employee Salary report, sorted by employee number\n"
             << "no- Empno, Name, Salary\n"
             << "------------------------------------------------"
             << endl;
        
        // sort the array
        sort();
        
        // iterate over the sorted array an print each employee in the format
        // ex. 1- 117493: Bumblebee Man, 43554.1
        for (int i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }


    // TODO: Implementation for the deallocateMemory function goes here
    // 1) employees.m_name = new char[len]   2) employees = new Employee[noOfEmployees]; 
    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;   // 1) delete the employees name of each struct
        }
        delete[] employees; // 2)delete the employee struct
    }
}