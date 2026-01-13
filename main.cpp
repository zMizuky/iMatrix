#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

char WINDOW_TITLE[] = "Hello SDL";

int WINDOW_WIDTH = 800;
int WINDOWS_HEIGHT = 600;

SDL_Window* window;
SDL_Renderer* renderer;

struct Player {
    float x = 250;
    float y = 250;
};Player player;

const char player_texture_path[] = "./assets/sprites/character.png"; // o spritesheet do player
SDL_Texture* player_texture;

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
    
    player_texture = IMG_LoadTexture(renderer, player_texture_path);
    SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);

    while(!done){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT){
                done = true;
            }
            if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.key == SDLK_A) player.x -= 5;
                if (event.key.key == SDLK_D) player.x += 5;
                if (event.key.key == SDLK_W) player.y -= 5;
                if (event.key.key == SDLK_S) player.y += 5;
            }

            SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
            SDL_RenderClear(renderer);
            
            SDL_FRect player_frame = {
                0,      //inicio, x
                0,      //inicio, y
                16,     //tamanho em x
                32      //tamanho em y
            };
            SDL_FRect player_pos = {
                player.x,
                player.y, 
                16, 
                32
            };
            
            SDL_RenderTexture(renderer, player_texture, &player_frame, &player_pos);
            
            SDL_RenderPresent(renderer);
        }
    }
    
    SDL_DestroyTexture(player_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
