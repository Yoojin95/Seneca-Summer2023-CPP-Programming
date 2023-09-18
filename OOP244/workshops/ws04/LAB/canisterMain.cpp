/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 1
// Version 1.0
// Description
// tester program
//
// Revision History
/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 8 2023
***********************************************************************/
#include <iostream>
#include "Canister.h"
using namespace std;
using namespace sdds;
void showCans(const char* title, const Canister* boxArray, int num = 1);
int main() {
    int i;
    Canister C[] = {
       Canister(),
       Canister(nullptr),
       Canister("Orange Juice"),
       Canister(40,30),
       Canister(20, 10, "Olive Oil"),
       // the smallest Canister height & diameter : 10.0 by 10.0 and the largest one can be 40 by 30
       Canister(9,20, "Bad ones"),  // bad ones
       Canister(20,9),              // bad ones
       Canister(41,20, "Bad ones"), // bad ones
       Canister(20,31, "Bad ones")  // bad ones
    };

    showCans("Five good ones and 4 bad ones:", C, 9);
    for (i = 5; i < 9; i++) C[i].clear(); // clear the Canister array C[5] to C[8]
    
    showCans("All good:", C, 9);

    C[5].setContent("Milk").pour(500);
    C[6].setContent("MilK");
    showCans("Milk canisters", &C[5], 2);

    C[6].pour(C[5]); // pour C[5]'s volume to C[6] -> C[5]=0 C[6)=500
    showCans("Poured one into another", &C[5], 2);

    showCans("Poured 800ccs into the empty canister", &C[5].pour(800), 1); // pour 800cc to empty C[5]
    C[6].pour(C[5]);

    showCans("Filled one with the milk from another", &C[5], 2); // ππ∑°

    showCans("Poured 1500ccs of Olive oil into Olive oil canister", &C[4].pour(1500), 1); // C[4]=1500
    C[5].pour(C[4]); // pour the C[4]'s volume to C[5]: C[4]=0, C[5]=1500
    
    showCans("Filled can of milk with olive oil", &C[4], 2); // π∫∏ª.. C[4] Canister(20, 10, "Olive Oil"),
    
    showCans("Poured too much into olive oil canister", &C[4].pour(1500), 1); // π∫∏ª¿Ã∞Ì
    for (i = 3; i < 9; i++) C[i].setContent(nullptr);
    
    showCans("All bad", &C[3], 6);
    
    return 0;
}
void showCans(const char* title, const Canister* canArray, int num) {
    cout << " " << title << endl;
    cout << " Capacity,  Dimensions            Volume     Content" << endl;
    cout << "------------------------------    ---------  ---------------------------" << endl;
    for (int i = 0; i < num; i++) {
        canArray[i].display() << endl;
    }
    cout << "------------------------------------------------------------------------" << endl << endl;
}
