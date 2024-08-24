#include <iostream>

int minMaxSymbol(int min, int max, char symbol, int code){
    if(int(symbol) >= min && int(symbol) <= max){
            code = code % 26;
            if(int(symbol) + code > max){
                int secCode = (int)symbol + code - max;
                symbol = char(min + secCode);
            }else{
                symbol = char(int(symbol) + code);
            }
    }
    return symbol;
}
std::string cesar(std::string word, int code){
    int len = word.length();
    for(int i = 0; i < len; i++)
    {
        if (int(word[i]) >=65 && int(word[i]) <= 90)
        {
            word[i] = minMaxSymbol(65, 90, word[i], code);
        }
        else if (int(word[i]) >=97 && int(word[i]) <= 122)
        {
            word[i] = minMaxSymbol(97, 122, word[i], code);
        }
        else if(int(word[i]) + code > 127){
            code = (int)(word[i]) + code - 127;
            word[i] = (char)code;
        }else{
            word[i] = char(int(word[i] + code));
        }



    }    
    return word;
}

int main(){
    int code;
    std::string message;
    std::cout << "Input your message and code - ";
    std::cin >> message >> code;
    std::cout << cesar(message, code);
}