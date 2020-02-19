#ifndef __RES_PATH_H
#define __RES_PATH_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

/**
 * Get the resource path for resources located in res/subDir
 * it's assumed the project directory is structured like
 * bin/
 *    the executables
 * chapter1/
 *    src/
 *       assets/
 *         
 * 
 * Paths returned will be lessons/res/subDir
*/
std::string getAssestPath(const std::string &Dir =""){

  #ifdef _WIN32
      const char PATH_SEP = '\\';
  #else
      const char PATH_SEP = '/' ;
  #endif
  static std::string baseRes;
  if (baseRes.empty()){
    char *basePath = SDL_GetBasePath();
    if (basePath){
      baseRes = basePath;
      SDL_free(basePath);
    }
    else{
      std::cerr << "Error getting assest path:" << SDL_GetError() << std::endl;
      return "";
    }
    size_t pos = baseRes.rfind("build");
    baseRes = baseRes.substr(0,pos) + Dir + PATH_SEP ;
  }

  return baseRes + "assets" + PATH_SEP;
}

#endif
