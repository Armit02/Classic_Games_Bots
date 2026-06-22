#ifndef SCORE_H

#define SCORE_H

typedef struct {
    int vert;
    int left_diag; 
    int right_diag; 
    int right;
} directions;

class Score {
    private:
        int player_total_score;
        int bot_total_score;
        bool game_complete;
        int *game_frame;

        int width;
        int height; 
        int size;

        // Get references to the game class, the object later being referenced
        Game* game_ptr;
        Game &game_ref;

    public:
        Score(Game &game);
        //~Score();
        int getScore(bool player);
        void setScore(bool player);

        void checkWin();
};

#endif