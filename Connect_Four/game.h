#ifndef GAME_H

#define GAME_H

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
        int getWidth();
        int getHeight();
        void getState(int* state_frame);
        void getCol(int index, int* col);
        void setCol(int index, int* state);
        bool makeMove(int col, bool player); 

        void displayState();
};

#endif