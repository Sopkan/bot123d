#include <iostream>

int main(){
    std::string house[10];
    for(int i = 0; i < 10; i++){
        std::cout << "Enter name for " << i << " house -";
        std::cin >> house[i];
    }
    int num;
    std::cin >> num;
    std::cout << house[num];
} 