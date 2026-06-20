#include <stdio.h>
#include <stdlib.h> 

#define PLAYERVAL 1
#define BOTVAL 2

#define DEFAULT_WIDTH 8
#define DEFAULT_HEIGHT 6

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

        void displayState();
};

// Overload constructors to give options
Game::Game() {
    // Set up the game state
    board_height = DEFAULT_HEIGHT; 
    board_width = DEFAULT_WIDTH;
    game_state = new int [board_width*board_height];
    for (int i = 0; i < board_height*board_width; i++) {
        game_state[i] = 0;
    }
    player_turn = 0;
};

Game::Game(int width, int height) {
    // Set up the game state
    board_height = width; 
    board_width = height;
    game_state = new int [board_width*board_height];
    for (int i = 0; i < board_height*board_width; i++) {
        game_state[i] = 0;
    }
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
    int col_data[board_height];
    getCol(col, col_data);
    int target = -1;
    for (int i = board_height - 1; i >= 0; i--) {
        if (col_data[i] == 0) {
            target = i;
            break;
        }
    }
    
    if (target == -1) {
        printf("\n Move Failed! Column is Full\n");
        return 0;
    } else {
        col_data[target] = player ? PLAYERVAL : BOTVAL;
    }
    setCol(col, col_data);
    return 1;
};

void Game::displayState() {
    printf("Game State ----\n\n");
    for (int i = 0; i < board_height; i++) {
        for (int j = 0; j < board_width; j++) {
            printf("%d",game_state[i*board_width + j]);
        }
        printf("\n");
    }
}

int main() {
    Game newGame;
    newGame.displayState();
    int choice; 
    while (1) {
        printf("Enter the column to place a chip\n");
        scanf("%d", &choice);
        newGame.makeMove(choice, 1);
        newGame.displayState();
    }
    return 1;
};