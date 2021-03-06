#include "game.hpp"



using namespace std;

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{

  m_bRunning = true;
  int flag = 0;
  




  if (fullscreen)
  {
    flag = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "init successful \n";
    m_pWindow = SDL_CreateWindow(title,xpos,ypos,width,height,flag);

    if (m_pWindow != 0)
    {
      std::cout << "window created successfully \n";
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0)
      {
        std::cout << "renderer created successfully  \n";
        SDL_SetRenderDrawColor(m_pRenderer,255,0,0,255);
      }
      else
      {
        std::cout << "renderer failed \n";
        return false;
      }
    }
    else
    {
      std::cout << "error in creating window \n";
      return false;
    }

  }
  else
  {
    std::cout << "error in initializing " << SDL_GetError()  << "\n";
    return false;
  }
  if(!TheTextureManager::Instance()->load(title,"idleboxer.png","boxer",m_pRenderer)){
      std::cout << "error in sdlLoad " << SDL_GetError() << "\n";
      return false;
  }
    m_gameObjects.push_back(new Player(new LoadParams(100,100,60.75,135,"boxer")));
    m_gameObjects.push_back(new Enemy(new LoadParams(300,300,60.75,135,"boxer")));
}

void Game::update() //do physic
{
 // m_currentFrame = int ((SDL_GetTicks() / 100) % 4);
 for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++){
      m_gameObjects[i]->update();
    }
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer); //clear to the draw colour

    // TheTextureManager::Instance()->draw("boxer",0,0,60.75,135,m_pRenderer);
    // TheTextureManager::Instance()->drawFrame("boxer", 100,100,60.75,135,1,m_currentFrame,m_pRenderer);

    for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++){
      m_gameObjects[i]->draw();
    }

  SDL_RenderPresent(m_pRenderer); //draw to the screen
}

void Game::clean()
{
  std::cout << "cleaning game\n";
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}
void Game::handleEvents()
{
  SDL_Event event;
  if (SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT :
        m_bRunning = false;
      break;

      default :
      break;
    }
  }
}
