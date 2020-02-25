#ifndef __Enemy__
#define __Enemy__

#include "sdlgameobj.hpp"

class Enemy :public SDLGameObject{
    public:
    Enemy(const LoadParams* pParams);

    void update();
    void draw();
   // void clean();


};

#endif