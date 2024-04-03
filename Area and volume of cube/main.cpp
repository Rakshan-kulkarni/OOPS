#include <iostream>
using namespace std;

class Cube {
public:
    double side;

    Cube(double s) {
        side = s;
    }

    double surfaceArea() {
        return 6 * side * side;
    }

    double volume() {
        return side * side * side;
    }
};

int main() {
    double s;
    cout << "Enter the side length of the cube: ";
    cin >> s;

    Cube cube(s);

    cout << "Surface Area of the cube: " << cube.surfaceArea() << endl;
    cout << "Volume of the cube: " << cube.volume() << endl;

    return 0;
}
