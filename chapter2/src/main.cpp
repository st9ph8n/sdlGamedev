#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include "game.hpp"



using namespace std;



Game *g_game;
int main()
{
  //initialize SDL
  g_game = new Game();

  g_game->init("chapter2", 100,100,640,560,false);

  while(g_game->running())
  {
    g_game->handleEvents();
     g_game->update();
    g_game->render();
  }
   g_game->clean();

  return 0;

}


