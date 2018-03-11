//
// Created by sarcoma on 24/02/18.
//

#include <iostream>
#include <SDL_filesystem.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "../utilities/Logger.h"
#include "../sdl_utilities/Deinit.h"
#include "../constants.h"

Texture::Texture()
{
    texture = nullptr;
    destination = {};
}

Texture::~Texture()
{
    free();
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    centerDestination(x, y);

    if (clip!=nullptr) {
        destination.w = clip->w;
        destination.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx(gRenderer, texture, clip, &destination, angle, center, flip);
}

void Texture::centerDestination(int x, int y)
{
    destination.x = x-destination.w/2;
    destination.y = y-destination.h/2;
}

void Texture::set(const std::string imagePath)
{
    free();
    Texture::load(imagePath);
    if (Texture::checkLoadSucceeded(&texture)==0) {
        setDestination();
    }
}

void Texture::load(const std::string& file)
{
    texture = IMG_LoadTexture(gRenderer, file.c_str());
    if (texture==nullptr) {
        Logger::sdlError(std::cout, "LoadTexture");
    }
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

void Texture::free()
{
    if (texture!=nullptr) {
        texture = nullptr;
        destination = {};
    }
}

void Texture::setDestination()
{
    //Query the Texture to get its width and height to use
    SDL_QueryTexture(texture, nullptr, nullptr, &destination.w, &destination.h);
}

int Texture::getWidth()
{
    return destination.w;
}

int Texture::getHeight()
{
    return destination.h;
}
