#include <stdio.h>
#include "game.h"
#include <stdlib.h> 

#define PLAYERVAL 1
#define BOTVAL 2

class Score {
    private:
        int player_total_score;
        int bot_total_score;
        bool game_complete;
        int *gane_frame;

        // Get references to the game class, the object later being referenced
        Game* game_ptr;
        Game &game_ref;

    public:
        Score();
        //~Score();
        int getScore(bool player);
        void setScore(bool player);

        void checkWin(int *game_state);
}

Score::Score(Game &game) : game_ref(game), game_ptr(&game) {
    player_total_score = 0;
    bot_total_score = 0;
    game_complete = 0;

    game_ref.getState(game_frame);
}

void Score::checkWin(int *game_state) {
    // Checks for a win condition, passing in the state of the game from the Game object
    // Loop through the array and identify any win conditions. 
    // Begin by finding a "seed" from the bottom
}

int main() {
    return 1;
}