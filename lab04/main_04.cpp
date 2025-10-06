#include <iostream>

#include "Polynomial.h"
using namespace std;

int main() {
    double coeffs1[] = {1, 2, 3};
    double coeffs2[] = {0, 1};

    Polynomial p1(2, coeffs1);
    Polynomial p2(1, coeffs2);

    cout << "p1(x) = " << p1 << endl;
    cout << "p2(x) = " << p2 << endl;
    cout << "p1 + p2 = " << (p1 + p2) << endl;
    cout << "p1 * p2 = " << (p1 * p2) << endl;
    cout << "p1'(x) = " << p1.derivative() << endl;
    cout << "p1(2) = " << p1.evaluate(2) << endl;

    return 0;
}