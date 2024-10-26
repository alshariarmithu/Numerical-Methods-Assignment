#include <iostream>
#include <iomanip>
#include "Runge-Kutta-Method.h"

using namespace std;

float f(float x, float y, float A, float B, float C, float D) {
    return (A * y * y - B * x * x) / (C * y * y + D * x * x);
}

void RungeKuttaMethod(float A, float B, float C, float D, float x0, float y0, float xn, int n) {
    float h, yn, k1, k2, k3, k4, k;
    h = (xn - x0) / n;

    cout << "---------- Runge-Kutta Method ---------" << endl;
    cout << "\nx0\ty0\tyn\n";
    cout << "------------------\n";

    for (int i = 0; i < n; i++) {
        k1 = h * f(x0, y0, A, B, C, D);
        k2 = h * f(x0 + h / 2, y0 + k1 / 2, A, B, C, D);
        k3 = h * f(x0 + h / 2, y0 + k2 / 2, A, B, C, D);
        k4 = h * f(x0 + h, y0 + k3, A, B, C, D);

        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;

        cout << x0 << "\t" << y0 << "\t" << yn << endl;

        x0 = x0 + h;
        y0 = yn;
    }

    cout << "\n\nValue of y at x = " << xn << " is " << yn << endl;
}
