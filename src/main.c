#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>

// global variable 
SDL_Window* window;
SDL_Surface* screenSurface;
SDL_Event event;
bool running = true, upK = false, downK = false, leftK = false, rightK = false; 

// window set up 
void setWindow() { 
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080,
        SDL_WINDOW_FULLSCREEN_DESKTOP
    );
}

// get inputs  
void getInputs() {
    while (SDL_PollEvent(&event)) {
        switch(event.type) { 
            case SDL_KEYDOWN: 
                switch(event.key.keysym.sym) { 
                    case SDLK_UP: 
                        upK = true;
                        break;
                    case SDLK_DOWN: 
                        downK = true;
                        break;
                    case SDLK_LEFT:
                        leftK = true;
                        break;
                    case SDLK_RIGHT:
                        rightK = true;
                        break;
                }
            break;
            case SDL_KEYUP:
                switch(event.key.keysym.sym) {
                    case SDLK_UP:
                        upK = false;
                        break;
                    case SDLK_DOWN: 
                        downK = false;
                        break;
                    case SDLK_LEFT:
                        leftK = false;
                        break;
                    case SDLK_RIGHT:
                        rightK = false;
                        break;
                }
            break;
            case SDL_QUIT:
                running = false;
        }
    }
}


// update 
void update() { 
    if (upK == true) { 
        printf("%s", "up pressed");
    }
    if (downK == true) { 
        printf("%s", "down pressed");
    }
    if (leftK == true) { 
        printf("%s", "left pressed");
    }
    if (rightK == true) { 
        printf("%s", "right pressed");
    }
}

// draw to window 
void draw() { 
    screenSurface = SDL_GetWindowSurface(window);

    SDL_FillRect(
        screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF)
    );

    SDL_UpdateWindowSurface(window);
}

// game main function 
int main(void) {
    
    setWindow();
    draw();

    while (running == true) {
        getInputs();
        update();
    }
}
