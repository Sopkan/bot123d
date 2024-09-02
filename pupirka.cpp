#include <iostream>

bool fullPop(bool matrix[12][12]){
    for(int i = 0; i < 12; i++){
        for(int k = 0; k < 12; k++){
            matrix [i][k] = true;
        }
    }
    return matrix[12][12];
}

bool popEnd(bool pop[12][12], int startPosX, int startPosY, int endPosX, int endPosY){
    if(startPosY < endPosY){
        for(int i = startPosY; i < endPosY; i++){
            if(startPosX < endPosX){
                for(int j = startPosX; j < endPosX; j++){
                    pop[i][j] = false;
                    std::cout<< "POP!"<< std::endl;
                }
            }
            else{
                for(int j = endPosX; j < startPosX; j++){
                    pop[i][j] = false;
                    std::cout<< "POP!"<< std::endl;
                }
            }
                
            }
    }
    else{
        for(int i = endPosY; i < startPosY; i++){
            if(startPosX < endPosX){
                for(int j = startPosX; j < endPosX; j++){
                    pop[i][j] = false;
                    std::cout<< "POP!"<< std::endl;
                }
            }
            else{
                for(int j = endPosX; j < startPosX; j++){
                    pop[i][j] = false;
                    std::cout<< "POP!"<< std::endl;
                }
            }
            }
    }
    
    return pop[12][12];
}
bool popIsTrue(bool pop[12][12]){
    bool isGood = false;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            if(pop[i][j] == true){
                isGood = true;
                break;
            }
        }
    }
    return isGood;
}
void seePop(bool pop[12][12]){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            std::cout<< pop[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}
int userEnter(){
    bool correct = true;
    int max = 12, min = 0;
    int x;
    while(correct){
        std::cout << "Enter pos: " <<std::endl;
        std::cin >> x;
        if(x >= min && x <= 12)
            correct = false;
        else{
            std::cout<< "Pos is not good. Enter new pos." << std::endl;
        }
    }
    return x;
}

int main(){
    bool isGood = true;
    int startPosX, startPosY, endPosX, endPosY;
    bool pop[12][12];
    pop[12][12] = fullPop(pop);
    while(isGood){
        std::cout << "Enter startPos." << std::endl;
        startPosX = userEnter();
        startPosY = userEnter();
        std::cout << "Enter endPos." << std::endl;
        endPosX = userEnter();
        endPosY = userEnter();
        pop[12][12] = popEnd(pop, startPosX, startPosY, endPosX, endPosY);
        seePop(pop);
        isGood = popIsTrue(pop);
    }
    std::cout<<"Pop is end. Buy new pop!";
}