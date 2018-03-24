#include "main.h"
#include "ui/Panel.h"

int main(int, char**)
{

    Init::sdl();

    deltaTime = new DeltaTime();

    bool quit = false;
    auto* game = new Game();
    SDL_Event e{};
    auto* panel = new Panel{100, 100, 0, 0};
    auto* panelTwo = new Panel{100, 100, 120, 120};
    auto* panelThree = new Panel{100, 100, 240, 240};
    panel->add(panelTwo);
    panelTwo->add(panelThree);
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type==SDL_QUIT) {
                quit = true;
            }
        }
        deltaTime->update();
        SDL_SetRenderDrawColor(gRenderer, 0x11, 0x11, 0x1F, 0xFF);
        SDL_RenderClear(gRenderer);
        panel->draw();
        game->start();
        SDL_RenderPresent(gRenderer);
    }

    Deinit::renderer(gRenderer);
    Deinit::window(gWindow);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
