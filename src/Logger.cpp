//
// Created by sarcoma on 24/02/18.
//

#include <SDL_quit.h>
#include "Logger.h"

void Logger::sdlError(std::ostream& os, const std::string& msg)
{
    os << msg << " error: " << SDL_GetError() << std::endl;
}
