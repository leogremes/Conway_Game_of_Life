#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H

# include <SDL2/SDL.h>
# include <windows.h> // -> sleep
# include <time.h> // -> srand seed
# include <stdlib.h> // -> srand

//number of board rows and columns 
# define NROWS 120
# define NCOLS 80

// cell and border size in pixels
# define CELL_SIZE 10
# define BORDER_SIZE 1

//spawn chance of an alive cell in a random generated board
# define PROBABILITY 33

//colors of cells (RGBA format)
# define DEAD_COLOR 0, 0, 0, 255
# define ALIVE_COLOR 0, 153, 0, 255
# define BORDER_COLOR 30, 30, 30, 255

#endif

//game_logic.c
void invert_cell(int (*curr)[NCOLS], SDL_MouseButtonEvent click);
int count_alive_neighbours(int (*curr)[NCOLS], int r, int c);
int update(int (*curr)[NCOLS], int (*next)[NCOLS]);
void pause_unpause(int* paused);
void keypress_handler(SDL_Keycode key, int* paused, int (** curr)[NCOLS],
                      int (** next)[NCOLS], int* running, int* sleep);

//utils.c
void initialize(int (*one)[NCOLS], int (*two)[NCOLS], int argc);
void invert_pointers(int (**one)[NCOLS], int (**two)[NCOLS]);
void draw_rectangles(SDL_Renderer* renderer, SDL_Rect* rect, int r, int g, int b, int a,
                     int (* curr)[NCOLS], int alive);