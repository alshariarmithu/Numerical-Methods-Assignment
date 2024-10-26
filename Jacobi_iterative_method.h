
#ifndef JACOBI_ITERATIVE_METHOD_H
#define JACOBI_ITERATIVE_METHOD_H

#include <string>

const int N = 6; 

void string_to_coefficient(std::string s, int i);
void jacobiMethod(int n, int maxIter, double tolerance);

#endif
