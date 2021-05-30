//Flight.h
//ENSF 337 Spring 2020
//Final Project
//Heidi Toews (UCID 30094995)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "Seat.h"
#include "Passenger.h"

using namespace std;

#ifndef HeidiToewsFlightClass

#define HeidiToewsFlightClass

typedef vector<char> row;
typedef vector<row> matrix;

class Flight {
public:
    Flight(); //default constructor
    //PROMISES: Creates a matrix SeatMap with size 0, sets
    //          FlightNumber and FileName to "NULL", and creates
    //          a vector Passengers with size 0.

    void populateFlightFromFile (string filen);
    //REQUIRES: filen is a valid string. The first name, last name, and phone number of each passenger
    //          are each in a field of 20 characters. The seat for each passenger is in a field of 4
    //          characters.
    //PROMISES: Attempts to open a file with the name filen. If this fails, the program quits.
    //          If it succeeds, assigns the value of filen to FileName, and begins to read from
    //          the file. If the filght number, the number of rows, and the number of seats per
    //          row cannot be read, the program quits. Otherwise, the program resizes SeatMap to
    //          the correct number of rows and reats per row, setting each element to ' ' using
    //          seatEmpty. Then it reads the passenger data into Passengers, and calls reserveSeat
    //          to change the correct element in SeatMap.

    void showPassengers () const;
    //PROMISES: Displays the information for each passenger in a table. If the vector Passengers
    //          is empty (there are no passengers), displays "No Passengers Found."

    void showSeatMap () const;
    //PROMISES: Displays the seat map for the aircraft, with an 'X' in each seat that is taken.
    //          Displays row numbers down the left side and the letters corresponding to each
    //          column of seats accross the top.

    int reserveSeat(int row, int seat);
    //REQUIRES: row and seat are valid integers.
    //PROMISES: If the seat doesn't exist: returns 0 and prints "That seat doesn't exist.
    //          Please try again." If the seat is already taken: returns 0 and prints
    //          "That seat is already taken. Please choose another." If the seat is available:
    //          returns 1 and sets the corresponding element of SeatMap to 'X'.

    void seatEmpty(int row, int seat);
    //REQUIRES: row and seat are valid integers, and element [row][seat] of SeatMap exists.
    //PROMISES: Sets the value of SeatMap[row][seat] to ' ' (empty).

    void addPassenger ();
    //PROMISES: If the flight is full, warns the user and ends. If there are 5 or fewer
    //          seats available, warns the user and lists these seats. Prompts the user
    //          to enter a valid, unused passenger id for a new passenger, and requests
    //          first name, last name, phone number, and desired seat for the passenger.
    //          Adds this information to a new element of the Passengers vector and calls
    //          reserveSeat to reserve the passenger's chosen seat.

    void editPassenger ();
    //PROMISES: Prompts the user to enter the ID for an existing passenger, then brings
    //          the user to a menu, where they can choose to quit or which item (first name,
    //          last name, phone number, or seat) they would like to edit. Returns to this
    //          menu after each edit until the user chooses to quit, then returning to the
    //          main menu.

    void removePassenger ();
    //PROMISES: Prompts the user to enter the ID for an existing passenger, and removes
    //          that passengerr from the Passengers vector and call seatEmpty to remove
    //          their seat reservation from SeatMap.

    void saveInfo ();
    //PROMISES: Prompts the user to enter 'Y' or 'N' in response to whether they want to
    //          save the passenger data in FileName. If the user enters 'N', resturns to
    //          the main menu. If the user enters 'Y', opens the file and writes the
    //          information for each passenger to the file. Will also work if the user
    //          enters 'y' instead of 'Y' or 'n' instead of 'N'.

    int checkForValidID(string s) const;
    //REQUIRES: s is a valid string to be used as a passenger ID
    //PROMISES: Returns 2 if s is an invalid ID (contains non-numeric
    //          characters or is not 6 digits long), returns 1 if
    //          there is already a passenger with ID equal to s,
    //          and returns 0 if s is a valid ID that is not already in use.

    char getSeat (int row, int seat) { return SeatMap[row][seat]; }
    //REQUIRES: row and seat and valid integers, and SeatMap[row][seat] exists.
    //PROMISES: Returns the character in SeatMap[row][seat].

private:
    string FlightNumber;
    string FileName;
    matrix SeatMap;
    vector <Passenger> Passengers;
};

#endif