#include <stdio.h>
#include <math.h>

float function(float x){
    // return (x*log10(x)-1.9);
    return (x-exp(-x));
}

float intersect(float a, float b){
    return (b-(function(b)*(b-a)/(function(b)-function(a))));
}

int main(){
    float a, b, fa, fb, c, fc, tol;
    int i=0;

    printf("Initial guess values (a b): ");
    scanf("%f %f", &a, &b);
    printf("tolerance: ");
    scanf("%f", &tol);
    
    fa = function(a);
    fb = function(b);
    c = intersect(a, b);
    fc = function(c);

    printf("\n%2s%12s%12s%12s%12s%12s%12s\n", "n", "a", "b", "f(a)", "f(b)", "c", "f(c)");
    printf("%2d%12f%12f%12f%12f%12f%12f\n", ++i, a, b, fa, fb, c, fc);

    while(fabs((c-b)/c)>tol){
        if(fb*fc<0){
            a = c;
            fa = fc;
        }else{
            b = c;
            fb = fc;
        }
        c = intersect(a, b);
        fc = function(c);
        printf("%2d%12f%12f%12f%12f%12f%12f\n", ++i, a, b, fa, fb, c, fc);
    }

    printf("\nApproximated Root = %f\n", c);

    return 0;
}