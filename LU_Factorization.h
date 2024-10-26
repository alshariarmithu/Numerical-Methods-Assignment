#ifndef LU_FACTORIZATION_H
#define LU_FACTORIZATION_H

#include <vector>
using namespace std;

void luFactorization(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U);
vector<double> forwardSubstitution(const vector<vector<double>>& L, const vector<double>& b);

vector<double> backwardSubstitution(const vector<vector<double>>& U, const vector<double>& y);

void printVector(const vector<double>& v);

#endif
