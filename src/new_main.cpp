#include "GameEngine.hpp"
#include "ConsoleUI.hpp"

int main() {
    GameEngine game;
    ConsoleUI ui;

    ui.showMessage("Вітаємо у грі Хрестики-Нулики (ООП версія)!");
    ui.displayBoard(game.getBoard());

    while (true) {
        int slot = ui.getPlayerInput(game.getCurrentPlayer());

        if (!game.makeMove(slot)) {
            ui.showMessage("Невірний хід! Спробуйте ще раз.");
            continue;
        }

        ui.displayBoard(game.getBoard());
        int status = game.checkWinner();

        if (status == 1) {
            ui.showMessage("Вітаємо! Гравець " + std::string(1, game.getCurrentPlayer()) + " переміг!");
            break;
        } else if (status == -1) {
            ui.showMessage("Нічия!");
            break;
        }

        game.switchPlayer();
    }

    return 0;
}