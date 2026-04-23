#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus() const;
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
    int getId() const { return id; }

private:
    int id;
    int capacity;
    int reserved;

    int maxReservations() const;
};

FlightBooking::FlightBooking() {
    id = 0;
    capacity = 0;
    reserved = 0;
}

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

int findFlightIndex(FlightBooking bookings[], int id) {
    for (int i = 0; i < 10; ++i) {
        if (bookings[i].getId() == id) {
            return i;
        }
    }

    return -1;
}

int findFreeIndex(FlightBooking bookings[]) {
    for (int i = 0; i < 10; ++i) {
        if (bookings[i].getId() == 0) {
            return i;
        }
    }

    return -1;
}

void printSystemStatus(FlightBooking bookings[]) {
    bool hasFlights = false;

    for (int i = 0; i < 10; ++i) {
        if (bookings[i].getId() != 0) {
            bookings[i].printStatus();
            hasFlights = true;
        }
    }

    if (!hasFlights) {
        cout << "No flights in the system" << endl;
    }
}

int main() {
    FlightBooking bookings[10];

    printSystemStatus(bookings);

    string commandLine;
    while (getline(cin, commandLine)) {
        if (commandLine == "quit") {
            break;
        }

        istringstream commandStream(commandLine);
        string command;
        commandStream >> command;

        string errorMessage;

        if (command == "create") {
            int id = 0;
            int capacity = 0;
            commandStream >> id >> capacity;

            if (commandStream.fail() || id == 0) {
                errorMessage = "Cannot perform this operation";
            } else if (findFlightIndex(bookings, id) != -1) {
                errorMessage = "Cannot perform this operation: flight already exists";
            } else {
                int freeIndex = findFreeIndex(bookings);
                if (freeIndex == -1) {
                    errorMessage = "Cannot perform this operation: limit reached";
                } else {
                    bookings[freeIndex] = FlightBooking(id, capacity, 0);
                }
            }
        } else if (command == "delete") {
            int id = 0;
            commandStream >> id;

            int index = findFlightIndex(bookings, id);
            if (commandStream.fail() || index == -1) {
                errorMessage = "Cannot perform this operation: flight " + to_string(id) + " not found";
            } else {
                bookings[index] = FlightBooking();
            }
        } else if (command == "add") {
            int id = 0;
            int seats = 0;
            commandStream >> id >> seats;

            int index = findFlightIndex(bookings, id);
            if (commandStream.fail() || index == -1) {
                errorMessage = "Cannot perform this operation: flight " + to_string(id) + " not found";
            } else if (!bookings[index].reserveSeats(seats)) {
                errorMessage = "Cannot perform this operation: capacity reached";
            }
        } else if (command == "cancel") {
            int id = 0;
            int seats = 0;
            commandStream >> id >> seats;

            int index = findFlightIndex(bookings, id);
            if (commandStream.fail() || index == -1) {
                errorMessage = "Cannot perform this operation: flight " + to_string(id) + " not found";
            } else if (!bookings[index].cancelReservations(seats)) {
                errorMessage = "Cannot perform this operation: not enough reservations";
            }
        } else {
            errorMessage = "Cannot perform this operation";
        }

        if (!errorMessage.empty()) {
            cout << errorMessage << endl;
        }

        printSystemStatus(bookings);
    }

    return 0;
}
