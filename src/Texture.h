//
// Created by sarcoma on 24/02/18.
//

#ifndef SDLTEST_TEXTURE_H
#define SDLTEST_TEXTURE_H

#include <SDL_system.h>
#include <string>
#include <list>

class Texture {
private:
    /**
     * We need to choose the path separator properly based on which
     * platform we're running on, since Windows uses a different
     * separator than most systems
     * @return filesystem separator
     */
    static char getSeparator();

    /**
     * Get filesystem resource base path
     * @param PATH_SEP
     * @return base path to resource
     */
    static std::string getPath(char PATH_SEP);

    /**
     * Loads a BMP image into a texture on the rendering device
     * @param file The BMP image file to load
     * @param renderer The renderer to load the texture onto
     * @return the loaded texture, or nullptr if something went wrong.
     */
    static SDL_Texture* load(const std::string& file, SDL_Renderer* renderer);

public:
    /**
     * Get filesystem path for image from a subdirectory
     * @param imagePath
     * @param subDirectories
     * @return path to image
     */
    static std::string path(const std::string& imagePath, const std::list<std::string>& subDirectories);

    /**
     * Override path
     * Get filesystem path for image without subdirectory
     * @param imagePath
     * @return path to image
     */
    static std::string path(const std::string& imagePath);

    /**
     * Create the texture from the image path provided
     * @param imagePath
     * @param sdlWindow
     * @param sdlRenderer
     * @return image texture
     */
    static SDL_Texture* get(std::string imagePath, SDL_Window* sdlWindow, SDL_Renderer* sdlRenderer);

    /**
     * Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
     * the texture's width and height
     * @param tex The source texture we want to draw
     * @param renderer The renderer we want to draw to
     * @param x The x coordinate to draw to
     * @param y The y coordinate to draw to
     */
    static void render(SDL_Texture* tex, SDL_Renderer* renderer, int x, int y);

    /**
     * Check that the Texture is loaded
     * @param file
     * @param renderer
     * @param window
     * @return success or failure
     */
    static int checkLoadSucceeded(SDL_Texture** file, SDL_Renderer* renderer, SDL_Window* window);
};

#endif //SDLTEST_TEXTURE_H
