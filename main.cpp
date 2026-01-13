#include <SDL3/SDL.h>

char WINDOW_TITLE[] = "Hello SDL";

int WINDOW_WIDTH = 800;
int WINDOWS_HEIGHT = 600;

SDL_Window* window;
SDL_Renderer* renderer;

bool done = false;

int main(){
    if(!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("Erro ao iniciar SDL: %s", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow(
        WINDOW_TITLE,
        WINDOW_WIDTH,
        WINDOWS_HEIGHT,
        0
    );

    if(!window){
        SDL_Log("Erro ao criar o window: %s", SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, NULL);

    if(!renderer){
        SDL_Log("Erro ao criar o renderer: %s", SDL_GetError());
        return -1;
    }

    while(!done){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT){
                done = true;
            }

            SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
            SDL_RenderClear(renderer);

            SDL_RenderPresent(renderer);
        }
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}