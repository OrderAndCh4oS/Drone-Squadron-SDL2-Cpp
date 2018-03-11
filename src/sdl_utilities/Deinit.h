//
// Created by sarcoma on 24/02/18.
//

#ifndef SDLTEST_DESTROY_H
#define SDLTEST_DESTROY_H

#include <SDL_video.h>
#include <SDL_system.h>

class Deinit {
public:
    /**
     * Destroy texture
     * @param texture
     */
    static void texture(SDL_Texture* texture);

    /**
     * Destroy renderer
     * @param renderer
     */
    static void renderer(SDL_Renderer* renderer);

    /**
     * Destroy window
     * @param window
     */
    static void window(SDL_Window* window);
};

#endif //SDLTEST_DESTROY_H
