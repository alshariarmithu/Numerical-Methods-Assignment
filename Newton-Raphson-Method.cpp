#include <bits/stdc++.h>
using namespace std;

//ALSHARIAR HOSSAIN MITHU //
//ROLL: 2107066//



/*Equation*/
float f(float x, float a, float b, float c, float d) {
    return a * x * x * x + b * x * x + c * x + d;
}
/*Differentiation of the eqation*/
float g(float x, float a, float b, float c) {
    return 3 * a * x * x + 2 * b * x + c;
}

int main()
{
    float x0, x1, f0, f1, g0, e;
    float a, b, c, d;
    int step = 1, N;
    cout << setprecision(6) << fixed;

    cout << "Enter coefficient a (for x^3 term): ";
    cin >> a;
    cout << "Enter coefficient b (for x^2 term): ";
    cin >> b;
    cout << "Enter coefficient c (for x term): ";
    cin >> c;
    cout << "Enter coefficient d (constant term): ";
    cin >> d;

    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter tolerable error: ";
    cin >> e;
    cout << "Enter maximum iteration: ";
    cin >> N;

    cout << endl << "*********************" << endl;
    cout << "Newton-Raphson Method" << endl;
    cout << "*********************" << endl;
    
    do
    {
        g0 = g(x0, a, b, c); 
        f0 = f(x0, a, b, c, d);
        
        if (g0 == 0.0) {
            cout << "Mathematical Error: Derivative is zero.";
            exit(0);
        }

        x1 = x0 - f0 / g0;

        cout << "Iteration-" << step << ":\t x = " << setw(10) << x1 << " and f(x) = " << setw(10) << f(x1, a, b, c, d) << endl;

        x0 = x1;
        step++;

        if (step > N) {
            cout << "Not Convergent.";
            exit(0);
        }

        f1 = f(x1, a, b, c, d);

    } while (fabs(f1) > e);

    cout << endl << "Root is: " << x1 << endl;

    return 0;
}
