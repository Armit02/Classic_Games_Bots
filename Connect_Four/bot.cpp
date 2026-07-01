#include <stdio.h>
#include "game.h"
#include "score.h"
#include <stdlib.h> 

#define PLAYERVAL 1
#define BOTVAL 2

class Bot {
    private:
        int *game_frame
        int height, width, size;
        Game &game_ref;
    public:
        Bot(Game &game);
        int makeDecision();
        void makeMove();
}

Bot::Bot(Game &game) : game_ref(game) {
    // Establish the connection to the game
    height = game_ref.getHeight();
    width = game_ref.getWidth();
    size = height * width;
}

int makeDecision() {
    // Get the current frame
    game_frame = int new[size];
    game_ref.getState(game_frame);
    // Recursively find the best path

    // TODO: Recursive scoring function to determine best column to take
}

/*
Bot Structure

- Sense: Analyse the current state

- Think: Develop a tree of possible moves and their concequences, discarding moves which are adverse
    This tree should go at least one layer deep into player moves, thereby eliminating the chance the bot 'lets' a player win
    Rules: 
        - If you can win, do so immediatley
        - If you can't win but the player can, prevent them from winning 
        - If you have a string of tokens that can be extended, do so
            - No specific focus for first iteration
        - If nothing else can be done, open up a new column
        - If all columns expended and no other moves can be done, attempt to stack vertically
        - If completely blocked, simply stack on top

- Act: Make a move using the game.makeMove method

*/