#include <iostream>
#include <cmath>

class Vector {
private:
    double x, y;

public:
    Vector(double x, double y) : x(x), y(y) {}

    Vector add(const Vector& other) {
        return Vector(x + other.x, y + other.y);
    }

    void print() {
        std::cout << "向量之和: x=" << x << ", y=" << y << std::endl;
    }

    void dir() {
        double magnitude = std::sqrt(x * x + y * y);
        std::cout << "模长: " << magnitude << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " x1 y1 x2 y2" << std::endl;
        return 1;
    }

    double x1 = std::stod(argv[1]);
    double y1 = std::stod(argv[2]);
    double x2 = std::stod(argv[3]);
    double y2 = std::stod(argv[4]);

    Vector v1(x1, y1);
    Vector v2(x2, y2);
    Vector sum = v1.add(v2);

    sum.print();
    sum.dir();

    return 0;
}
