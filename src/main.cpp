#include "Player.hpp"
#include <iostream>
#include <array>
#include <typeinfo>
#include "utils.hpp"
#include "Mode.hpp"

int main()
{
  std::cout << "Hello lou la skateuse!" << std::endl;
  std::array<char, 9> board{'.', '.', '.', '.', '.', '.', '.', '.', '.'};

  draw_game_board(board);

  // TODO :Choisir le mode.

  classic_mode(board);
  // IA mode

  return 0;
}
