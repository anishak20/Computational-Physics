#include <stdio.h>
#include <math.h>

// Function declarations
float f(float x);
float g(float x);
float bisection(float xl, float xr, float acc);
float secant(float x1, float x2, float acc);
float newtonraphson(float x, float acc);

void main() {
    float x, root,root1,root2;
    float acc = 0.00001;


    for (x = -1.0; x < 1.0; x += 0.5) {
        if (f(x) * f(x + 0.5) < 0) {
            root = bisection(x, x + 0.5, acc);
            printf("Root from Bisection: %f\n", root);
            root1 = secant(x, x + 0.5, acc);
            printf("Root from Secant: %f\n", root1);
        } 
        root2 = newtonraphson(x, acc);
        printf("Root from Newton Raphson: %f\n", root2);
        
    }
}

// Function Definitions
float f(float x) {
    float a = 1.0, b = 5.0;
    return exp(a * x) - (b * x * x);
}

float g(float x) {
    float a = 1.0, b = 5.0;
    return a * exp(a * x) - (2 * b * x);
}

// Bisection Method
float bisection(float xl, float xr, float acc) {
    float xm;
    do {
        xm = (xl + xr) / 2.0;
        if (f(xm) * f(xl) > 0) {
            xl = xm;
        } else {
            xr = xm;
        }
    } while (fabs(xr - xl) > acc);
    return xm;
}

// Secant Method
float secant(float x1, float x2, float acc) {
    float f1, f2, x3;
    do {
        f1 = f(x1);
        f2 = f(x2);
        if (fabs(f2 - f1) < 1e-10) {
            return NAN;  // Return invalid root if division by zero occurs
        }
        x3 = (x1 * f2 - f1 * x2) / (f2 - f1);
        x1 = x2;
        x2 = x3;
    } while (fabs(f(x2)) > acc);
    return x2;
}

// Newton-Raphson Method
float newtonraphson(float x, float acc) {
    float h, f1, f2;
    do {
        f1 = f(x);
        f2 = g(x);
        if (fabs(f2) < 1e-10) {  // Prevent division by zero
            return NAN;
        }
        h = -f1 / f2;
        x = x + h;
    } while (fabs(h / x) > acc);
    return x;
}
