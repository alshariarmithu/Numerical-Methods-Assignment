#include <iostream>
#include <iomanip>
#include <cmath>
#include "False_Position_Method.h"

using namespace std;

float f(float x, float a, float b, float c) {
    return a * x * x + b * x + c;
}

void falsePositionMethod(float a, float b, float c) {
    float x0, x1, x, f0, f1, f_mid, e;
    int step = 1;

    cout << setprecision(6) << fixed;

    while (1) {
        cout << "Enter first guess: ";
        cin >> x0;
        cout << "Enter second guess: ";
        cin >> x1;
        cout << "Enter tolerable error: ";
        cin >> e;
        
        f0 = f(x0, a, b, c);
        f1 = f(x1, a, b, c);

        if (f0 * f1 > 0.0) {
            cout << "Incorrect Initial Guesses. Please try again." << endl;
        } else {
            break;
        }
    }

    cout << endl
         << "*********************" << endl;
    cout << "False Position Method" << endl;
    cout << "*********************" << endl;

    do {
        x = x0 - (x0 - x1) * f0 / (f0 - f1);
        f_mid = f(x, a, b, c);

        cout << "Iteration-" << step << ":\t x = " << setw(10) << x << " and f(x) = " << setw(10) << f_mid << endl;

        if (f0 * f_mid < 0) {
            x1 = x;
            f1 = f_mid;
        } else {
            x0 = x;
            f0 = f_mid;
        }

        step = step + 1;
    } while (fabs(f_mid) > e);

    cout << endl
         << "Root is: " << x << endl;
}
