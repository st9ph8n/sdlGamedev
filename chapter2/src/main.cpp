#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include "game.hpp"



using namespace std;

typedef Game TheGame;


int main()
{
  std::cout << "game init attempt ..\n";

  if(TheGame::Instance()->init("chapter2", 100,100,640,560,false)){
    std::cout << "game init success\n";
    while(TheGame::Instance()->running()){
      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();

      SDL_Delay(10);
    }
  }
  else{
    std::cout << "game init failure -" << SDL_GetError() << "\n";
    return -1;
  }

  std::cout << "game closing ...\n";
  TheGame::Instance()->clean();

  return 0;

}


