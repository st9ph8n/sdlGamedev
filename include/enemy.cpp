#include "enemy.hpp"
#include "game.hpp"

Enemy::Enemy(const LoadParams* pParams)
 :SDLGameObject(pParams){}


void Enemy::draw(){
    SDLGameObject::draw();
}

void Enemy::update(){
    m_y += 1;
    m_x += 1;
}