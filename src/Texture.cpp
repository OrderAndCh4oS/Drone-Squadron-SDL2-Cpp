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

SDL_Texture* Texture::load(const std::string& file, SDL_Renderer* renderer)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, file.c_str());
    if (texture==nullptr) {
        Logger::sdlError(std::cout, "LoadTexture");
    }
    return texture;
}

void Texture::render(SDL_Texture* tex, SDL_Renderer* renderer, int x, int y)
{
    //Setup the destination rectangle to be at the position we want
    SDL_Rect dst{};
    //Query the Texture to get its width and height to use
    SDL_QueryTexture(tex, nullptr, nullptr, &dst.w, &dst.h);
    dst.x = x-dst.w/2;
    dst.y = y-dst.h/2;
    SDL_RenderCopy(renderer, tex, nullptr, &dst);
}

std::string Texture::path(const std::string& imagePath)
{
    char PATH_SEP = getSeparator();
    static std::string path = getPath(PATH_SEP);

    return path+imagePath;
}

std::string Texture::path(const std::string& imagePath, const std::list<std::string>& subDirectories)
{
    char PATH_SEP = getSeparator();
    static std::string path = getPath(PATH_SEP);

    for (auto const& directory : subDirectories) {
        path += directory+PATH_SEP;
    }

    return path+imagePath;
}

std::string Texture::getPath(char PATH_SEP)
{
    std::string path {""};
    if (path.empty()) {
        //SDL_GetBasePath will return NULL if something went wrong in retrieving the path
        char* basePath = SDL_GetBasePath();
        if (basePath) {
            path = basePath;
            SDL_free(basePath);
        }
        else {
            Logger::sdlError(std::cout, "Error getting resource path: ");
            return "";
        }
        //We replace the last bin/ with res/ to get the the resource path
        size_t pos = path.rfind("bin");
        path = path.substr(0, pos)+".."+PATH_SEP+"res"+PATH_SEP;
        return path;
    }
    return "";
}

char Texture::getSeparator()
{
#ifdef _WIN32
    const char PATH_SEP {'\\'};
#else
    const char PATH_SEP {'/'};
#endif
    return PATH_SEP;
}

int Texture::checkLoadSucceeded(SDL_Texture** file, SDL_Renderer* renderer, SDL_Window* window)
{
    if (*file==nullptr) {
        Logger::sdlError(std::cout, "Failed to load bmp");
        Deinit::texture(*file);
        Deinit::renderer(renderer);
        Deinit::window(window);

        SDL_Quit();
        return 1;
    }
    return 0;
}

SDL_Texture* Texture::get(std::string imagePath, SDL_Window* sdlWindow, SDL_Renderer* sdlRenderer)
{
    SDL_Texture* drone = Texture::load(imagePath, sdlRenderer);
    Texture::checkLoadSucceeded(&drone, sdlRenderer, sdlWindow);
    return drone;
}
