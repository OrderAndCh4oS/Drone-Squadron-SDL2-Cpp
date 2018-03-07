#include "main.h"

int main(int, char**)
{

    Init::sdl();

    bool quit = false;
    Game game(0, SCREEN_HEIGHT/2);
    SDL_Event e{};
    while (!quit) {
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
        }
        SDL_RenderClear(gRenderer);
        game.start();
    }

    Deinit::renderer(gRenderer);
    Deinit::window(gWindow);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
