#include <iostream>

char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char current_marker = 'X';


void drawBoard() {
    std::cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "| ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n-------------\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (slot < 1 || slot > 9 || board[row][col] != ' ') {
        return false;
    }

    board[row][col] = current_marker;
    return true;
}


int checkWinner() {
   
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') 
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') 
            return 1;
    }
    // Перевірка діагоналей
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') 
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') 
        return 1;

    return 0;
}

void swapPlayer() {
    current_marker = (current_marker == 'X') ? 'O' : 'X';
}

int main() {
    std::cout << "Вітаємо у грі Хрестики-Нулики!\n";
    drawBoard();
    
    int player_won = 0;
    int total_turns = 0;

    while (player_won == 0 && total_turns < 9) {
        int slot;
        std::cout << "Гравець " << current_marker << ", виберіть клітинку (1-9): ";
        std::cin >> slot;

        if (!placeMarker(slot)) {
            std::cout << "Невірний хід! Спробуйте ще раз.\n";
            continue;
        }

        drawBoard();
        player_won = checkWinner();
        
        if (player_won == 1) {
            std::cout << "Вітаємо! Гравець " << current_marker << " переміг!\n";
            break;
        }

        swapPlayer();
        total_turns++;
    }

    if (player_won == 0) {
        std::cout << "Нічия!\n";
    }

    return 0;
}