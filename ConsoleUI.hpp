#pragma once
#include <iostream>
#include "GameEngine.hpp"

class ConsoleUI {
public:
    void displayBoard(const Board& board) const {
        std::cout << "-------------\n";
        for (int i = 0; i < 3; i++) {
            std::cout << "| ";
            for (int j = 0; j < 3; j++) {
                std::cout << board.getCell(i, j) << " | ";
            }
            std::cout << "\n-------------\n";
        }
    }

    int getPlayerInput(char playerMarker) const {
        int slot;
        std::cout << "Гравець " << playerMarker << ", виберіть клітинку (1-9): ";
        std::cin >> slot;
        return slot;
    }

    void showMessage(const std::string& message) const {
        std::cout << message << std::string("\n");
    }
};