#include <iostream>
using namespace std;

int main() {
    int vector[] = {3, -5, 7, 10, -4, 14, 5, 2, -13};
    const int n = sizeof(vector) / sizeof(*vector);

    int *minimum = vector;

    for (int *current = vector + 1; current < vector + n; ++current) {
        if (*current < *minimum) {
            minimum = current;
        }
    }

    cout << "Array: ";
    for (int *current = vector; current < vector + n; ++current) {
        cout << *current << ' ';
    }

    cout << "\nMinimum element: " << *minimum << endl;
    cout << "Index: " << minimum - vector << endl;
    cout << "Position: " << minimum - vector + 1 << endl;

    return 0;
}
