#include <stdio.h>
#include <stdlib.h> 

class Game {
    private: 
        int board_width;
        int board_height;

        bool player_turn;

        int *game_state;
    public: 
        Game();
        Game(int width, int height);
        //~Game();
        void getState(int* state_frame);
        void getCol(int index, int* col);
        void setCol(int index, int* state);
        bool makeMove(int col, bool player); 
};

// Overload constructors to give options
Game::Game() {
    // Set up the game state
    board_height = 6; 
    board_width = 8;
    game_state[board_width*board_height] = {0};
    player_turn = 0;
};

Game::Game(int width, int height) {
    // Set up the game state
    board_height = width; 
    board_width = height;
    game_state[board_width*board_height] = {0};
    player_turn = 0;
};

// Deconstructor
// Game::~Game() {

// };

void Game::getState(int* state_frame) {
    //int* state_frame = new int[board_width*board_height];
    for (int i = 0; i < board_width; i++) {
        for (int j = 0; j < board_height; j++) {
            state_frame[i*board_width + j] = game_state[i*board_width + j];
        }
    }
    //return state_frame;
};

void Game::getCol(int index, int* col) {
    //int* col = new int[board_height]; 
    for (int i = 0; i < board_height; i++) {
        col[i] = game_state[index + i*board_width];
    }
    //return col;
};

void Game::setCol(int index, int* modified_col) {
    for (int i = 0; i < board_height; i++) {
        game_state[index + i*board_width] = modified_col[i];
    }
};

bool Game::makeMove(int col, bool player) {
    try {
        int col_data[board_height*board_width] = {0};
        getCol(col, col_data);
        int i;
        while (col_data[i] == 0 | i < board_height - 1) {
            i++;
        }
        col_data[i] = player ? 1 : 2;
        setCol(col, col_data);
        return 1;
    } catch (...) {
        printf("Move Failed...\n");
        return 0;
    }
};

int main() {
    return 0;
};