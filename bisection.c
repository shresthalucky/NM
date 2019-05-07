#include <stdio.h>
#include <math.h>

float function(float x){
    return (x*x*x + x*x + x + 7);
    // return (x*x-sin(x)-0.5);
    // return ((1-pow(1+x,4))/x - 1);
    // return (4*exp(-x)*sin(x)-1);
    // return (x*log10(x) - 1.9);
}

int main(){
    
    float a, b, c, tol, fa, fb, fc;
    int i = 0;
    
    do{
        printf("Initial guess values (a b): ");
        scanf("%f %f", &a, &b);
        fa = function(a);
        fb = function(b);
    }while(fa*fb > 0);

    printf("tolerance: ");
    scanf("%f", &tol);

    printf("\n%2s%12s%12s%12s%12s%12s%12s\n", "n", "a", "b", "f(a)", "f(b)", "c", "f(c)");
    
    c = (a+b)/2;
    fc = function(c);
    printf("%2d%12f%12f%12f%12f%12f%12f\n", ++i, a, b, fa, fb, c, fc);

    while(fabs((a-b)/c) > tol){

        fc = function(c);
        if((fa*fc)>0){
            a = c;
            fa = fc;
        }else{
            b = c;
            fb = fc;
        }
        c = (a+b)/2;
        printf("%2d%12f%12f%12f%12f%12f%12f\n", ++i, a, b, fa, fb, c, fc);
    }

    printf("\nApproximated Root = %f\n", c);

    return 0;
}