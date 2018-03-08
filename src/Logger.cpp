//
// Created by sarcoma on 24/02/18.
//

#include <SDL_quit.h>
#include "Logger.h"

void Logger::sdlError(std::ostream& os, const std::string& msg)
{
    os << msg << " error: " << SDL_GetError() << std::endl;
}

void Logger::message(std::ostream& os, const std::string& message)
{
    os << "Message: " << message << std::endl;
}

void Logger::message(std::ostream& os, const int message)
{
    os << "Value: " << std::to_string(message) << std::endl;
}
