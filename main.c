/*
compiled with:
gcc main.c game_logic.c utils.c -I game_of_life -I .\SDL2\x86_64-w64-mingw32\include\ -L .\SDL2\x86_64-w64-mingw32\lib\ -lmingw32 -lSDL2main -lSDL2
*/

#include "game_of_life.h"

int main(int argc, char** argv) {

	//VARIABLES
    //board matrices
    int  one[NROWS][NCOLS];
    int  two[NROWS][NCOLS];

    //pointers to current state and next
    int (*curr)[NCOLS] = one;
    int (*next)[NCOLS] = two;

    //initialize matrices with zeroes
    initialize(one, two, argc);

    //window is running
    int running = 1;

    //simulation is pauses
    int paused = 1;

    // time between loops
    int sleep_time = 60;

    //creation of window and renderer
    SDL_Window* window = NULL;
	window = SDL_CreateWindow(
		"Game of Life", // -> window title
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		(NROWS * CELL_SIZE) + BORDER_SIZE, (NCOLS * CELL_SIZE) + BORDER_SIZE, // -> window dimensions
		SDL_WINDOW_SHOWN
		);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	//creation of entitiy that will be the cells
    SDL_Rect q = {0, 0, CELL_SIZE - BORDER_SIZE, CELL_SIZE - BORDER_SIZE};

	//PROGRAM
    //window loop
    while(running){

        //listening events
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
            case SDL_QUIT:
                running = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (paused == 1)
                    invert_cell(curr, event.button);
                break;
            case SDL_KEYDOWN:
                keypress_handler(event.key.keysym.sym, &paused, &curr, &next, &running, &sleep_time);
                break;
            default:
                break;
            }
        }

        //drawing on the window
        SDL_RenderClear(renderer); // -> clean all window
        draw_rectangles(renderer, &q, DEAD_COLOR, curr, 0); // -> dead cells
        draw_rectangles(renderer, &q, ALIVE_COLOR, curr, 1); // -> alive cells
        SDL_SetRenderDrawColor(renderer, BORDER_COLOR); // -> border
        SDL_RenderPresent(renderer);

        //update states if simulation is running
        if (paused == 0) {
            update(curr, next);
            invert_pointers(&curr, &next);
        }
        Sleep(sleep_time);
	}

    //destroy window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
	}