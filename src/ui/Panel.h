//
// Created by sarcoma on 22/03/18.
//

#ifndef SDLTEST_PANEL_H
#define SDLTEST_PANEL_H

#include <SDL_quit.h>
#include <vector>

class Panel {
private:
    SDL_Rect panel{};
    Uint8 colour[4] = {0x0, 0xFF, 0x0, 0xFF};
    std::vector<Panel*> children;
public:
    Panel(int width, int height, int x, int y);

    virtual void draw();

    virtual void add(Panel* child);

    const SDL_Rect& getPanel() const;

    void drawChildren() const;
};

#endif //SDLTEST_PANEL_H
