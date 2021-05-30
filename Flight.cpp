//Flight.cpp
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

int toInt (string s);
string toString (int i);
void cleanStandardInputStream ();
string copyToString (char * s);
void emptyArray (char * s);

Flight::Flight () {
    SeatMap.resize(0);
    FlightNumber = "NULL";
    Passengers.resize(0);
}

int Flight::checkForValidID(string s) const {
    int result = 0;
    for (int i = 0; i < (int)Passengers.size(); i++) {
        string c = Passengers.at(i).getID();
        if (c.compare(s) == 0) {
            result = 1;
            break;
        }
    }
    for (int i = 0; i < (int)s.length(); i++) {
        if (s.at(i) < 48 || s.at(i) > 57) {
            result = 2;
            break;
        }
    }
    if (s.length() != 5)
        result = 2;
    return result;
}

void Flight::showSeatMap () const {
    int row = SeatMap.size();
    int col = SeatMap.at(0).size();
    cout << "\n" << setw(4 + (col*4)/2 + 17/2) << right << "Aircraft Seat Map";
    cout << "\n  ";
    for (int j = 0; j < col; j++) {
        char ch = j+65;
        cout << "   " << ch;
    } //print letters across the top
    cout << "\n";
    for (int i = 0; i < row; i++) {
        cout << "   +";
        for (int j = 0; j < col; j++) {
            cout << "---+";
        } //print the lines separating rows
        cout << "\n" << setw(3) << left << i+1 << "|"; //print the row number at the beginning of each row
        for (int j = 0; j < col; j++) {
            cout << " " << SeatMap[i][j] << " |";
        } //print 'X' if the seat is taken and print the lines between columns
        cout << "\n";
    } //print a row of seats for every row in the plane
    cout << "   +";
    for (int j = 0; j < col; j++) {
        cout << "---+";
    } //print the last line at the end of the map
    cout << "\n";
}

void Flight::showPassengers () const {
    cout << "\n" << setw(79/2 + 10) << right << "Passenger Information";
    cout << "\n" << setw(20) << left << "First Name" << setw(20) << left << "Last Name";
    cout << setw(20) << left << "Phone" << setw(7) << left << "Row";
    cout << setw(7) << left << "Seat" << setw(7) << left << "ID";
    cout << "\n-------------------------------------------------------------------------------\n";

    if (Passengers.size() == 0) {
        cout << setw(79/2 + 10) << right << "No Passengers Found.";
        cout << "\n-------------------------------------------------------------------------------\n";
    }

    for (int i = 0; i < (int)Passengers.size(); i++) {
        cout << setw(20) << left << Passengers.at(i).getFirstName() << setw(20) << left << Passengers.at(i).getLastName();
        cout << setw(20) << left << Passengers.at(i).getPhone() << setw(7) << left << Passengers.at(i).getSeatR();
        cout << setw(7) << left << Passengers.at(i).getSeatS() << setw(7) << left << Passengers.at(i).getID();
        cout << "\n-------------------------------------------------------------------------------\n";
    }
}

