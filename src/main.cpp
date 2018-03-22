#include "main.h"

int main(int, char**)
{

    Init::sdl();

    deltaTime = new DeltaTime();

    SDL_SetRenderDrawColor(gRenderer, 0x11, 0x11, 0x1F, 0xFF);

    bool quit = false;
    Game game;
    SDL_Event e{};

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type==SDL_QUIT) {
                quit = true;
            }
        }
        deltaTime->update();
        SDL_RenderClear(gRenderer);
        game.start();
    }

    Deinit::renderer(gRenderer);
    Deinit::window(gWindow);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
