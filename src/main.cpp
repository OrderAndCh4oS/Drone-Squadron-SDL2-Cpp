#include "main.h"
#include "ui/Panel.h"

int main(int, char**)
{

    Init::sdl();

    deltaTime = new DeltaTime();

    bool quit = false;
    Game game;
    SDL_Event e{};
    Panel panel{100, 100, 0, 0};
    Panel panelTwo{100, 100, 120, 120};
    Panel panelThree{100, 100, 240, 240};
    panelTwo.add(panelThree);
    panel.add(panelTwo);
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type==SDL_QUIT) {
                quit = true;
            }
        }
        deltaTime->update();
        SDL_SetRenderDrawColor(gRenderer, 0x11, 0x11, 0x1F, 0xFF);
        SDL_RenderClear(gRenderer);
        panel.draw();
        game.start();
        SDL_RenderPresent(gRenderer);
    }

    Deinit::renderer(gRenderer);
    Deinit::window(gWindow);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
