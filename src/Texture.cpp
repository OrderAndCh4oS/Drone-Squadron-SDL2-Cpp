//
// Created by sarcoma on 24/02/18.
//

#include <iostream>
#include <SDL_filesystem.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Logger.h"
#include "Deinit.h"
#include "constants.h"

SDL_Texture* Texture::load(const std::string& file)
{
    SDL_Texture* texture = IMG_LoadTexture(gRenderer, file.c_str());
    if (texture==nullptr) {
        Logger::sdlError(std::cout, "LoadTexture");
    }
    return texture;
}

void Texture::render(SDL_Texture* tex, int x, int y)
{
    //Setup the destination rectangle to be at the position we want
    SDL_Rect destination{};
    //Query the Texture to get its width and height to use
    SDL_QueryTexture(tex, nullptr, nullptr, &destination.w, &destination.h);
    destination.x = x-destination.w/2;
    destination.y = y-destination.h/2;
    SDL_RenderCopy(gRenderer, tex, nullptr, &destination);
}

int Texture::checkLoadSucceeded(SDL_Texture** file)
{
    if (*file==nullptr) {
        Logger::sdlError(std::cout, "Failed to load bmp");
        Deinit::texture(*file);
        Deinit::renderer(gRenderer);
        Deinit::window(gWindow);

        SDL_Quit();
        return 1;
    }
    return 0;
}

SDL_Texture* Texture::get(std::string imagePath)
{
    SDL_Texture* texture = Texture::load(imagePath);
    Texture::checkLoadSucceeded(&texture);
    return texture;
}
