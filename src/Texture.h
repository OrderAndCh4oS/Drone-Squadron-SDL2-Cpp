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
     * Loads a BMP image into a texture on the rendering device
     * @param file The BMP image file to load
     * @return the loaded texture, or nullptr if something went wrong.
     */
    static SDL_Texture* load(const std::string& file);

public:
    /**
     * Create the texture from the image path provided
     * @param imagePath
     * @return image texture
     */
    static SDL_Texture* get(std::string imagePath);

    /**
     * Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
     * the texture's width and height
     * @param tex The source texture we want to draw
     * @param x The x coordinate to draw to
     * @param y The y coordinate to draw to
     */
    static void render(SDL_Texture* tex, int x, int y);

    /**
     * Check that the Texture is loaded
     * @param file
     * @return success or failure
     */
    static int checkLoadSucceeded(SDL_Texture** file);
};

#endif //SDLTEST_TEXTURE_H
