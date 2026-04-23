#include <iostream>
#include <string>
using namespace std;

class Square {
public:
    Square(double side);
    void set_side(double side);
    void print() const;

private:
    double side;
    double area;
};

Square::Square(double side) {
    this->side = 0;
    this->area = 0;
    set_side(side);
}

void Square::set_side(double side) {
    if (side < 0) {
        return;
    }

    this->side = side;
    this->area = side * side;
}

void Square::print() const {
    cout << "Square: side=" << side << " area=" << area << endl;
}

int main() {
    Square s(4);

    s.print();

    s.set_side(2.0);
    s.print();

    s.set_side(-33.0);
    s.print();

    return 0;
}
