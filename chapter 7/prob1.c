/*seperate functions for 1) adding 2) subtracting 3) multiplying
4) printing 5) finding trace of matrices 6) transferring elements of one matrix to another*/

#include<stdio.h>
#include<math.h>
#define MAX 4
float C[MAX][MAX]; 

/*Function Declarations*/
void matadd(float M1[MAX][MAX], float M2[MAX][MAX]);
void matsub(float M1[MAX][MAX], float M2[MAX][MAX]);
void matmult(float M1[MAX][MAX], float M2[MAX][MAX]);
void matprint(float C[MAX][MAX]);
float trace(float C[MAX][MAX]);
void transfer(float M1[MAX][MAX], float M2[MAX][MAX]);

void main(){
    //some arbitrary matrices to check the implementation of the functions
    float M1[MAX][MAX] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    float M2[MAX][MAX] = {{16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};
    
    // Matrix Addition
    matadd(M1, M2);
    printf("Matrix Addition Result:\n");
    matprint(C);
    
    // Matrix Subtraction
    matsub(M1, M2);
    printf("Matrix Subtraction Result:\n");
    matprint(C);
    
    // Matrix Multiplication
    matmult(M1, M2);
    printf("Matrix Multiplication Result:\n");
    matprint(C);
    
    // Trace of a matrix
    float tr = trace(M1);
    printf("Trace of Matrix M1: %.2f\n", tr);
    
    // Matrix Transfer
    transfer(M1, M2);
    printf("Matrix M2 (after transfer from M1):\n");
    matprint(M2);
    
    
}


/* Function Definitions*/
void matadd(float M1[MAX][MAX], float M2[MAX][MAX]){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            C[i][j]=M1[i][j]+M2[i][j];
        }
    }
    
}
void matsub(float M1[MAX][MAX], float M2[MAX][MAX]){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            C[i][j]=M1[i][j]-M2[i][j];
        }
    }
    
}
void matmult(float M1[MAX][MAX], float M2[MAX][MAX]){
    int sum=0;
    for(int i=0;i<MAX;i++){
        for(int j=0; j<MAX; j++){
            for(int k=0; k<MAX; k++){
                sum+=M1[i][k]*M2[k][j];
            }
            C[i][j]=sum;
            sum=0;
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
float trace(float C[MAX][MAX]){
    float tr=0;
    for(int i=0; i<MAX; i++){
        tr+=C[i][i]; //adds only the diagnol elements
    }
    return tr;
}

void transfer(float M1[MAX][MAX], float M2[MAX][MAX]){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            M2[i][j]=M1[i][j];
        }
    }

}
        