void Flight::addPassenger () {
    int seats = 0, count = 0;
    for (int i = 0; i < (int)SeatMap.size(); i++) {
        for (int j = 0; j < (int)SeatMap.at(i).size(); j++) {
            if (SeatMap[i][j] == 'X')
                seats++;
            count++;
        }
    }
    if (count == seats) {
        cout << "\nNo available seats, flight is full.\n";
    } else {
        if (count - seats <= 5) {
            cout << "\nWarning: There are " << count - seats << " left: ";
            for (int i = 0; i < (int)SeatMap.size(); i++) {
                for (int j = 0; j < (int)SeatMap.at(i).size(); j++) {
                    if (SeatMap[i][j] == ' ')
                        cout << i + 1 << (char)(j+65) << " ";
                }
            }
        }
        string id, fn, ln, ph, row;
        int r, j = 0;
        char s;
        Passengers.resize(Passengers.size() + 1);
        while (Passengers.at(j).getSeatR() != 0) {
            j++;
        }
        cout << "\nPlease enter the passenger id: ";
        cin >> id;
        cleanStandardInputStream ();
        int check = checkForValidID(id);
        while (1) {
            if (check == 0) {
            break;
            } else if (check == 1) {
                cout << "\nThat id is already in use. Please choose another: ";
                cin >> id;
                cleanStandardInputStream ();
                check = checkForValidID(id);
            } else if (check == 2) {
                cout << "\nYou have entered an invalid id. Please enter a 5 digit id of numbers only and no spaces: ";
                cin >> id;
                cleanStandardInputStream ();
                check = checkForValidID(id);
            }
        }
        Passengers.at(j).setID(id);

        cout << "\nPlease enter the passenger first name (and middle name, if applicable): ";
        getline(cin, fn);
        while (fn.length() == 0) {
            cout << "\nYou have not entered anything. Please enter the passenger's first name: ";
            getline(cin, fn);
        }
        Passengers.at(j).setFirstName(fn);
        cout << "\nPlease enter the passenger last name: ";
        getline(cin, ln);
        while (ln.length() == 0) {
            cout << "\nYou have not entered anything. Please enter the passenger's last name: ";
            getline(cin, ln);
        }
        Passengers.at(j).setLastName(ln);
        cout << "\nPlease enter the passenger phone number: ";
        getline(cin, ph);
        while (ph.length() == 0) {
            cout << "\nYou have not entered anything. Please enter the passenger's phone number: ";
            getline(cin, ph);
        }

        while (1) {
            for (int i = 0; i < (int)ph.length(); i++) {
                if (ph.at(i) >= 48 && ph.at(i) <= 57) {
                } else if (ph.at(i) != '(' && ph.at(i) != ')' && ph.at(i) != '-' && ph.at(i) != ' ') {
                    cout << "\nInvalid phone number. Please enter a valid phone number: ";
                    getline(cin, ph);
                    i = 0;
                } else if (1) {
                    break;
                }
            }
            Passengers.at(j).setPhone(ph);
            Passengers.at(j).formatPhone();
            ph = Passengers.at(j).getPhone();
            if (ph.length() != 12) {
                cout << "\nInvalid phone number. Please enter a valid phone number: ";
                getline(cin, ph);
            } else {
                break;
            }
        }
        cout << "\nEnter the passenger's desired row: ";
        cin >> row;
        r = toInt(row);
        cleanStandardInputStream ();
        cout << "\nEnter the passenger's desired seat: ";
        s = cin.get();
        s = toupper(s);
        cleanStandardInputStream ();
        int seat = s - 65;
        while (reserveSeat(r - 1, seat) == 0) {
            cout << "\nEnter the passenger's desired row: ";
            cin >> row;
            r = toInt(row);
            cleanStandardInputStream ();
            cout << "\nEnter the passenger's desired seat: ";
            s = cin.get();
            s = toupper(s);
            seat = s - 65;
            cleanStandardInputStream ();
        }
        Passengers.at(j).setSeatR(r);
        Passengers.at(j).setSeatS(s);
    }
}

