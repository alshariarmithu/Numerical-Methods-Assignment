#include <iostream>
#include <iomanip>
#include <cmath>
#include "Secant_Method.h"

using namespace std;

float f(float x, float a, float b, float c, float d) {
    return a * x * x * x + b * x * x + c * x + d;
}

void secantMethod(float a, float b, float c, float d, float x0, float x1, float e, int N) {
    float x2, f0, f1, f2;
    int step = 1;

    cout << setprecision(6) << fixed;
    cout << "--------- Secant Method ----------" << endl;

    do {
        f0 = f(x0, a, b, c, d);
        f1 = f(x1, a, b, c, d);

        if (f0 == f1) {
            cout << "Mathematical Error: Division by zero." << endl;
            exit(0);
        }

        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2, a, b, c, d);

        cout << "Iteration-" << step << ":\t x2 = " << setw(10) << x2 << " and f(x2) = " << setw(10) << f2 << endl;

        x0 = x1;
        x1 = x2;

        step++;

        if (step > N) {
            cout << "Not Convergent." << endl;
            exit(0);
        }

    } while (fabs(f2) > e);

    cout << endl << "Root is: " << x2 << endl;
}
