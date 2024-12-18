#include "Player.hpp"
#include <iostream>
#include <array>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include "utils.hpp"


int main()
{
  std::cout << "Hello lou la skateuse!" << std::endl;
  std::array<char, 9> board{'0', '1', '2', '3', '4', '5', '6', '7', '8'};

  draw_game_board(board);

  Player player_1;
  Player player_2;

  player_1 = create_player();
  player_2 = create_player();

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

  while (!is_winner(player_1, player_2, board))
  {
    if (player_1.can_play)
    {
      std::cout << "A ton tour " << player_1.name << " : " << std::endl;
      std::cout << player_1.name << " : Choisir un nombre " << std::endl;
      std::cin >> player_1.choice;

      board[player_1.choice] = player_1.symbol;
      player_1.can_play = false;
      player_2.can_play = true;
    }
    else if (player_2.can_play)
    {
      std::cout << player_2.name << " : Choisir un nombre " << std::endl;
      std::cin >> player_2.choice;

      board[player_2.choice] = player_2.symbol;
      player_2.can_play = false;
      player_1.can_play = true;
    }
    draw_game_board(board);
  }
  std::cout << "Fin de la partie" << std::endl;

  return 0;
}


// ) que on peut pas choisir le meme nombre 2 fois
// 3) ia