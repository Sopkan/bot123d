#include <iostream>

int fullMatxA(int matrix[4][4]){
    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){
            std::cout << "Enter num for " << i << " "<< k <<" "<< " pos: ";
            std::cin >> matrix [i][k];
        }
    }
    return matrix[4][4];
}
int fullMatxB(int matrix[4]){
    for(int i = 0; i < 4; i++){
            std::cout << "Enter num for " << i <<" "<< " pos: ";
            std::cin >> matrix[i];
    }
    return matrix[4];
}

int matixAxMatrixBtoC(int matrixA[4][4], int matrixB[4], int matrixC[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j =0; j < 4; j++){
            matrixC[i][j] = matrixA[i][j] * matrixB[j];
        }
    }
    return matrixC[4][4];
}

void seeMatrix(int matrixC[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j =0; j < 4; j++){
            std::cout<<matrixC[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    int matrixA[4][4], matrixB[4], matrixC[4][4];
    matrixA[4][4] = fullMatxA(matrixA);
    matrixB[4] =  fullMatxB(matrixB);
    matrixC[4][4] = matixAxMatrixBtoC(matrixA, matrixB, matrixC);
    for(int i = 0; i < 4; i++){
        for(int j =0; j < 4; j++){
            std::cout<<matrixC[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}