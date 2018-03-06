#include "main.h"

int main(int, char**)
{
    SDL_Window* sdlWindow = nullptr;
    SDL_Renderer* sdlRenderer = nullptr;
    Init::sdl(&sdlWindow, &sdlRenderer);

    bool quit = false;
    Game game(50, -50);
    SDL_Event e{};
    while (!quit) {
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
        }
        SDL_RenderClear(sdlRenderer);
        game.start(sdlWindow, sdlRenderer);
    }

    Deinit::renderer(sdlRenderer);
    Deinit::window(sdlWindow);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
