#include <iostream>

std::string isCorrectLenFirst(int len){
    std::string isCorrect = "";
    if (len >=1 && len <= 64)
        isCorrect = 't';
    else
        isCorrect = 'f';
    return isCorrect;
}


std::string isCorrectLenSec(int len){
    std::string isCorrect = "";
    if (len >=1 && len <= 63)
        isCorrect = 't';
    else
        isCorrect = 'f';
    return isCorrect;
}

std::string isCorrectPoint(std::string email){
    std::string isCorrect = "";
    if(email[0] == '.'){
        isCorrect = 'f';
    }
    if(email[email.length() - 1] == '.'){
        isCorrect = 'f';
    }   
    for(int i = 0; i < email.length() - 1; i++){
        if(email[i] == '.' && email[i+1] == '.'){
            isCorrect = 'f';
        }
    }
    return isCorrect;
}

std::string isCorrectyntax(std::string email){
    std::string isCorrect = "";
    std::string symbols = "!#$%&'*+-/=?^_`{|}~.";
    for(int i = 0; i < email.length(); i++){
        for (int n = 0; n < symbols.length(); n++){
            if(int(email[i])== int(symbols[n])){
                isCorrect = "t";
                break;
            }
        }
        if(int(email[i])>64 && int(email[i]) < 90 || int(email[i]) > 96 && int(email[i]) < 123){
            isCorrect = "t";
            break;
        }
    }
    return isCorrect;
}


std::string isDog(std::string email){
    std::string isCorrect = "";
    int dog = 0;
    for (int i = 0; i < email.length(); i++){
        if (email[i] == '@')
            dog++;
    }
    if(dog == 1)
        isCorrect = 't';
    else
        isCorrect = 'f';
    return isCorrect;
}
//create string answer's
std::string fullActiveVer(std::string emailBefore, std::string emailAfter, std::string email){
    std::string isCorrect;
    for(int i = 0; i < 1; i++){
        isCorrect  += isDog(email);
        if (isCorrect == "f"){
            break;
        }
        isCorrect  += isCorrectLenFirst(emailBefore.length());
        isCorrect  += isCorrectLenSec(emailAfter.length());
        isCorrect  += isCorrectPoint(emailBefore);
        isCorrect  += isCorrectPoint(emailAfter);
        isCorrect  += isCorrectyntax(emailBefore);
    }
    return isCorrect;
}
bool fullVerification(std::string isCorrect){
    
    bool answer = true;
    for(int i = 0; i < isCorrect.length(); i++){
        if(isCorrect[i] == 'f')
        answer = false;
    }
    return answer;
}

void answer(bool isCorrect){
    if(isCorrect)
        std::cout << "Yes";
    else
        std::cout << "No";

}
int main(){
    std::string email;
    std::cout << "Enter your email - ";
    std::cin >> email;
    std::string emailAfter = "", emailBefore = "";
    std::string isCorrect = "";

    //divide the email into 2 values
    for (int i =0; i < email.length(); i++){
        if(email[i] == '@'){
            i++;
            for(;i < email.length(); i++){
                emailAfter+=email[i];
            }
            break;
        }
    }
    for (int i =0; i < email.length(); i++){
        if(email[i] == '@'){
            break;
        }
        else{
            emailBefore+=email[i];
        }
    }


    answer(fullVerification(fullActiveVer(emailBefore, emailAfter, email)));

}