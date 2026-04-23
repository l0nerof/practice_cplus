#include <iostream>
using namespace std;

class AdHocSquare {
public:
    AdHocSquare(double side);
    void set_side(double side);
    double get_area() const;

private:
    double side;
};

class LazySquare {
public:
    LazySquare(double side);
    void set_side(double side);
    double get_area();
    bool changed() const;

private:
    double side;
    double area;
    bool side_changed;
};

AdHocSquare::AdHocSquare(double side) {
    this->side = side >= 0 ? side : 0;
}

void AdHocSquare::set_side(double side) {
    if (side >= 0) {
        this->side = side;
    }
}

double AdHocSquare::get_area() const {
    return side * side;
}

LazySquare::LazySquare(double side) {
    this->side = side >= 0 ? side : 0;
    this->area = this->side * this->side;
    this->side_changed = false;
}

void LazySquare::set_side(double side) {
    if (side < 0) {
        return;
    }

    if (this->side != side) {
        this->side = side;
        this->side_changed = true;
    }
}

double LazySquare::get_area() {
    if (side_changed) {
        area = side * side;
        side_changed = false;
    }

    return area;
}

bool LazySquare::changed() const {
    return side_changed;
}

int main() {
    cout << boolalpha;

    AdHocSquare adHoc(4);
    cout << "AdHoc area: " << adHoc.get_area() << endl;
    adHoc.set_side(6);
    cout << "AdHoc area after set_side(6): " << adHoc.get_area() << endl;

    LazySquare lazy(4);
    cout << "Lazy area: " << lazy.get_area() << endl;
    cout << "Lazy changed: " << lazy.changed() << endl;
    lazy.set_side(6);
    cout << "Lazy changed after set_side(6): " << lazy.changed() << endl;
    cout << "Lazy area after set_side(6): " << lazy.get_area() << endl;
    cout << "Lazy changed after get_area(): " << lazy.changed() << endl;

    return 0;
}
