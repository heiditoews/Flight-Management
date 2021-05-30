//Passenger.cpp
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

Passenger::Passenger () {
    FirstName = "NULL";
    LastName = "NULL";
    Phone = "NULL";
    SeatP.setRow(0);
    SeatP.setSeat('0');
    ID = "NULL";
}

void Passenger::setFirstName (string s) {
    while(s.at(0) == ' ')
        s.erase(0, 1);

    s.at(0) = toupper(s.at(0));

    int i = 1;
    while (i < (int)s.length()) {
        if (s.at(i) == ' ') {
            break;
        } else {
            s.at(i) = tolower(s.at(i));
        }
        i++;
    }

    while (i < (int)s.length() - 1) {
        if (s.at(i+1) == ' ' && s.at(i) == ' ') {
            s.erase(i, 1);
            i--;
        } else {
            break;
        }
        i++;
    }

    if (i < (int)s.length() - 1) {
        if (s.at(i+1) == ' ' && s.at(i) == ' ') {
            while (i < (int)s.length()) {
                s.erase(i, 1);
            }
        } else {
            i++;
            s.at(i) = toupper(s.at(i));
            i++;
            while (i < (int)s.length()) {
                if (s.at(i) == ' ')
                    break;
                else
                    s.at(i) = tolower(s.at(i));
                i++;
            }
        }
    }

    while (i < (int)s.length()) {
        if (s.at(i) == ' ') {
            s.erase(i, 1);
            i--;
        }
        i++;
    }
    FirstName = s;
}

void Passenger::setLastName (string s) {
    while(s.at(0) == ' ')
        s.erase(0, 1);

    s.at(0) = toupper(s.at(0));

    int i = 1;
    while (i < (int)s.length()) {
        if (s.at(i) == ' ') {
            break;
        } else {
            s.at(i) = tolower(s.at(i));
        }
        i++;
    }

    while (i < (int)s.length() - 1) {
        if (s.at(i+1) == ' ' && s.at(i) == ' ') {
            s.erase(i, 1);
            i--;
        } else {
            break;
        }
        i++;
    }

    if (i < (int)s.length() - 1) {
        if (s.at(i+1) == ' ' && s.at(i) == ' ') {
            while (i < (int)s.length()) {
                s.erase(i, 1);
            }
        } else {
            i++;
            s.at(i) = toupper(s.at(i));
            i++;
            while (i < (int)s.length()) {
                if (s.at(i) == ' ')
                    break;
                else
                    s.at(i) = tolower(s.at(i));
                i++;
            }
        }
    }

    while (i < (int)s.length()) {
        if (s.at(i) == ' ') {
            s.erase(i, 1);
            i--;
        }
        i++;
    }

    LastName = s;
}

void Passenger::setID (string id) {
    for (int i = 0; i < (int)id.length(); i++) {
        if (id.at(i) == ' ') {
            id.erase(i, 1);
            i--;
        }
    }
    ID = id;
}

void Passenger::formatPhone () {
    for (int i = 0; i < (int)Phone.length(); i++) {
        if (Phone.at(i) < 48 || Phone.at(i) > 57 || i >= 10) {
            Phone.erase(i, 1);
            i--;
        }
    }
    if ((int)Phone.length() < 10) {
        for (int i = Phone.length(); i < 10; i++) {
            Phone.append("0");
        }
    }
    Phone.insert(3, 1, '-');
    Phone.insert(7, 1, '-');
}