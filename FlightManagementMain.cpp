//FilghtManagementMain.cpp
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

void displayHeader ();
int menu ();
void pressEnter ();

int main () {
    Flight f;
    f.populateFlightFromFile("flight_info.txt");
    displayHeader();
    int choice;
    while ((choice = menu())) {
        switch (choice) {
            case 1:
                f.showSeatMap();
                pressEnter();
                break;
            case 2:
                f.showPassengers();
                pressEnter();
                break;
            case 3:
                f.addPassenger();
                break;
            case 4:
                f.editPassenger();
                break;
            case 5:
                f.removePassenger();
                break;
            case 6:
                f.saveInfo();
                break;
            case 7:
                exit(1);
                break;
        }
    }
    return 0;
}