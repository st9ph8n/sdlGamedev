#include "player.hpp"
#include "game.hpp"

Player::Player(const LoadParams* pParams):
SDLGameObject(pParams){}

void Player::draw(){
   SDLGameObject::draw();
}

void Player::update(){
    m_y += 1;
    m_x += 1;
    m_currentFrame = int ((SDL_GetTicks() / 100) % 4);
}

