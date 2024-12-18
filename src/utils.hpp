#pragma once
#include <array>
#include "Player.hpp"

void draw_game_board(std::array<char, 9> board);
bool is_end(std::array<char, 9> board);
bool is_winner(Player player_1, Player player_2, std::array<char, 9> board);
void choose_random_player_start(Player &player_1, Player &player_2);