#include <bits/stdc++.h>
using namespace std;

//ALSHARIAR HOSSAIN MITHU //
// ROLL: 2107066 //

float f(float x, float a, float b, float c, float d) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
    float x0, x1, x2, f0, f1, f2, e;
    float a, b, c, d;
    int step = 1, N;

    cout << setprecision(6) << fixed;

    cout << "Enter coefficient a: ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter coefficient c: ";
    cin >> c;
    cout << "Enter coefficient d: ";
    cin >> d;

    cout << "Enter first guess: ";
    cin >> x0;
    cout << "Enter second guess: ";
    cin >> x1;
    cout << "Enter tolerable error: ";
    cin >> e;
    cout << "Enter maximum iteration: ";
    cin >> N;

    cout << "--------- Secant Method ----------" << endl;
    do
    {
        f0 = f(x0, a, b, c, d);
        f1 = f(x1, a, b, c, d);
        
        if (f0 == f1) {
            cout << "Mathematical Error: Division by zero.";
            exit(0);
        }

        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2, a, b, c, d);

        cout << "Iteration-" << step << ":\t x2 = " << setw(10) << x2 << " and f(x2) = " << setw(10) << f2 << endl;

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;

        step++;

        if (step > N) {
            cout << "Not Convergent.";
            exit(0);
        }

    } while (fabs(f2) > e);

    cout << endl << "Root is: " << x2 << endl;

    return 0;
}
