#ifndef NEWTON_RAPHSON_METHOD_H
#define NEWTON_RAPHSON_METHOD_H

float f(float x, float a, float b, float c, float d);

float g(float x, float a, float b, float c);

void newtonRaphson(float a, float b, float c, float d, float x0, float e, int N);

#endif 
