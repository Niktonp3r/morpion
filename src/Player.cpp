#include "Player.hpp"
#include <iostream>

Player create_player()
{
    Player player;
    std::cout << "Entrez un nom : " << std::endl;
    std::cin>> player.name;
    std::cout << "Entrez un symbole pour " << player.name << " : " << std::endl;
    std::cin>> player.symbol;
    return player;
}

bool Player::win(std::array<char, 9> board)
{
    //horizontal
    for (int i=0; i < 3; ++i){
        // 0 1 2 -> i = 0 
        // 3 4 5 -> i = 1 
        // 6 7 8 -> i = 2 
        // (i*3) (i*3 + 1) (i*3 + 2)
    
        if (board[i*3]== symbol && board[i*3+1]== symbol && board[i*3+2] == symbol){ 
            return true;
        }

        // 0 1 2 -> i = 0 
        // 3 4 5 -> i = 1 
        // 6 7 8 -> i = 2 
        // (i) (i+3) (i+6)
        if (board[i]== symbol && board[i+3]== symbol && board[i+6] == symbol){ 
            return true;
        }      
    }

    if (board[0]== symbol && board[4]== symbol && board[8] == symbol){ 
            return true;
    }
    if (board[2]== symbol && board[4]== symbol && board[6] == symbol){ 
            return true;
    }

    return false;
}