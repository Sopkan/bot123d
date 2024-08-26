#include <iostream>

int main(){
    float numbers[15];
    for(int i = 0; i < 15; i++){
        std::cin >> numbers[i];
    }
    for(int i = 0; i < 15; i++){
        for(int n = 0; n < 15; n++){
            if(numbers[n] < numbers[n+1]){
                std::swap(numbers[n], numbers[n+1]);
            }
        }
    }
    for(int i = 0; i < 15; i++)
        std::cout << numbers[i] << " ";
}