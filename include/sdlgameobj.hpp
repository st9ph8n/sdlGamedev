#pragma once
#include "gameobject.hpp"

class SDLGameObject : public GameObject
{
    public:
    SDLGameObject(const LoadParams* pParamas);

    virtual void draw();
   // virtual void update();
    //virtual void clean();

    protected:

    int m_x;
    int m_y;
    int m_width;
    int m_height;
    int m_currentRow;
    int m_currentFrame;
    std::string m_textureID;
};