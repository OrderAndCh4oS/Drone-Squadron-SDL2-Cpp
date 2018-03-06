//
// Created by sarcoma on 24/02/18.
//

#include "Deinit.h"

void Deinit::texture(SDL_Texture* texture)
{
    SDL_DestroyTexture(texture);
}

void Deinit::renderer(SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
}

void Deinit::window(SDL_Window* window)
{
    SDL_DestroyWindow(window);
}
