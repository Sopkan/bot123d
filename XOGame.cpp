#include <iostream>

void seeField(char field[3][3]){
    for(int i = 0; i < 3; i++){
        std::cout << "|";
        for(int j = 0; j < 3; j++){
            std::cout<<field[i][j]<< "|";
        }
        std::cout << std::endl;
    }
}
bool whoIsWin(char field[3][3], char user){
    bool win = false;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0 && field[i][j] == user && field[i][j+1] == user && field[i][j+2] == user){
                win = true;
                break;
            }
            else if(i == 0 && field[i][j] == user && field[i+1][j] == user && field[i+2][j] == user){
                win = true;
                break;
            }
        }
    }
    return win;
}
int main(){
    bool win = false;
    char winner;
    char x = 'X', o = '0';
    char field[3][3] = {    {' ', ' ', ' '},
                            {' ', ' ', ' '},
                            {' ', ' ', ' '}};
    while(win != true){
        bool move = true;
        int xPos, yPos;
        std::cout << "Enter your move for X - ";
        std::cin >> xPos >> yPos;
        while(move){
            if(field[xPos][yPos] == ' ' && xPos < 3 && xPos >=0 && yPos < 3 && yPos >=0){
                field[xPos][yPos] = x;
                move = false;
            }

            else{
                std::cout << "This pos is not good. Enter your move for X - ";
                std::cin >> xPos >> yPos;
            }
            
        }
        win = whoIsWin(field, x);
        seeField(field);
        if(win){
            winner = x;
            break;
        }
        std::cout << "Enter your move for 0 - ";
        std::cin >> xPos >> yPos;
        move = true;
        while(move){
            if(field[xPos][yPos] == ' ' && xPos < 3 && xPos >=0 && yPos < 3 && yPos >=0){
                field[xPos][yPos] = o;
                move = false;
            }

            else{
                std::cout << "This pos is not good. Enter your move for 0 - ";
                std::cin >> xPos >> yPos;
            }
            
        }
        seeField(field);
        win = whoIsWin(field, o);
        if(win){
            winner = o;
            break;
        }

    }
    std::cout << "Winner is " << winner;
}