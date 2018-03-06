//
// Created by sarcoma on 06/03/18.
//

#ifndef SDLTEST_GAME_H
#define SDLTEST_GAME_H

class Game {
private:
    int x {0}, y {0};

public:
    Game(int x, int y);
    /**
     * Run the game
     * @param sdlWindow
     * @param sdlRenderer
     */
    void start(SDL_Window* sdlWindow, SDL_Renderer* sdlRenderer);
};

#endif //SDLTEST_GAME_H
