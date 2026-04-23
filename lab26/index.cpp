#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class IPAddress {
public:
    IPAddress(const string &address);
    IPAddress(const IPAddress &other);
    virtual void print() const;
    virtual ~IPAddress() {}

protected:
    string address;
};

class IPAddressChecked : public IPAddress {
public:
    IPAddressChecked(const string &address);
    IPAddressChecked(const IPAddressChecked &other);
    void print() const override;

private:
    bool isCorrect;
    bool validate() const;
};

IPAddress::IPAddress(const string &address) {
    this->address = address;
}

IPAddress::IPAddress(const IPAddress &other) {
    address = other.address;
}

void IPAddress::print() const {
    cout << address;
}

IPAddressChecked::IPAddressChecked(const string &address) : IPAddress(address) {
    isCorrect = validate();
}

IPAddressChecked::IPAddressChecked(const IPAddressChecked &other)
    : IPAddress(other) {
    isCorrect = other.isCorrect;
}

bool IPAddressChecked::validate() const {
    istringstream stream(address);
    string part;
    int count = 0;

    while (getline(stream, part, '.')) {
        if (part.empty()) {
            return false;
        }

        for (char ch : part) {
            if (!isdigit(static_cast<unsigned char>(ch))) {
                return false;
            }
        }

        int value = stoi(part);
        if (value < 0 || value > 255) {
            return false;
        }

        ++count;
    }

    return count == 4;
}

void IPAddressChecked::print() const {
    IPAddress::print();
    cout << " - " << (isCorrect ? "Correct" : "Not Correct");
}

int main() {
    string firstInput;
    string secondInput;
    string thirdInput;

    getline(cin, firstInput);
    getline(cin, secondInput);
    getline(cin, thirdInput);

    IPAddress first(firstInput);
    IPAddressChecked second(secondInput);
    IPAddressChecked third(thirdInput);

    IPAddress *addresses[3] = {&first, &second, &third};

    for (int i = 0; i < 3; ++i) {
        addresses[i]->print();
        cout << endl;
    }

    return 0;
}
