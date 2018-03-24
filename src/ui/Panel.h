//
// Created by sarcoma on 22/03/18.
//

#ifndef SDLTEST_PANEL_H
#define SDLTEST_PANEL_H

#include <SDL_quit.h>
#include <vector>

class Panel {
private:
    int width{0};
    int height{0};
    int x{0};
    int y{0};
    SDL_Rect panel{};
    Uint8 colour[4] = {0x0, 0xFF, 0x0, 0xFF};
    std::vector<Panel*> children;
public:
    Panel(int width, int height, int x, int y);

    void draw();

    void add(Panel* child);
};

#endif //SDLTEST_PANEL_H
