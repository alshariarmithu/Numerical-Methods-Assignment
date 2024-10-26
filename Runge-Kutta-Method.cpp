#include <bits/stdc++.h>
using namespace std;
//ALSHARIAR HOSSAIN MITHU //
//ROLL: 2107066 //  

/*Differential equation dy/dx = (A*y^2 - B*x^2) / (C*y^2 + D*x^2) */
float f(float x, float y, float A, float B, float C, float D) {
    return (A * y * y - B * x * x) / (C * y * y + D * x * x);
}

int main()
{
    float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
    float A, B, C, D;
    int i, n;

    cout << "Enter the coefficient A (for A*y^2): ";
    cin >> A;
    cout << "Enter the coefficient B (for B*x^2): ";
    cin >> B;
    cout << "Enter the coefficient C (for C*y^2): ";
    cin >> C;
    cout << "Enter the coefficient D (for D*x^2): ";
    cin >> D;

    cout << "\nEnter Initial Condition" << endl;
    cout << "x0 = ";
    cin >> x0;
    cout << "y0 = ";
    cin >> y0;
    cout << "Enter calculation point xn = ";
    cin >> xn;
    cout << "Enter number of steps: ";
    cin >> n;

    h = (xn - x0) / n;

    cout<<"---------- Runge-Kutta Method---------"<<endl;
    cout << "\nx0\ty0\tyn\n";
    cout << "------------------\n";
    
    for (i = 0; i < n; i++) {
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

    return 0;
}
