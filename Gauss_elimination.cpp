#include "Gauss_elimination.h"

void gaussElimination(int n, double arr[][6]) {
    cout << setprecision(5) << fixed;

    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (i == j) {
                break;
            } else {
                double a, b;
                int p = i;
                while (arr[p - 1][j] == 0) {
                    p--;
                }
                b = arr[p - 1][j];
                a = arr[i][j];
                if (a == 0.0) {
                    continue;
                }
                for (int m = 0; m < n + 1; m++) {
                    arr[i][m] = (b * arr[i][m]) - (a * arr[p - 1][m]);
                }
            }
        }
    }

    cout << "Gauss Elimination:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (i == j) {
                break;
            } else {
                double a, b;
                int p = i;
                while (arr[p + 1][j] == 0) {
                    p++;
                }
                b = arr[p + 1][j];
                a = arr[i][j];
                if (a == 0.0) {
                    continue;
                }
                for (int m = 0; m < n + 1; m++) {
                    arr[i][m] = (a * arr[p + 1][m]) - (b * arr[i][m]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        double p = arr[i][i];
        for (int j = 0; j < n + 1; j++) {
            arr[i][j] = (arr[i][j] / p);
        }
    }
    cout << "The values of the variables are:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << arr[i][n] << endl;
    }
}
