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

Player create_IA(Player player)
{
    Player IA_player;
    IA_player.name = "_IA_";
    if (player.symbol == 'X')
        IA_player.symbol = 'O';
    else
        IA_player.symbol = 'X';
    return IA_player;
}

bool Player::win(std::array<char, 9> board)
{
    for (int i=0; i < 3; ++i){
        if (board[i*3]== symbol && board[i*3+1]== symbol && board[i*3+2] == symbol){ 
            return true;
        }
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