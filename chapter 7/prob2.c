/*Program to generate 2 4x4 matrices and calculate its commutator
matrix aij= i/(i+j), matrix bij=j/(i+j) */
#include<stdio.h>
#include<math.h>
#define MAX 4

void matsub(float M1[MAX][MAX], float M2[MAX][MAX], float result[MAX][MAX]);
void matprint(float C[MAX][MAX]);
void matmult(float M1[MAX][MAX], float M2[MAX][MAX], float result[MAX][MAX]);

void main(){
    float M1[MAX][MAX];
    float M2[MAX][MAX];

    float D[MAX][MAX]; // to store M1*M2
    float B[MAX][MAX]; // to store M2*M1
    float commutator[MAX][MAX]; //to store (M1*M2-M2*M1)

    //generating matrices for M1 and M2
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(i+j==0){
                M1[i][j]=0;
                M2[i][j]=0;

            }else{
                M1[i][j]=(float)i/(i+j);
                M2[i][j]=(float)j/(i+j);
            }
        }
    }
    matmult(M1, M2, D);
    matmult(M2, M1, B);
    matsub(D, B, commutator);
    matprint(commutator);
    
}
void matsub(float M1[MAX][MAX], float M2[MAX][MAX], float result[MAX][MAX]){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            result[i][j]=M1[i][j]-M2[i][j];
        }
    }
    
}
void matprint(float C[MAX][MAX]){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            printf("%f\t",C[i][j]);
        }
        printf("\n");
    }
}

void matmult(float M1[MAX][MAX], float M2[MAX][MAX], float result[MAX][MAX]){
    float sum=0;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            for(int k=0; k<MAX; k++){
                sum+=M1[i][k]*M2[k][j];

            }
            result[i][j]=sum;
            sum=0;
        }
    }
}
