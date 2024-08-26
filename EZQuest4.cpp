#include <iostream>

int main(){
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int x = numbers[0];
    int copy = 0;
    for(int i = 0; i < 15; i++){
        x = numbers[i] < x ? numbers[i] : x;
        for(int n = 0; n < 15; n++){
            if (n == i)
                continue;
            if(numbers[i] == numbers[n]){
                copy = numbers[i];
            }
        }
    }
    std::cout << "In this numbers X - " << x << ", and copy number - " << copy;
}