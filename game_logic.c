#include "game_of_life.h"

//invert cell state if the simulation is paused
void invert_cell(int (*curr)[NCOLS], SDL_MouseButtonEvent click)
{
    int i = click.x / CELL_SIZE;
    int j = click.y / CELL_SIZE;
    if (curr[i][j] == 1)
        curr[i][j] = 0;
    else
        curr[i][j] = 1;
}

//count alive neighbours to determine next state
int count_alive_neighbours(int (*curr)[NCOLS], int r, int c)
{
    int alive = 0;
    //upper row
    if (r > 0) {
        if (c > 0)
            alive += curr[r - 1][c - 1];
        alive += curr[r - 1][c];
        if (c < NCOLS - 1)
            alive += curr[r - 1][c + 1];
    }
    //lower row
    if (r < NROWS - 1) {
        if (c > 0)
            alive += curr[r + 1][c - 1];
        alive += curr[r + 1][c];
        if (c < NCOLS - 1)
            alive += curr[r + 1][c + 1];
    }
    //same row
    if (c > 0)
        alive += curr[r][c - 1];
    if (c < NCOLS - 1)
        alive += curr[r][c + 1];
    return alive;
}

//update state for next frame
int update(int (* curr)[NCOLS], int (* next)[NCOLS])
{
    int neighbours;
    for (int r = 0; r < NROWS; r++) {
        for (int c = 0; c < NCOLS; c++) {
            //count neighbours
            neighbours = count_alive_neighbours(curr, r, c);
            //rule 1 -> any alive cells with less than 2 alive neighbours will die
            //rule 3 -> any alive cells with more than 3 alive neighbours will die
            if (curr[r][c] == 1 && (neighbours < 2 || neighbours > 3))
                next[r][c] = 0;
            //rule 4 -> any dead cells with exactly 3 alive neighbours will live
            else if (curr[r][c] == 0 && neighbours == 3)
                next[r][c] = 1;
            //cells with no changes
            else
                next[r][c] = curr[r][c];
        }
    }
}

//handling with keypresses
void keypress_handler(SDL_Keycode key, int* paused, int (** curr)[NCOLS],
                      int (** next)[NCOLS], int* running, int* sleep)
{
    switch(key) {
        case SDLK_SPACE: // -> will pause and unpause the game
            pause_unpause(paused);
            break;
        case SDLK_UP: // -> will advance to the very next state
            if (*paused == 1) {
                update(*curr, *next);
                invert_pointers(curr, next);
            }
            break;
        case SDLK_DOWN: // -> will invert pointers without update, allowing to go 1 frame back
            if (*paused == 1)
                invert_pointers(curr, next);
            break;
        case SDLK_ESCAPE: // -> close window
            *running = 0;
            break;
        case SDLK_KP_PLUS: // -> increase simulation speed
            if (*sleep >= 20)
                *sleep -= 20;
            break;
        case SDLK_KP_MINUS: // -> decrease simulation speed
            if (*sleep <= 120)
                *sleep += 20;
            break;
        case SDLK_KP_0:
            if (*paused == 1)
                initialize(*curr, *next, 2);
            break;
        default:
            break;
    }
}

// pause and unpause the simulation
void pause_unpause(int* paused)
{
    if (*paused == 1)
        *paused =  0;
    else
        *paused = 1;
}