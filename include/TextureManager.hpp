#ifndef _TextureManager_
#define _TextureManager_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include "res_path.hpp"

class TextureManager
{

  public:

    static TextureManager* Instance()
  {
    if(s_pInstance == 0)
    {
      s_pInstance = new TextureManager();
      return s_pInstance;
    }
    return s_pInstance;
  }
    
    bool load (std::string Dir,std::string filename, std::string id, SDL_Renderer* pRenderer);

    //draw
    void draw (std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    //drawframe
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    
  private:
    TextureManager(){}

    ~TextureManager(){}

    static TextureManager *s_pInstance;

    std::map<std::string, SDL_Texture *> m_textureMap;

};

typedef TextureManager TheTextureManager;

#endif