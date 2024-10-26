
#ifndef GAUSS_GAUSSJORDAN_INVERSION_H
#define GAUSS_GAUSSJORDAN_INVERSION_H

#include <vector>
using namespace std;

// Function declarations
vector<vector<double>> Upper_triangular(vector<vector<double>> a);
vector<vector<double>> Reduced_row_echelon(vector<vector<double>> a);
bool Solvable(vector<vector<double>> a);
bool invertible(vector<vector<double>> a);
void Gauss_elimination(vector<vector<double>> a);
void Gauss_jordan_elimination(vector<vector<double>> a);
void Matrix_inversion(vector<vector<double>> a);

#endif 
