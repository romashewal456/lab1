#pragma once
#include <vector>

class Board {
private:
    std::vector<std::vector<char>> grid;

public:
    Board() {
        grid = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
    }

    char getCell(int row, int col) const {
        return grid[row][col];
    }

    bool placeMarker(int slot, char marker) {
        int row = (slot - 1) / 3;
        int col = (slot - 1) % 3;

        if (slot < 1 || slot > 9 || grid[row][col] != ' ') {
            return false;
        }

        grid[row][col] = marker;
        return true;
    }

    void reset() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = ' ';
            }
        }
    }
};