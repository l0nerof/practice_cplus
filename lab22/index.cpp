#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString() const;
    double toDouble() const;

private:
    int numerator;
    int denominator;
};

Fraction::Fraction(int numerator, int denominator) {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    this->numerator = numerator;
    this->denominator = denominator;
}

string Fraction::toString() const {
    if (numerator == 0) {
        return "0";
    }

    int absNumerator = abs(numerator);
    int wholePart = absNumerator / denominator;
    int remainder = absNumerator % denominator;
    string sign = numerator < 0 ? "-" : "";

    if (remainder == 0) {
        return sign + to_string(wholePart);
    }

    if (wholePart == 0) {
        return sign + to_string(absNumerator) + "/" + to_string(denominator);
    }

    return sign + to_string(wholePart) + " " +
           to_string(remainder) + "/" + to_string(denominator);
}

double Fraction::toDouble() const {
    return static_cast<double>(numerator) / denominator;
}

string formatDecimal(double value) {
    ostringstream out;

    if (value == static_cast<long long>(value)) {
        out << fixed << setprecision(1) << value;
        return out.str();
    }

    out << fixed << setprecision(10) << value;
    string text = out.str();

    while (!text.empty() && text.back() == '0') {
        text.pop_back();
    }

    if (!text.empty() && text.back() == '.') {
        text.push_back('0');
    }

    return text;
}

int main() {
    int num = 0;
    int den = 1;
    char slash = '/';
    string input;

    getline(cin, input);

    istringstream parser(input);
    parser >> num >> slash >> den;

    Fraction fraction(num, den);

    cout << fraction.toString() << " is "
         << formatDecimal(fraction.toDouble())
         << " in decimal" << endl;

    return 0;
}
