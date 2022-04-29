#include <stdio.h>
#include <math.h>

#define f(x) 2*x*x*x - 13*x*x - 2*x - 50
#define g(x) 6*x*x - 26*x - 2

double newton(double x0) {
    double f0 = f(x0);
    double g0 = g(x0);
    return x0 - f0/g0;
}

double zelva_zajic(double x0){
    double zelva = newton(x0);
    double zajic = newton(newton(x0));
    for(;;){
        zelva = newton(zelva);
        zajic = newton(newton(zajic));

        if(fabs(zelva - zajic) < 0.0000000000000001)
            return zelva;
    }
}

int main() {
    printf("%.50lf", zelva_zajic(4));
    return 0;
}
