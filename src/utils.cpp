#include "utils.hpp"
#include <iostream>

//dessine la grille de jeu.
void draw_game_board(std::array<char, 9> board)
{
  for (int i = 0; i < board.size(); ++i)
  {
    std::cout << "| " << board[i] << " ";
    if ((i + 1) % 3 == 0)
    {
      std::cout << "|"<< std::endl;
    }
  }
}

//vérifie si la grille est totalement remplie.
bool is_end(std::array<char, 9> board)
{
  for (int i{0}; i < board.size(); i++)
  {
    if (int(board[i] - '0') == i)
    {
      return false;
    }
  }
  return true;
}

//vérifie si il y a un gagnant ou pas.
bool is_winner(Player player_1, Player player_2, std::array<char, 9> board)
{
  if (player_1.win(board))
  {
    std::cout << player_1.name << " a gagné" << std::endl;
    return true;
  }
  else if (player_2.win(board))
  {
    std::cout << player_2.name << " a gagné" << std::endl;
    return true;
  }
  else if (is_end(board))
  {
    std::cout << "Match nul" << std::endl;
    return true;
  }

  return false;
}