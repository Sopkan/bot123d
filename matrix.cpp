#include <iostream>

int fullMatx(int matrix[4][4]){
    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){
            std::cout << "Enter num for " << i << " "<< k <<" "<< " pos: ";
            std::cin >> matrix [i][k];
        }
    }
    return matrix[4][4];
}
bool matxIsMatx(int matrix1[4][4], int matrix2[4][4]){
    bool isGood = true;
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 4; k++){
            if(matrix1[i][k] != matrix2[i][k]){
                isGood = false;
                break;
            }
        }
    }
    return isGood;
}

int diagonalMatx(int matrix[4][4]){
    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){
            if(i != k)
                matrix[i][k] = 0;
        }
    }
    return matrix[4][4];
}

void seeMatx(int matrix[4][4]){
    for(int i = 0; i < 4; i++){
        for(int k = 0; k < 4; k++){
            std::cout << matrix[i][k] << " "; 
        }
        std::cout<< std::endl;
    }
}

int main(){
    int matrix1[4][4];
    int matrix2[4][4];
    matrix1[4][4] = fullMatx(matrix1);
    matrix2[4][4] = fullMatx(matrix2);
    bool isGood = matxIsMatx(matrix1, matrix2);
    if(isGood){
        matrix1[4][4] = diagonalMatx(matrix1);
        std::cout << "Matrix2 == Matrix2 - true" << std::endl;
    }
    else{
        std::cout << "Matrix2 == Matrix2 - false" << std::endl;
    }
    seeMatx(matrix1);
    
}