void Flight::editPassenger() {
    string id;
    cout << "\nEnter the id of the passenger you wish to edit, or \"X\" to quit: ";
    cin >> id;
    if (id.compare("X") == 0) {
    } else {
        int location = -1, choice;
        string str, c;
        for (int j = 0; j < (int)Passengers.size(); j++) {
            str = Passengers.at(j).getID();
            if (str.compare(id) == 0) {
                location = j;
                break;
            }
        }
        while (location == -1) {
            cout << "\nYou have entered an invalid id. Please try again. ";
            cin >> id;
            if (id.compare("X") == 0) {
                break;
            }
            for (int j = 0; j < (int)Passengers.size(); j++) {
                str = Passengers.at(j).getID();
                if (str.compare(id) == 0) {
                    location = j;
                    break;
                }
            }
        }
        if (id.compare("X")) {
            while (1) {
                cout << "\nPlease choose which item you would like to edit:";
                cout << "\n1. Passenger's First Name (currently " << Passengers.at(location).getFirstName() << ")";
                cout << "\n2. Passenger's Last Name (currently " << Passengers.at(location).getLastName() << ")";
                cout << "\n3. Passenger's Phone Number (currently " << Passengers.at(location).getPhone() << ")";
                cout << "\n4. Passenger's Seat (currently " << Passengers.at(location).getSeatR() << Passengers.at(location).getSeatS() << ")";
                cout << "\n5. Quit";
                cout << "\n\nEnter your choice: (1, 2, 3, 4, or 5) ";
                cin >> c;
                choice = toInt(c);
                cleanStandardInputStream();
                while (choice < 1 || choice > 5) {
                    cout << "\nInvalid selection. Please try again. ";
                    cin >> c;
                    choice = toInt(c);
                    cleanStandardInputStream();
                }
                string input = "NULL";
                if (choice == 1) {
                    cout << "\nEnter the passenger's new first name: ";
                    getline(cin, input);
                    while (input.length() == 0) {
                        cout << "\nYou have not entered anything. Please enter the passenger's first name: ";
                        getline(cin, input);
                    }
                    Passengers.at(location).setFirstName(input);
                } else if (choice == 2) {
                    cout << "\nEnter the passenger's new last name: ";
                    getline(cin, input);
                    while (input.length() == 0) {
                        cout << "\nYou have not entered anything. Please enter the passenger's last name: ";
                        getline(cin, input);
                    }
                    Passengers.at(location).setLastName(input);
                } else if (choice == 3) {
                    cout << "\nEnter the passenger's new phone number: ";
                    getline(cin, input);
                    while (input.length() == 0) {
                        cout << "\nYou have not entered anything. Please enter the passenger's phone number: ";
                        getline(cin, input);
                    }
                    Passengers.at(location).setPhone(input);
                    Passengers.at(location).formatPhone();
                } else if (choice == 4) {
                    int row;
                    char s;
                    string str;
                    cout << "\nEnter the passenger's desired row: ";
                    cin >> str;
                    row = toInt(str);
                    cleanStandardInputStream ();
                    cout << "\nEnter the passenger's desired seat: ";
                    s = cin.get();
                    s = toupper(s);
                    int seat = s - 65;
                    cleanStandardInputStream ();
                    while (reserveSeat(row - 1, seat) == 0) {
                        cout << "\nEnter the passenger's desired row: ";
                        cin >> row;
                        cleanStandardInputStream ();
                        cout << "\nEnter the passenger's desired seat: ";
                        s = cin.get();
                        s = toupper(s);
                        seat = s - 65;
                        cleanStandardInputStream ();
                    }
                    seatEmpty(Passengers.at(location).getSeatR()-1, Passengers.at(location).getSeatS()-65);
                    Passengers.at(location).setSeatR(row);
                    Passengers.at(location).setSeatS(s);
                } else if (choice == 5) {
                    break;
                }
            }
        }
    }
}

void Flight::removePassenger () {
    string id, str;
    cout << "\nEnter the id of the passenger you wish to remove, or X to quit without removing: ";
    cin >> id;
    cleanStandardInputStream();
    if (id.compare("X") == 0) {
    } else {
        int location = -1;
        for (int j = 0; j < (int)Passengers.size(); j++) {
            str = Passengers.at(j).getID();
            if (str.compare(id) == 0) {
                location = j;
                break;
            }
        }
        while (location == -1) {
            cout << "\nYou have entered an invalid id. Please try again. ";
            cin >> id;
            cleanStandardInputStream();
            if (id.compare("X") == 0) {
                break;
            } else {
                for (int j = 0; j < (int)Passengers.size(); j++) {
                    str = Passengers.at(j).getID();
                    if (str.compare(id) == 0) {
                        location = j;
                        break;
                    }
                }
            }
        }
        if (id.compare("X") != 0) {
            seatEmpty(Passengers.at(location).getSeatR()-1, Passengers.at(location).getSeatS()-65);

            for (int i = location; i < (int)Passengers.size() - 1; i++) {
                Passengers.at(i).setFirstName(Passengers.at(i+1).getFirstName());
                Passengers.at(i).setLastName(Passengers.at(i+1).getLastName());
                Passengers.at(i).setPhone(Passengers.at(i+1).getPhone());
                Passengers.at(i).setID(Passengers.at(i+1).getID());
                Passengers.at(i).setSeatR(Passengers.at(i+1).getSeatR());
                Passengers.at(i).setSeatS(Passengers.at(i+1).getSeatS());
            }
            Passengers.resize(Passengers.size() - 1);
        }
    }
}

