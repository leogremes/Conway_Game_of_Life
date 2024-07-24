#include "game_of_life.h"

//initialize matrices
void initialize(int (*one)[NCOLS], int (*two)[NCOLS], int argc)
{
    int n;
    srand(time(NULL));
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            if (argc > 1) {
                n = rand();
                if (n > (RAND_MAX / 100) * PROBABILITY)
                    one[i][j] = 0;
                else  
                    one[i][j] = 1;
            }
            else
                one[i][j] = 0;
            two[i][j] = 0;
        }
    }
}

//invert pointers of current and next state between matrices
void invert_pointers(int (**one)[NCOLS], int (**two)[NCOLS])
{
    int (*aux)[NCOLS];
    aux = *one;
    *one = *two;
    *two = aux;
}

//draw_rectangles in the window
void draw_rectangles(SDL_Renderer* renderer, SDL_Rect* rect, int r, int g, int b, int a,
                     int (* curr)[NCOLS], int alive)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            if (curr[i][j] == alive) {
                rect->x = (CELL_SIZE * i) + BORDER_SIZE;
                rect->y = (CELL_SIZE * j) + BORDER_SIZE;
                SDL_RenderFillRect(renderer, rect);
            }
        }
    }
}