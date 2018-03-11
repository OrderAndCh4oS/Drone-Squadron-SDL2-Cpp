//
// Created by sarcoma on 07/03/18.
//

#include "Resource.h"

char Resource::getSeparator()
{
#ifdef _WIN32
    const char PATH_SEP {'\\'};
#else
    const char PATH_SEP{'/'};
#endif
    return PATH_SEP;
}

std::string Resource::path(const std::string& imagePath)
{
    char PATH_SEP = getSeparator();
    static std::string path = getPath(PATH_SEP);

    return path+imagePath;
}

std::string Resource::path(const std::string& imagePath, const std::list<std::string>& subDirectories)
{
    char PATH_SEP = getSeparator();
    static std::string path = getPath(PATH_SEP);

    for (auto const& directory : subDirectories) {
        path += directory+PATH_SEP;
    }

    return path+imagePath;
}

std::string Resource::getPath(char PATH_SEP)
{
    std::string path;
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