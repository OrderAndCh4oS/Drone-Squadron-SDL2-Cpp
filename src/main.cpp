#include "main.h"

int main(int, char**)
{

    Init::sdl();

    deltaTime = new DeltaTime();

    auto* game = new Game();
    while (!game->isQuit()) {
        deltaTime->update();
        SDL_SetRenderDrawColor(gRenderer, 0x11, 0x11, 0x1F, 0xFF);
        SDL_RenderClear(gRenderer);
        game->start();
        SDL_RenderPresent(gRenderer);
    }

    Deinit::renderer(gRenderer);
    Deinit::window(gWindow);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
