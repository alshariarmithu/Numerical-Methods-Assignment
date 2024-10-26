#include <bits/stdc++.h>
#include "Bisection_Method.h"
#include "False_Position_Method.h"
#include "Gauss_elimination.h"
#include "Gauss_GaussJordan_Inversion.h"
#include "Jacobi_iterative_method.h"
#include "LU_Factorization.h"
#include "Newton-Raphson-Method.h"
#include "Runge-Kutta-Method.h"
#include "Secant_Method.h"

using namespace std;

void displayMenu() {
    cout << "Choose a numerical method to solve:\n";
    cout << "1. Bisection Method\n";
    cout << "2. False Position Method\n";
    cout << "3. Gauss Elimination\n";
    cout << "4. Gauss-Jordan Elimination\n";
    cout << "5. Jacobi Iterative Method\n";
    cout << "6. LU Factorization\n";
    cout << "7. Newton-Raphson Method\n";
    cout << "8. Runge-Kutta Method\n";
    cout << "9. Secant Method\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    bool keepRunning = true;

    while (keepRunning) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            // Bisection Method
            float a, b, c;
            cout << "Enter coefficient a: ";
            cin >> a;
            cout << "Enter coefficient b: ";
            cin >> b;
            cout << "Enter coefficient c: ";
            cin >> c;
            bisectionMethod(a, b, c);
        }
        break;

        case 2: {
            // False Position Method
            float a, b, c;
            cout << "Enter coefficient a: ";
            cin >> a;
            cout << "Enter coefficient b: ";
            cin >> b;
            cout << "Enter coefficient c: ";
            cin >> c;
            falsePositionMethod(a, b, c);
        }
        break;

        case 3: {
            // Gauss Elimination
            int n;
            cout << "Enter the number of unknown variables: ";
            cin >> n;
            double arr[5][6];
            cout << "Enter Coefficients of Augmented Matrix:\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n + 1; j++) {
                    cin >> arr[i][j];
                }
            }
            gaussElimination(n, arr);
        }
        break;

        case 4: {
            // Gauss-Jordan Elimination
            int n;
            cout << "Enter the number of unknown variables: ";
            cin >> n;
            double arr[5][6];
            cout << "Enter Coefficients of Augmented Matrix:\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n + 1; j++) {
                    cin >> arr[i][j];
                }
            }
           //Gauss_jordan_elimination(arr);
        }
        break;

        case 5: {
            // Jacobi Iterative Method
            int n, maxIter;
            double tolerance;
            cout << "Enter the number of variables: ";
            cin >> n;
            cout << "Enter maximum number of iterations: ";
            cin >> maxIter;
            cout << "Enter tolerance: ";
            cin >> tolerance;
            jacobiMethod(n, maxIter, tolerance);
        }
        break;

        case 6: {
            // LU Factorization
            vector<vector<double>> A(5, vector<double>(5));
            cout << "Enter the matrix A (5x5):" << endl;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    cin >> A[i][j];
                }
            }
            vector<double> b(5);
            cout << "Enter vector b (5x1):" << endl;
            for (int i = 0; i < 5; i++) {
                cin >> b[i];
            }
            vector<vector<double>> L, U;
            luFactorization(A, L, U);
        }
        break;

        case 7: {
            // Newton-Raphson Method
            float a, b, c, d, x0, e;
            int N;
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
            newtonRaphson(a, b, c, d, x0, e, N);
        }
        break;

        case 8: {
            // Runge-Kutta Method
            float A, B, C, D, x0, y0, xn;
            int n;
            cout << "Enter coefficient A (for A*y^2): ";
            cin >> A;
            cout << "Enter coefficient B (for B*x^2): ";
            cin >> B;
            cout << "Enter coefficient C (for C*y^2): ";
            cin >> C;
            cout << "Enter coefficient D (for D*x^2): ";
            cin >> D;
            cout << "Enter initial condition x0 = ";
            cin >> x0;
            cout << "Enter y0 = ";
            cin >> y0;
            cout << "Enter calculation point xn = ";
            cin >> xn;
            cout << "Enter number of steps: ";
            cin >> n;
            RungeKuttaMethod(A, B, C, D, x0, y0, xn, n);
        }
        break;

        case 9: {
            // Secant Method
            float a, b, c, d, x0, x1, e;
            int N;
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
            secantMethod(a, b, c, d, x0, x1, e, N);
        }
        break;

        case 0:
            keepRunning = false;
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
