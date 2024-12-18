#include "Player.hpp"
#include <iostream>
#include <array>
#include <typeinfo>

void draw_game_board(std::array<char, 9> board) {

  for (int i = 0; i < board.size(); ++i) {
    // Ajouter une barre à gauche de chaque point
    std::cout << "| " << board[i] << " ";

    // Après chaque troisième élément, ajouter une barre de droite et passer à
    // la ligne suivante
    if ((i + 1) % 3 == 0) {
      std::cout << "|\n";
    }
  }
}

bool is_end(std::array<char, 9> board){
  for (int i{0}; i < board.size(); i++)
  {
     if (int(board[i] - '0')  == i){
      return false;
    }
  }
  return true;
}


bool is_winner(Player player_1, Player player_2, std::array<char, 9> board)
{
  if (player_1.win(board)){
        std::cout<< player_1.name << " a gagné"<<std::endl;
    return true;
  }
  else if (player_2.win(board)){
    std::cout<< player_2.name << " a gagné"<<std::endl;
    return true;
  }
  else if (is_end(board))
  {
    std::cout << "Match nul" << "\n";
    return true;
  }

  return false;
}


int main() {
  std::cout << "Hello lou la skateuse!" << std::endl;
  std::array<char, 9> board{'0','1', '2', '3', '4', '5', '6', '7', '8'};
  
  draw_game_board(board);

  Player player_1;
  Player player_2;

  // ) Initialiser les joueurs.
  player_1 = create_player();
  player_2 = create_player();

  // 2) Les joueurs jouent tour à tour, ils choisissent  positions de 0 à 8 sur
  //Le joueur  commence
  player_1.can_play = true; //TODO : faire un random pour plus stylé!
  
  while(!is_winner(player_1, player_2, board))
  {
    if (player_1.can_play)
    {
      std::cout << player_1.name<< " : Choisir un nombre " << std::endl;
      std::cin>> player_1.choice;

      // if (board[player_1.choice] == player_1.symbol || board[player_1.choice] == player_2.symbol){
    // break ?? ca marche pas dcp jsp 
    // }
      board[player_1.choice] = player_1.symbol;
      player_1.can_play = false;
      player_2.can_play = true;

    }
    else if (player_2.can_play)
    {
      std::cout <<player_2.name<< " : Choisir un nombre " << std::endl;
      std::cin>> player_2.choice;

      board[player_2.choice] = player_2.symbol;
      player_2.can_play = false;
      player_1.can_play = true;
    }
    draw_game_board(board);
  }
  std::cout << "Fin de la partie" << "\n";



  

  


 
  // le board. 3) On affiche le nouveau board avec le symbol du joueur dessus.
  // 4) A chaque nouveau tour, on check s'il y a pas un joueur qui a gagné. Si
  // oui, fin du jeu.

  return 0;
}

// a rajouter : 
// ) que on peut pas choisir le meme nombre 2 fois
// 2) que la partie se termine si toutes les cases sont remplies
// 3) ia