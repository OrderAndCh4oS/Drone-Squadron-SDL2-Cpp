//
// Created by sarcoma on 24/02/18.
//

#ifndef SDLTEST_LOGGER_H
#define SDLTEST_LOGGER_H

#include <ostream>

class Logger {
public:
    /**
     * Log an SDL error with some error message to the output stream of our choice
     * @param os The output stream to write the message to
     * @param msg The error message to write, format will be msg error: SDL_GetError()
     */
    static void sdlError(std::ostream& os, const std::string& msg);

    /**
     * Log a message
     * @param os
     * @param message
     */
    static void message(std::ostream& os, const std::string& message);

    static void message(std::ostream& os, const int message);
};

#endif //SDLTEST_LOGGER_H
