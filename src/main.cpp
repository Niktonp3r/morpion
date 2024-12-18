#include "Player.hpp"
#include <iostream>
#include <array>
#include <typeinfo>
#include "utils.hpp"
#include "Mode.hpp"

int main()
{
  std::cout << "Le morpion de Lou !" << std::endl;
  std::array<char, 9> board{'.', '.', '.', '.', '.', '.', '.', '.', '.'};

  draw_game_board(board);
  int choice_mode;

  {
    std::cout << "Choix du mode : " << std::endl;
    std::cout << "1) Classique 2 joueurs (1v1)" << std::endl;
    std::cout << "2) Contre l'IA" << std::endl;
    std::cout << "Choix : ";
    std::cin >> choice_mode;
  } while (choice_mode != 1 && choice_mode != 2);

  if (choice_mode == 1){
    std::cout << "Mode classique : " << std::endl;
    classic_mode(board);
  }
  else {
    std::cout << "Mode avec IA : " << std::endl;
    IA_mode(board);
  }

  return 0;
}
