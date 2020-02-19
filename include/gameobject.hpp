#pragma once
#ifndef __GameObject__
#define __GameObject__


#include<SDL2/SDL.h>
#include <iostream>
#include "loadParam.hpp"
#include "TextureManager.hpp"


class GameObject
{
    public:
    // // void load(int x, int y, int wdth, int height, std::string textureID);
    virtual void draw(){}
    virtual void update(){}
    virtual void clean(){}
    // virtual void load (const LoadParams* pParams);

    protected:
    GameObject(const LoadParams* pParams){}
    virtual ~GameObject(){}

   };
#endif