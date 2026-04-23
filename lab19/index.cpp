#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string password;
    getline(cin, password);

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (char ch : password) {
        unsigned char current = static_cast<unsigned char>(ch);

        if (isupper(current)) {
            hasUpper = true;
        } else if (islower(current)) {
            hasLower = true;
        } else if (isdigit(current)) {
            hasDigit = true;
        } else {
            hasSpecial = true;
        }
    }

    bool isValid = true;

    if (password.length() < 8) {
        cout << "The password must be 8 characters long" << endl;
        isValid = false;
    }

    if (!hasUpper) {
        cout << "The password must have at least one upper case letter" << endl;
        isValid = false;
    }

    if (!hasLower) {
        cout << "The password must have at least one lower case letter" << endl;
        isValid = false;
    }

    if (!hasDigit) {
        cout << "The password must have at least one digit" << endl;
        isValid = false;
    }

    if (!hasSpecial) {
        cout << "The password must have at least one special character" << endl;
        isValid = false;
    }

    if (isValid) {
        cout << "The password is valid" << endl;
    }

    return 0;
}
