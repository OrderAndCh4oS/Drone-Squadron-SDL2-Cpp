//
// Created by sarcoma on 25/02/18.
//

#ifndef SDLTEST_INIT_H
#define SDLTEST_INIT_H

class Init {
public:
    /**
     * Set up SDL
     * @param window
     * @param renderer
     * @return success or failure
     */
    static int sdl(SDL_Window** window, SDL_Renderer** renderer);
};

#endif //SDLTEST_INIT_H
