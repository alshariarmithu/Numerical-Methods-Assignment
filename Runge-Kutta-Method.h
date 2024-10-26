#ifndef RUNGE_KUTTA_METHOD_H
#define RUNGE_KUTTA_METHOD_H

float f(float x, float y, float A, float B, float C, float D);

void RungeKuttaMethod(float A, float B, float C, float D, float x0, float y0, float xn, int n);

#endif 
