//Passenger.h
//ENSF 337 Spring 2020
//Final Project
//Heidi Toews (UCID 30094995)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "Seat.h"

#ifndef HeidiToewsPassengerClass

#define HeidiToewsPassengerClass

class Passenger {
public:
    Passenger(); //default constructor
    //PROMISES: Sets each string variable of the class (FirstName,
    //          LastName, Phone, ID) to "NULL". Sets the RowS and
    //          SeatS variables of the Seat object to 0 and '0' respectively.

    void formatPhone ();
    //REQUIRES: Phone is a valid string with at least one numeric character.
    //PROMISES: Formats Phone to match XXX-XXX-XXXX, removing all non-numeric
    //          characters before adding dashes in the appropriate places. If
    //          Phone does not contain 10 numeric characters, '0' is appended
    //          to Phone until it contains 10 numeric characters.

    void setFirstName (string s);
    //REQUIRES: s is a valid string. If the name has a second part, there is only
    //          one space between them. The name has no more than two parts.
    //PROMISES: Ensures the first character of s is capitalized and the following
    //          characters (except the first character of the middle name, if there
    //          is one) are not, and assigns the value of s to FirstName.

    void setLastName (string s);
    //REQUIRES: s is a valid string. If the name has a second part, there is only
    //          one space between them. The name has no more than two parts.
    //PROMISES: Ensures the first character of s is capitalized and the following
    //          characters are not, (except if there is a second part of the last
    //          middle name; then the first character of it is capitalized) and
    //          assigns the value of s to LastName.

    void setPhone (string s) { Phone = s; }
    //REQUIRES: s is a valid string.
    //PROMISES: Assigns the value of s to Phone.

    void setID (string id);
    //REQUIRES: id is a valid string.
    //PROMISES: Assigns the value of id to ID and removes any spaces.

    void setSeatR (int r) { SeatP.setRow(r); }
    //REQUIRES: r is greater than 0 and less than or equal
    //          to the total number of rows in the aircraft.
    //PROMISES: assigns the value of r to RowS in SeatP.

    void setSeatS (char c) { SeatP.setSeat(c); }
    //REQUIRES: c is an uppercase alphabetic character that is not
    //          greater than the maximum number of columns of seats
    //          in the aircraft (for example, if there are 6 columns
    //          of seats, c can only be A, B, C, D, E, or F).
    //PROMISES: Assigns the value of c to SeatS in SeatP.

    string getFirstName () const { return FirstName; }
    //PROMISES: Returns to value of FirstName.

    string getLastName () const { return LastName; }
    //PROMISES: Returns the value of LastName.

    string getPhone () const { return Phone; }
    //PROMISES: Returns the value of Phone.

    string getID () const { return ID; }
    //PROMISES: Returns the value of ID.

    int getSeatR () const { return SeatP.getRow(); }
    //PROMISES: Returns the value of RowS in SeatP.

    char getSeatS () const { return SeatP.getSeat(); }
    //PROMISES: Returns the value of SeatS in SeatP.

private:
    string FirstName;
    string LastName;
    string Phone;
    string ID;
    Seat SeatP;
};

#endif