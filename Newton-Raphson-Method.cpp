#include <iostream>
#include <iomanip>
#include <cmath>
#include "Newton-Raphson-Method.h"

using namespace std;

float f(float x, float a, float b, float c, float d) {
    return a * x * x * x + b * x * x + c * x + d;
}

float g(float x, float a, float b, float c) {
    return 3 * a * x * x + 2 * b * x + c;
}

void newtonRaphson(float a, float b, float c, float d, float x0, float e, int N) {
    float x1, f0, f1, g0;
    int step = 1;

    cout << setprecision(6) << fixed;
    cout << endl << "*********************" << endl;
    cout << "Newton-Raphson Method" << endl;
    cout << "*********************" << endl;

    do {
        g0 = g(x0, a, b, c);
        f0 = f(x0, a, b, c, d);
        
        if (g0 == 0.0) {
            cout << "Mathematical Error: Derivative is zero.";
            return;
        }

        x1 = x0 - f0 / g0;

        cout << "Iteration-" << step << ":\t x = " << setw(10) << x1 << " and f(x) = " << setw(10) << f(x1, a, b, c, d) << endl;

        x0 = x1;
        step++;

        if (step > N) {
            cout << "Not Convergent.";
            return;
        }

        f1 = f(x1, a, b, c, d);

    } while (fabs(f1) > e);

    cout << endl << "Root is: " << x1 << endl;
}
