#include <stdio.h>

int main(){
    int n, i, j, k;
    printf("number of unknowns: ");
    scanf("%d", &n);
    
    float m[n][n+1], x[n], r, sum;
    printf("Input augmented matrix:\n");

    for(i=0; i<n; i++){
        for(j=0; j<n+1; j++){
            printf("[%d][%d]: ", i+1, j+1);
            if(i==j){
                do{
                    scanf("%f", &m[i][j]);
                    if(m[i][j]==0) printf("diagonals cannot be zero!: ");
                }while(m[i][j]==0);
            }else{
                scanf("%f", &m[i][j]);
            }
        }
    }

    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
                r = m[j][i]/m[i][i];
            for(k=0; k<n+1; k++){
                m[j][k] = m[j][k] - r*m[i][k];           
            }
        }
    }

    printf("\nAfter applying guess elimination\n");

    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            printf("%f\t", m[i][j]);
        }
        printf("\n");
    }

    for(i=n-1; i>=0; i--){
        sum=0;
        for(j=i+1; j<n+1; j++){
            sum = sum + m[i][j] * x[j];
        }
        x[i] = (m[i][n] - sum) / m[i][i];
    }

    printf("\nApplying backward substitution:\n");

    for(i=0; i<n; i++){
        printf("x%d = %f \n", i+1 , x[i]);
    }

    return 0;
}