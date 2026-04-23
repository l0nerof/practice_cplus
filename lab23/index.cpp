#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a == 0 ? 1 : a;
}

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    string toOriginalString() const;
    double toDouble() const;
    Fraction plus(Fraction that);
    Fraction minus(Fraction that);
    Fraction times(Fraction that);
    Fraction by(Fraction that);

private:
    int numerator;
    int denominator;
    void reduce();
};

Fraction::Fraction(int numerator, int denominator) {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    this->numerator = numerator;
    this->denominator = denominator;
}

void Fraction::reduce() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

string Fraction::toOriginalString() const {
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

string Fraction::toString() {
    reduce();

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

Fraction Fraction::plus(Fraction that) {
    int num = numerator * that.denominator + that.numerator * denominator;
    int den = denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::minus(Fraction that) {
    int num = numerator * that.denominator - that.numerator * denominator;
    int den = denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::times(Fraction that) {
    int num = numerator * that.numerator;
    int den = denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::by(Fraction that) {
    int num = numerator * that.denominator;
    int den = denominator * that.numerator;
    return Fraction(num, den);
}

Fraction readFraction() {
    int num = 0;
    int den = 1;
    char slash = '/';
    string input;

    getline(cin, input);
    istringstream parser(input);
    parser >> num >> slash >> den;

    return Fraction(num, den);
}

int main() {
    Fraction first = readFraction();
    Fraction second = readFraction();

    cout << first.toOriginalString() << " + " << second.toOriginalString()
         << " = " << first.plus(second).toString() << endl;
    cout << first.toOriginalString() << " - " << second.toOriginalString()
         << " = " << first.minus(second).toString() << endl;
    cout << first.toOriginalString() << " * " << second.toOriginalString()
         << " = " << first.times(second).toString() << endl;
    cout << first.toOriginalString() << " / " << second.toOriginalString()
         << " = " << first.by(second).toString() << endl;

    return 0;
}
