#include <iostream>
#include <cassert>

float travelTime(float distance, float speed)
{
    assert(speed > 0);
    float time = distance / speed;
    return time;
}

int main(){
    float distance, speed;
    std::cout << "Enter speed - ";
    std::cin >> speed;
    std::cout << "Enter distance - ";
    std::cin >> distance;
    float time = travelTime(distance, speed);
    std::cout << time;
}