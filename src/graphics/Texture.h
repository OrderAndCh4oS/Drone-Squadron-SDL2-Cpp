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
    SDL_Texture* texture;
    SDL_Rect destination;

    /**
     * Loads a image into a texture on the rendering device
     * @param file The image file to load
     */
    void load(const std::string& file);

    void setDestination();

    void centerDestination(int x, int y);

public:
    Texture();

    ~Texture();

    void free();

    /**
     * Create the texture from the image path provided
     * @param imagePath
     */
    void set(std::string imagePath);

    /**
     * Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
     * the texture's width and height
     * @param x The x coordinate to draw to
     * @param y The y coordinate to draw
     * @param clip the sprite to rect
     */
    void render(int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr,
            SDL_RendererFlip flip = SDL_FLIP_NONE);

    /**
     * Check that the Texture is loaded
     * @param file
     * @return success or failure
     */
    static int checkLoadSucceeded(SDL_Texture** file);

    int getWidth();

    int getHeight();
};

#endif //SDLTEST_TEXTURE_H
