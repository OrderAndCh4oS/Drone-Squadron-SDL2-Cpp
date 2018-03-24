#include "main.h"
#include "ui/Panel.h"
#include "ui/View.h"

int main(int, char**)
{

    Init::sdl();

    deltaTime = new DeltaTime();

    bool quit = false;
    auto* game = new Game();
    SDL_Event e{};
    auto* gameView = new View{640, 440, 0, 0};
    auto* menuView = new View{640, 40, 0, 440};
    auto* button = new Panel{20, 20, 10, 10};
    menuView->add(button);
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type==SDL_QUIT) {
                quit = true;
            }
        }
        deltaTime->update();
        SDL_SetRenderDrawColor(gRenderer, 0x11, 0x11, 0x1F, 0xFF);
        SDL_RenderClear(gRenderer);
        gameView->draw();
        game->start();
        menuView->draw();
        SDL_RenderPresent(gRenderer);
    }

    Deinit::renderer(gRenderer);
    Deinit::window(gWindow);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
