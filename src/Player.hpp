#pragma once
#include <string>
#include <array>

struct Player {
    std::string name;
    int choice;
    char symbol;
    bool can_play{false};

    bool win(std::array<char, 9> board);
};

Player create_player();
Player create_IA(Player player);