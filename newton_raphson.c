#include <stdio.h>
#include <math.h>

float function(float x){
    // return (x-exp(-x));
    return (x*exp(x)-cos(x));
}

float derivative(float x){
    // return (1+exp(-x));
    return (exp(x)*(x+1)+sin(x));
}

int main(){

    float a, fa, dfa, b, tol, err;
    int i=0;
    printf("Initial guess value (a): ");
    scanf("%f", &a);
    printf("tolerance: ");
    scanf("%f", &tol);

    b = a - function(a)/derivative(a);
    err = fabs((b-a)/b);

    printf("%2s%12s%12s%12s\n", "n", "X", "X(n+1)", "error");
    printf("%2d%12f%12f%12f\n", ++i, a, b, err);
    
    while(err>tol){
        a = b;
        b = a - function(a)/derivative(a);
        err = fabs((b-a)/b);
        printf("%2d%12f%12f%12f\n", ++i, a, b, err);
    }

    printf("\nApproximated Root = %f\n", b);

    return 0;
}