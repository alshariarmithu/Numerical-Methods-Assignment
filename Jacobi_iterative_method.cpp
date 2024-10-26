#include "Jacobi_iterative_method.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double A[N][N], X[N], Y[N];

void string_to_coefficient(string s, int i) {
    int num = 0;
    int sign = 1;
    int idx = 0;

    if (s[0] == '-') {
        sign = -1;
        idx = 1;
    }

    for (int j = idx; j < s.length(); j++) {
        if (s[j] >= '0' && s[j] <= '9') {
            num = num * 10 + (s[j] - '0');
        } else if (s[j] == 'x') {
            if (num == 0) {
                num = 1;
            }
            A[i][1] = sign * num;
            num = 0;
            sign = 1;
        } else if (s[j] == 'y') {
            if (num == 0) {
                num = 1;
            }
            A[i][2] = sign * num;
            num = 0;
            sign = 1;
        } else if (s[j] == 'z') {
            if (num == 0) {
                num = 1;
            }
            A[i][3] = sign * num;
            num = 0;
            sign = 1;
        } else if (s[j] == 'w') {
            if (num == 0) {
                num = 1;
            }
            A[i][4] = sign * num;
            num = 0;
            sign = 1;
        }

        if (s[j] == '-') {
            sign = -1;
        } else if (s[j] == '+') {
            sign = 1;
        }
    }
    X[i] = sign * num;
}

void jacobiMethod(int n, int maxIter, double tolerance) {
    double sol[N] = {0};
    double prevSol[N] = {0};
    
    cout << "\nJacobi Iteration:\n";
    
    for (int iter = 0; iter < maxIter; iter++) {
        bool converged = true;
        
        for (int i = 1; i <= n; i++) {
            prevSol[i] = sol[i];
        }
        
        for (int i = 1; i <= n; i++) {
            double sum = 0;
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    sum += A[i][j] * prevSol[j];
                }
            }
            sol[i] = (X[i] - sum) / A[i][i];
        }
        
        for (int i = 1; i <= n; i++) {
            if (fabs(sol[i] - prevSol[i]) > tolerance) {
                converged = false;
            }
            cout << "x" << i << " = " << sol[i] << "\t";
        }
        cout << endl;
        
        if (converged) {
            cout << "Jacobi method converged after " << iter + 1 << " iterations.\n";
            break;
        }
    }
    
    cout << "\nSolution:\n";
    for (int i = 1; i <= n; i++) {
        cout << "x" << i << " = " << sol[i] << endl;
    }
}
