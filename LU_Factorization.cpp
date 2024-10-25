#include <bits/stdc++.h>
using namespace std;

// AL SHARIAR HOSSAIN MITHU //
// ROLL: 2107066 //

void luFactorization(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    L = vector<vector<double>>(n, vector<double>(n, 0));
    U = vector<vector<double>>(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++) {

        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }

        for (int k = i; k < n; k++) {
            if (i == k) {
                L[i][i] = 1;
            } else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += L[k][j] * U[j][i];
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

vector<double> forwardSubstitution(const vector<vector<double>>& L, const vector<double>& b) {
    int n = L.size();
    vector<double> y(n, 0);

    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }

    return y;
}

vector<double> backwardSubstitution(const vector<vector<double>>& U, const vector<double>& y) {
    int n = U.size();
    vector<double> x(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }

    return x;
}

void printVector(const vector<double>& v) {
    for (double val : v) {
        cout << setw(10) << val << " ";
    }
    cout << endl;
}

int main() {
    // Input matrix A
    vector<vector<double>> A(5, vector<double>(5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> A[i][j];
        }
    }

    // Input vector b
    vector<double> b(3);
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }

    int n = A.size();
    vector<vector<double>> L(n, vector<double>(n, 0)), U(n, vector<double>(n, 0));

    luFactorization(A, L, U);

    vector<double> y = forwardSubstitution(L, b);
    vector<double> x = backwardSubstitution(U, y);

    cout << "Solution vector x:" << endl;
    printVector(x);

    return 0;
}
