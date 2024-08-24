#include <iostream>

bool isPoint(std::string ip){
    int point = 0;
    for (int i = 0; i < ip.length(); i++){
        if (ip[i] == '.'){
            point++;
        }
        if(ip[i] == '.' && ip[i+1] == '.'){
            return false;
        }
    }
    if(point == 3)
        return true;
    else
        return false;    
}

bool isNum(std::string ip){
    for (int i = 0; i < ip.length(); i++){
        if (ip[i] == '.'){
            continue;
        } 
        else if(int(ip[i]) > 47 && int(ip[i]) < 58){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
bool howManyZero(std::string ip){
    for(int i = 0; i < ip.length()-1; i++){
        if(ip[i] == '0' && ip[i+1] == '0' || ip[i] == '.' && ip[i+1] == '0' && ip[i+2] != '.'){
            return false;
        }
    }
    return true;
}

bool ipToInt(std::string ip){
    int num = stoi(ip);
    if (num > 255){
        return false;
    }
    else
        return true;
}

bool checkOut(std::string ip){
    std::string num = "";
    for(int i = 0; i < ip.length(); i++){
    num += ip[i];
    if(ip[i] == '.' || i == ip.length() -1){
        ipToInt(num);
        if (ipToInt(num)){
            num = "";
            continue;
        }
        else
            return false;

    }
    }   
    return true;
}


int main(){
    std::string ip;
    std::cout << "Enter your ip - ";
    std::cin >> ip;
    if(isPoint(ip) && isNum(ip) && howManyZero(ip) && checkOut(ip)){
        std::cout << "Valid" << std::endl;
    }
    else    
        std::cout << "Invalid" << std::endl;
}