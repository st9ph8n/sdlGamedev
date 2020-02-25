#pragma once
#ifndef __Player__
#define __Player__

#include "sdlgameobj.hpp"


class Player: public SDLGameObject{
 public:
  
  Player(const LoadParams* pParams);
  void draw();
  void update();
  void clean(){}
};

#endif
