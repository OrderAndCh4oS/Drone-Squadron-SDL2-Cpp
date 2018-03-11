//
// Created by sarcoma on 07/03/18.
//

#ifndef SDLTEST_RESOURCE_H
#define SDLTEST_RESOURCE_H

#include <string>
#include <list>
#include <SDL_filesystem.h>
#include <iostream>
#include "../utilities/Logger.h"

class Resource {
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

};

#endif //SDLTEST_RESOURCE_H