void Flight::saveInfo () {
    ofstream flightData (FileName);
    char tab = 9, answer;
    if (flightData.fail()) {
        cerr << "\nCould not open file.\n";
        exit(1);
    }

    cout << "\nDo you want to save the data in \"" << FileName << "\"? Please answer <Y or N> ";
    answer = cin.get();
    cleanStandardInputStream ();
    while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n') {
        cout << "\nYou have entered an invalid answer. Please try again. ";
        answer = cin.get();
        cleanStandardInputStream ();
    }

    if (answer == 'Y' || answer == 'y') {
        flightData << FlightNumber << tab << SeatMap.size() << tab << SeatMap.at(0).size() << "\n";
        for (int i = 0; i < (int)Passengers.size(); i++) {
            string seat, s = "0";
            seat = toString(Passengers.at(i).getSeatR());
            s.at(0) = Passengers.at(i).getSeatS();
            seat.append(s);
            flightData << setw(20) << left << Passengers.at(i).getFirstName() << setw(20) << left << Passengers.at(i).getLastName();
            flightData << setw(20) << left << Passengers.at(i).getPhone() << setw(4) << left << seat;
            flightData << setw(5) << left << Passengers.at(i).getID() << "\n";
        }
        flightData << EOF;
        cout << "\nAll the data in the passenger list was saved into the file \"" << FileName << "\".\n";
    }

    flightData.close();
}

void Flight::populateFlightFromFile (string filen) {
    ifstream flightData (filen);
    if (flightData.fail()) {
        cerr << "\nCould not open file.\n";
        exit(1);
    }
    FileName = filen;
    flightData >> FlightNumber;
    string rows = "0", col = "0";
    flightData >> rows;
    flightData >> col;
    if (!FlightNumber.compare("NULL") || !rows.compare("0") || !col.compare("0")) {
        cerr << "\nInvalid file.";
        exit(1);
    }
    int r = toInt(rows), c = toInt(col);

    SeatMap.resize(r); //resize seatmap to the correct number of rows
    for (int i = 0; i < r; i++) {
        SeatMap.at(i).resize(c); //resize each element of seatmap to the correct number of columns
        for (int j = 0; j < c; j++) {
            seatEmpty(i, j); //set each seat to empty
        }
    }
    int p = 0;
    while (!flightData.eof()) {
        string str, str2 = "0", str3 = "0";
        char s[22], a[22], b[22];
        flightData.read(&s[0], 20);
        str = copyToString(s);
        if (str.at(0) == '-' && str.at(1) == '1') {
            break;
        }
        Passengers.resize(Passengers.size() + 1);
        /*getline (flightData, str);
        if (str.length() < 5)
            getline (flightData, str);*/

        //int i = 0, j = 0;
        //if (str.compare("-1") == 0)
            //break;

        Passengers.at(p).setFirstName(str);

        emptyArray(s);
        flightData.read(&s[0], 20);
        str = copyToString(s);
        Passengers.at(p).setLastName(str);

        emptyArray(s);
        flightData.read(&s[0], 20);
        str = copyToString(s);
        Passengers.at(p).setPhone(str);
        Passengers.at(p).formatPhone();

        emptyArray(s);
        flightData.read(&s[0], 3);

        str = copyToString(s);
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ') {
            } else if (s[i] >= 48 && s[i] <= 57) {
                a[i] = s[i];
            } else {
                b[0] = s[i];
            }
        }
        str = copyToString(a);
        int row = toInt(str);
        char seat = b[0];
        reserveSeat(row - 1, seat - 65);
        Passengers.at(p).setSeatR(row);
        Passengers.at(p).setSeatS(seat);

        emptyArray(s);
        emptyArray(a);
        emptyArray(b);
        char ch;
        int i = 0;
        while (1) {
            ch = flightData.get();
            if (ch != '\n' && ch != EOF)
                s[i] = ch;
            else
                break;
            i++;
        }
        str = copyToString(s);
        Passengers.at(p).setID(str);
        emptyArray(s);

        p++;
    } //populate each passenger to the values found in the file
    flightData.close();
}

int Flight::reserveSeat (int row, int seat) {
    if (row >= (int)SeatMap.size() || seat >= (int)SeatMap.at(0).size() || row < 0 || seat < 0) {
        cout << "\nThat seat doesn't exist. Please try again. \n";
        return 0;
    } else if (SeatMap[row][seat] == ' ') {
        SeatMap[row][seat] = 'X';
        return 1;
    } else {
        cout << "\nThat seat is already taken. Please choose another. \n";
        return 0;
    }
}

void Flight::seatEmpty (int row, int seat) {
    SeatMap[row][seat] = ' ';
}