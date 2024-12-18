#include "Mode.hpp"
#include <iostream>

void classic_mode(std::array<char, 9> board)
{
    Player player_1;
    Player player_2;

    player_1 = create_player();
    player_2 = create_player();

    choose_random_player_start(player_1, player_2);
    while (!is_winner(player_1, player_2, board))
    {
        if (player_1.can_play)
        {
            std::cout << "A ton tour " << player_1.name << " : " << std::endl;
            do
            {
                std::cout << player_1.name << " : Choisir un nombre " << std::endl;
                std::cin >> player_1.choice;
            } while (!valid_choice(player_1, player_2, board));

            board[player_1.choice] = player_1.symbol;
            player_1.can_play = false;
            player_2.can_play = true;
        }
        else if (player_2.can_play)
        {
            std::cout << "A ton tour " << player_1.name << " : " << std::endl;
            do
            {
                std::cout << player_2.name << " : Choisir un nombre " << std::endl;
                std::cin >> player_2.choice;
            } while (!valid_choice(player_2, player_1, board));

            board[player_2.choice] = player_2.symbol;
            player_2.can_play = false;
            player_1.can_play = true;
        }
        draw_game_board(board);
    }
    std::cout << "Fin de la partie" << std::endl;
}

void IA_mode(std::array<char, 9> board)
{

    Player player;
    Player IA;

    player = create_player();
    IA = create_IA(player);

    choose_random_player_start(player, IA);
    while (!is_winner(player, IA, board))
    {
        if (player.can_play)
        {
            std::cout << "A ton tour " << player.name << " : " << std::endl;
            do
            {
                std::cout << player.name << " : Choisir un nombre " << std::endl;
                std::cin >> player.choice;
            } while (!valid_choice(player, IA, board));

            board[player.choice] = player.symbol;
            player.can_play = false;
            IA.can_play = true;
        }
        else if (IA.can_play)
        {
            std::cout << "A ton tour " << IA.name << " : " << std::endl;
            do
            {
                std::srand(std::time(nullptr));
                int random_choice{std::rand() % 9};
                IA.choice = random_choice;
                
            } while (!valid_choice(IA, player, board));

            board[IA.choice] = IA.symbol;
            IA.can_play = false;
            player.can_play = true;
        }
        draw_game_board(board);
    }
    std::cout << "Fin de la partie" << std::endl;
}
