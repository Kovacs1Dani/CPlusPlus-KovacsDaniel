#include <iostream>

#include "functions.h"
using namespace std;
int main() {

    //1 exerc.
    for (int i = 0; i < 127; i++) {
        cout << countBits(i) << endl;
    }

    //2 exerc.
    int n = 5;
    cout << "Original number: " << n << endl;
    if (setBits(n, 3)) {
    }




    double array[] = {1.0, 5.0, 3.0, 7.0, 14.0, 2.0};

    return 0;
}
