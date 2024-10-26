
#include <bits/stdc++.h>
#include "Gauss_GaussJordan_Inversion.h" 

using namespace std;

vector<vector<double>> Upper_triangular(vector<vector<double>> a) {
    // Implementation of Upper_triangular
    int n = a.size();
    int m = a[0].size();
    int maxrow;
    for (int i = 0; i < n; i++) {
        maxrow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(a[k][i]) > fabs(a[maxrow][i]))
                maxrow = k;
        }
        if (i != maxrow) {
            swap(a[i], a[maxrow]);
        }
        for (int k = i + 1; k < n; k++) {
            double r = a[k][i] / a[i][i];
            for (int j = i; j < m; j++) {
                a[k][j] = a[k][j] - r * a[i][j];
            }
        }
    }
    return a;
}

vector<vector<double>> Reduced_row_echelon(vector<vector<double>> a) {
    // Implementation of Reduced_row_echelon
    vector<vector<double>> a2 = Upper_triangular(a);
    int n = a2.size();
    int m = a2[0].size();
    for (int i = n - 1; i >= 0; i--) {
        for (int k = i - 1; k >= 0; k--) {
            double r = a2[k][i] / a2[i][i];
            for (int j = i; j < m; j++) {
                a2[k][j] = a2[k][j] - r * a2[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = n; j < m; j++) {
            a2[i][j] /= a2[i][i];
        }
        a2[i][i] = 1;
    }
    return a2;
}

bool Solvable(vector<vector<double>> a) {
    if (a.size() != a[0].size() - 1) {
        return false;
    }
    vector<vector<double>> a1 = Upper_triangular(a);
    for (int i = 0; i < a.size(); i++) {
        if (a1[i][i] == 0)
            return false;
    }
    return true;
}

bool invertible(vector<vector<double>> a) {
    if (a.size() != a[0].size()) {
        return false;
    }
    vector<vector<double>> a1 = Upper_triangular(a);
    for (int i = 0; i < a.size(); i++) {
        if (a1[i][i] == 0)
            return false;
    }
    return true;
}

void Gauss_elimination(vector<vector<double>> a) {
    if (!Solvable(a)) {
        cout << "Not solvable\n";
        return;
    }
    vector<vector<double>> a1 = Upper_triangular(a);
    vector<double> solution;
    int n = a1.size();
    solution.push_back(a1[n - 1][n] / a1[n - 1][n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < solution.size(); j++) {
            a1[i][n] = a1[i][n] - solution[j] * a1[i][n - j - 1];
        }
        a1[i][n] = a1[i][n] / a1[i][i];
        solution.push_back(a1[i][n]);
    }
    for (int i = solution.size() - 1; i >= 0; i--) {
        cout << "x" << n - i << " = " << solution[i] << endl;
    }
}

void Gauss_jordan_elimination(vector<vector<double>> a) {
    if (!Solvable(a)) {
        cout << "Not solvable\n";
        return;
    }
    vector<vector<double>> a1 = Reduced_row_echelon(a);
    int n = a1.size();
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << a1[i][n] << endl;
    }
}

void Matrix_inversion(vector<vector<double>> a) {
    if (!invertible(a)) {
        cout << "Matrix not invertible\n";
        return;
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (i == j)
                a[i].push_back(1);
            else
                a[i].push_back(0);
        }
    }
    vector<vector<double>> a1 = Reduced_row_echelon(a);
    for (int i = 0; i < a1.size(); i++) {
        for (int j = a.size(); j < a1[0].size(); j++) {
            cout << a1[i][j] << "\t";
        }
        cout << endl;
    }
}
