//FlightManagement.cpp
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
#include "Flight.h"

using namespace std;

void pressEnter ();
//PROMISES: Prompts the user to press enter and waits for them to do so.

void cleanStandardInputStream ();
//PROMISES: Removes any characters remaining in the standard input stream.

int toInt (string s);
//REQUIRES: s is a valid string.
//PROMISES: Converts the numeric digits of s to an integer with digits in the
//          same order. Ignores non-numeric characters.

string toString (int i);
//REQUIRES: i is positive.
//PROMISES: Converts i to a string of digits. For example, if i = 123, the
//          function would return a string "123".

void displayHeader ();
//PROMISES: Displays the header of the program.

string copyToString (char * s);
//REQUIRES: s is a valid c-string.
//PROMISES: Copies the characters in s into a string and returns the string.

void emptyArray (char * s);
//REQUIRES: s is a valid c-string.
//PROMISES: Replaces every character in s with a '\0'.

void pressEnter() {
    cout << "\n<<< Press Enter to Continue >>>\n";
    cin.get();
}

void cleanStandardInputStream () {
    int leftover;
    leftover = cin.get();
    while (leftover !='\n' && leftover != EOF) {
        leftover = cin.get();
    }
}

int toInt (string s) {
    int integer = 0;
    for (int j = 0; j < (int)s.length(); j++) {
        if (s.at(j) >= 48 && s.at(j) <= 57)
            integer = integer*10 + s.at(j) - 48;
    }
    return integer;
}

string toString (int i) {
    string str = "X";
    char ch;
    //int n = i;
    if (i % 10 == i) {
        ch = i + 48;
        str.at(0) = ch;
    } else {
        ch = i % 10 + 48;
        str.append(&ch);
        i -= i % 10;
        i = i/10;
        ch = i + 48;
        str.at(0) = ch;
    }
    return str;
}

void displayHeader () {
    cout << "\nVersion: 1.0";
    cout << "\nTerm Project - Flight Management Program in C++";
    cout << "\nProduced by: Heidi Toews\n\n";
    pressEnter();
}

int menu () {
    string c;
    int choice;
    cout << "\nPlease select one of the following options: ";
    cout << "\n1. Display Flight Seat Map.";
    cout << "\n2. Display Passengers Information.";
    cout << "\n3. Add a New Passenger.";
    cout << "\n4. Edit an Existing Passenger.";
    cout << "\n5. Remove an Existing Passenger.";
    cout << "\n6. Save Data.";
    cout << "\n7. Quit.";
    cout << "\n\nEnter your choice: (1, 2, 3, 4, 5, 6 or 7) ";
    cin >> c;
    choice = toInt(c);
    cleanStandardInputStream();
    while (choice < 1 || choice > 7) {
        cout << "\nInvalid selection. Please try again. ";
        cin >> c;
        choice = toInt(c);
        cleanStandardInputStream();
    }
    return choice;
}

string copyToString (char * s) {
    string result = "";
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') {
        } else if (i >= (int)result.length()) {
            result.append(1, s[i]);
        } else {
            result[i] = s[i];
        }
    }
    return result;
}

void emptyArray (char * s) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = '\0';
    }
}