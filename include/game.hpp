#pragma once
#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include "TextureManager.hpp"
#include <SDL2/SDL_image.h>
#include "player.hpp"
#include "enemy.hpp"
#include "gameobject.hpp"
#include <vector>

class Game
{
 public:
   
    bool init (const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
    void render();
    void update();
    void handleEvents();
    void clean();

    //a function to access the private running variable
    bool running(){return m_bRunning;}

    static Game* Instance(){
       if(s_pInstance == 0){
          s_pInstance = new Game();
          return s_pInstance;
       }
       return s_pInstance;
    }

    SDL_Renderer* getRenderer() const {return m_pRenderer;}

 private:
    Game(){}
    ~Game(){}
    
    static Game *s_pInstance;
    typedef Game TheGame;
    bool m_bRunning;
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;
    SDL_Texture *m_pTexture;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;
    int m_currentFrame;
    std::vector<GameObject*> m_gameObjects;
      
};

#endif
