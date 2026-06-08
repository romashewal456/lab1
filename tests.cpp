#include <iostream>
#include <cassert>
#include "GameEngine.hpp" 

// Тест 1: Перевірка початкового стану гри
void test_InitialState() {
    GameEngine game;
    assert(game.getCurrentPlayer() == 'X'); 
    assert(game.getTotalTurns() == 0);     
    assert(game.checkWinner() == 0);        
    std::cout << "Test InitialState: PASSED\n";
}

// Тест 2: Перевірка виконання коректного ходу
void test_ValidMove() {
    GameEngine game;
    bool success = game.makeMove(5);       
    assert(success == true);                
    assert(game.getTotalTurns() == 1);      
    assert(game.getBoard().getCell(1, 1) == 'X'); 
    std::cout << "Test ValidMove: PASSED\n";
}

// Тест 3: Перевірка блокування некоректного ходу (в уже зайняту клітинку)

void test_InvalidMove() {
    GameEngine game;
    game.makeMove(5);                      
    bool success = game.makeMove(5);       
    assert(success == false);               
    assert(game.getTotalTurns() == 1);     
    std::cout << "Test InvalidMove: PASSED\n";
}

void test_PlayerSwitching() {
    GameEngine game;
    assert(game.getCurrentPlayer() == 'X');
    game.makeMove(1);                       
    game.switchPlayer();                    
    assert(game.getCurrentPlayer() == 'O'); 
    std::cout << "Test PlayerSwitching: PASSED\n";
}

void test_WinCondition_Horizontal() {
    GameEngine game;
    
    game.makeMove(1); game.switchPlayer(); 
    game.makeMove(4); game.switchPlayer();
    game.makeMove(2); game.switchPlayer(); 
    game.makeMove(5); game.switchPlayer();
    game.makeMove(3);                      
    
    assert(game.checkWinner() == 1);        
    std::cout << "Test WinCondition_Horizontal: PASSED\n";
}

int main() {
    std::cout << "--- ЗАПУСК ЮНІТ-ТЕСТІВ (ООП ВЕРСІЯ) ---\n";
    test_InitialState();
    test_ValidMove();
    test_InvalidMove();
    test_PlayerSwitching();
    test_WinCondition_Horizontal();
    std::cout << "Всі ООП-тести успішно пройдені!\n";
    return 0;
}