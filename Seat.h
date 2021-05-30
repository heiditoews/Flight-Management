//Seat.h
//ENSF 337 Spring 2020
//Final Project
//Heidi Toews (UCID 30094995)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

#ifndef HeidiToewsSeatClass

#define HeidiToewsSeatClass

class Seat {
public:
    void setRow (int r) { RowS = r; }
    //REQUIRES: r is greater than 0 and less than or equal
    //          to the total number of rows in the aircraft.
    //PROMISES: assigns the value of r to RowS.

    void setSeat (char c) { SeatS = c; }
    //REQUIRES: c is an uppercase alphabetic character that is not
    //          greater than the maximum number of columns of seats
    //          in the aircraft (for example, if there are 6 columns
    //          of seats, c can only be A, B, C, D, E, or F).
    //PROMISES: Assigns the value of c to SeatS.

    int getRow () const { return RowS; }
    //PROMISES: returns the value of RowS.

    char getSeat () const { return SeatS; }
    //PROMISES: returns the value of SeatS.

private:
    int RowS;
    char SeatS;
};

#endif