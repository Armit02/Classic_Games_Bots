#include <stdio.h>
#include "game.h"
#include "score.h"
#include <stdlib.h> 

#define PLAYERVAL 1
#define BOTVAL 2

Score::Score(Game &game) : game_ref(game), game_ptr(&game) {
    player_total_score = 0;
    bot_total_score = 0;
    game_complete = 0;

    height = game_ref.getHeight();
    width = game_ref.getWidth();
    size = height * width;
}

void Score::checkWin() {
    // Checks for a win condition, passing in the state of the game from the Game object
    // Loop through the array and identify any win conditions. 
    // Begin by finding a "seed" from the bottom
    int index;
    directions dirs;
    dirs.vert = 1; 
    dirs.left_diag = 1;
    dirs.right_diag = 1; 
    dirs.right = 1;
    bool win_state = 0;

    // Get the frame at this instant
    game_frame = new int[size];
    game_ref.getState(game_frame);

    for (int i = height; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            // Look for an intial value
            // Define index initially to reduce cache eviction
            index = i*width + j;
            if (game_frame[index] == 1) {
                // User token present
                // Assume this is the leftmost in a pattern
                // If j is too high, a right win is impossible 
                if (j >= (width - 3)) {
                    dirs.right, dirs.right_diag = 0;
                }
                // If j is too low a left diagonal is impossible
                if (j <= 3) {
                    dirs.left_diag = 0;
                }
                // If i too low, vertical win is impossible
                if (i <= 3) {
                    dirs.vert = 0;
                }

                //printf("Checking:\nVertical %d\nLeft Diagonal %d \nRight Diagonal %d\nRight %d\n",dirs.vert,dirs.left_diag,dirs.right_diag,dirs.right);

                // If at this stage, a win is possible
                if (dirs.vert == 1) {
                    for (int k = i - 3; k < i; k++) {
                        if (!game_frame[k*width + j]) {
                            break;
                        } 
                        win_state = 1;
                    }
                }

                if (dirs.left_diag == 1) {
                    for (int k = i - 3; k < i; k++) {
                        // Potentially overcomplicated check
                        if (!game_frame[k*width + j - (i - k)]) {
                            break;
                        }
                        win_state = 1;
                    }
                }

                if (dirs.right_diag == 1) {
                    for (int k = i - 3; k < i; k++) {
                        // Potentially overcomplicated check
                        if (!game_frame[k*width + j + (i - k)]) {
                            break;
                        } 
                        win_state = 1;
                    }
                }

                if (dirs.right == 1) {
                    for (int k = j + 3; k > j; k--) {
                        if (!game_frame[i*width + k]) {
                            break;
                        } 
                        win_state = 1;
                    }
                }
                // TODO: The rest of the checks
                // Save previous win conditions to identify multiple
                // printf("--Win Condition: %d--\n",win_state);

                if (win_state) {
                    printf("-- PLAYER WIN!! -- At index %d\n\n", index);
                    return;
                }
            }
        }
    }
}
