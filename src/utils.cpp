#include "utils.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// dessine la grille de jeu.
void draw_game_board(std::array<char, 9> board)
{
  for (int i = 0; i < board.size(); ++i)
  {
    std::cout << "| " << board[i] << " ";
    if ((i + 1) % 3 == 0)
    {
      std::cout << "|" << std::endl;
    }
  }
}

// vérifie si la grille est totalement remplie.
bool is_end(std::array<char, 9> board)
{
  for (int i{0}; i < board.size(); i++)
  {
    if (board[i] == '.')
    {
      return false;
    }
  }
  return true;
}

// vérifie si il y a un gagnant ou pas.
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

// Choose a random player to start
void choose_random_player_start(Player &player_1, Player &player_2)
{
  std::srand(std::time(nullptr));
  int random_variable{std::rand() % 2};

  if (random_variable == 1)
  {
    player_1.can_play = true;
  }
  else
  {
    player_2.can_play = true;
  }
}

bool valid_choice(Player player_1, Player player_2, std::array<char, 9> board)
{
  if (board[player_1.choice] == player_1.symbol || board[player_1.choice] == player_2.symbol)
  {
    if (player_1.name != "_IA_")
    {
      std::cout << "Case déjà prise ! " << std::endl;
    }
    return false;
  }
  else if (player_1.choice < 0 || player_1.choice > 8)
  {
    std::cout << "Tu joues où là ?" << std::endl;
    return false;
  }

  return true;
}