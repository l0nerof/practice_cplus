#include <iostream>
#include <limits>
#include <sstream>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus() const;
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);

private:
    int id;
    int capacity;
    int reserved;

    int maxReservations() const;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity < 0 ? 0 : capacity;
    this->reserved = reserved;

    if (this->reserved < 0) {
        this->reserved = 0;
    }

    if (this->reserved > maxReservations()) {
        this->reserved = maxReservations();
    }
}

int FlightBooking::maxReservations() const {
    return capacity * 105 / 100;
}

void FlightBooking::printStatus() const {
    int percentage = capacity == 0 ? 0 : reserved * 100 / capacity;
    cout << "Flight " << id << " : "
         << reserved << "/" << capacity
         << " (" << percentage << "%) seats reserved" << endl;
}

bool FlightBooking::reserveSeats(int number_of_seats) {
    if (number_of_seats < 0 || reserved + number_of_seats > maxReservations()) {
        return false;
    }

    reserved += number_of_seats;
    return true;
}

bool FlightBooking::cancelReservations(int number_of_seats) {
    if (number_of_seats < 0 || number_of_seats > reserved) {
        return false;
    }

    reserved -= number_of_seats;
    return true;
}

int main() {
    int capacity = 0;
    int reserved = 0;

    cin >> capacity >> reserved;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    FlightBooking booking(1, capacity, reserved);
    booking.printStatus();

    string commandLine;
    while (getline(cin, commandLine)) {
        if (commandLine == "quit") {
            break;
        }

        istringstream commandStream(commandLine);
        string command;
        int value = 0;

        commandStream >> command >> value;

        bool success = false;
        if (command == "add" && !commandStream.fail()) {
            success = booking.reserveSeats(value);
        } else if (command == "cancel" && !commandStream.fail()) {
            success = booking.cancelReservations(value);
        }

        if (success) {
            booking.printStatus();
        } else {
            cout << "Cannot perform this operation" << endl;
        }
    }

    return 0;
}
