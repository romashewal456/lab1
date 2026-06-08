#pragma once
#include "Board.hpp"

class GameEngine {
private:
    Board board;
    char currentMarker;
    int totalTurns;

public:
    GameEngine() : currentMarker('X'), totalTurns(0) {}

    const Board& getBoard() const { return board; }
    char getCurrentPlayer() const { return currentMarker; }
    int getTotalTurns() const { return totalTurns; }

    bool makeMove(int slot) {
        if (board.placeMarker(slot, currentMarker)) {
            totalTurns++;
            return true;
        }
        return false;
    }

    void switchPlayer() {
        currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    }

    int checkWinner() const {
       
        for (int i = 0; i < 3; i++) {
            if (board.getCell(i, 0) == board.getCell(i, 1) && board.getCell(i, 1) == board.getCell(i, 2) && board.getCell(i, 0) != ' ') 
                return 1;
            if (board.getCell(0, i) == board.getCell(1, i) && board.getCell(1, i) == board.getCell(2, i) && board.getCell(0, i) != ' ') 
                return 1;
        }
        // Перевірка діагоналей
        if (board.getCell(0, 0) == board.getCell(1, 1) && board.getCell(1, 1) == board.getCell(2, 2) && board.getCell(0, 0) != ' ') 
            return 1;
        if (board.getCell(0, 2) == board.getCell(1, 1) && board.getCell(1, 1) == board.getCell(2, 0) && board.getCell(0, 2) != ' ') 
            return 1;

        if (totalTurns == 9) return -1;
        return 0; 
    }
};