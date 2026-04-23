#include <iostream>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus() const;

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity < 0 ? 0 : capacity;
    this->reserved = reserved;
}

void FlightBooking::printStatus() const {
    int percentage = capacity == 0 ? 0 : reserved * 100 / capacity;
    cout << "Flight " << id << " : "
         << reserved << "/" << capacity
         << " (" << percentage << "%) seats reserved" << endl;
}

int main() {
    int capacity = 0;
    int reserved = 0;

    cin >> capacity >> reserved;

    FlightBooking booking(1, capacity, reserved);
    booking.printStatus();

    return 0;
}
