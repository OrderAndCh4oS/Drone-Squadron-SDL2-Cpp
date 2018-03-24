#include "main.h"
#include "ui/Panel.h"
#include "ui/View.h"
#include "ui/Button.h"

int main(int, char**)
{

    Init::sdl();

    deltaTime = new DeltaTime();

    bool quit = false;
    auto* game = new Game();
    SDL_Event e{};
    auto* gameView = new View{640, 440, 0, 0};
    gameView->setBackgroundColour(0x0, 0x0, 0x25, 0xFF);
    auto* menuView = new View{640, 480, 0, 440};
    menuView->setBackgroundColour(0x25, 0x25, 0x40, 0xFF);
    auto* buttonOne = new Button{20, 20, 10, 10};
    buttonOne->setBackgroundColour(0x25, 0xC6, 0x25, 0xFF);
    menuView->add(buttonOne);
    auto* buttonTwo = new Button{20, 20, 40, 10};
    buttonTwo->setBackgroundColour(0x25, 0xC6, 0x25, 0xFF);
    menuView->add(buttonTwo);
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type==SDL_QUIT) {
                quit = true;
            }
            if (e.type==SDL_MOUSEBUTTONUP) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                buttonOne->handleMouseUpEvent(x, y);
                buttonTwo->handleMouseUpEvent(x, y);
            }
        }
        deltaTime->update();
        SDL_SetRenderDrawColor(gRenderer, 0x11, 0x11, 0x1F, 0xFF);
        SDL_RenderClear(gRenderer);
        menuView->draw();
        gameView->draw();
        game->start();
        SDL_RenderPresent(gRenderer);
    }

    Deinit::renderer(gRenderer);
    Deinit::window(gWindow);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
