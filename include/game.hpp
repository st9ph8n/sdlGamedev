#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include "TextureManager.hpp"
#include <SDL2/SDL_image.h>

class Game
{
 public:
    Game(){}
    ~Game(){}

    bool init (const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
    void render();
    void update();
    void handleEvents();
    void clean();

    //a function to access the private running variable
    bool running(){return m_bRunning;}

 private:
    bool m_bRunning;
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;
    SDL_Texture *m_pTexture;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;
    int m_currentFrame;
      
};

#endif
