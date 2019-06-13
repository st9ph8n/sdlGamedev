#include <SDL2/SDL.h>
#include "game.h"
#include <iostream>
#include <SDL2/SDL_surface.h>
#include "res_path.h"


using namespace std;
/**
 * templat
 * 
 * void init(){}
 * void render(){}
 * void update(){}
 * void handleEvents(){}
 * void clean(){}
 * 
 * bool g_bRunning = true;
 * 
 * int main()
 * {
 *    init();
 * 
 *    while(g_bRunnig)
 *    {
 *      handleEvents() //get input
 *      update();     // do physics
 *      render();
 *    }
 *    clean();
 * }
 * 
*/

// SDL_Window *g_pWindow = 0;
// SDL_Renderer *g_pRenderer = 0;
 

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
    m_bRunning = true;
    int flags = 0;
    
    if(fullscreen)
    {
      flags = SDL_WINDOW_FULLSCREEN;
    }
  //initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    //if succeeded create our window
    std::cout << "SDL init success" << '\n';
     //init the window
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

    //if the window creation succeeded create our renderer
    if(m_pWindow != 0)
    {
      std::cout << "window creation success \n";
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0)
      {
        std::cout << "renderer creation success\n";
        SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,255);

      }
      else
      {
        std::cout << "renderer init fail \n";
        return false; 
      }
    }
    else
    {
      std::cout << "window  init fail \n";
      return false;
    }
  }
  else
  {
    std::cout << "SDL init fail \n";
    return false;
  }

  std::string imagePath = getAssestPath("chapter1")+"rider.bmp";
  SDL_Surface *pTempSurface = SDL_LoadBMP(imagePath.c_str()); //not workin for some reason -> solution needs full path

    if ( pTempSurface != NULL)
    {
      std::cout << "SDL_Load success\n";

        
      m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);
      SDL_FreeSurface(pTempSurface);

      //get dimensions of the texture just loaded above and use it to set width and height of m_sourceRectangle
      SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);


    /*now the correct height and width of m_sourceRectangle has been set,
    * the destinationRectangle must also be set
    * This is done so that our renderer knows which part of the window to draw the image and also the width and height of the image we want to render
    * setting the "x" and "y" coordinated to 0 puts the image at the top right corner of the window
    * center: x = width of window / 2 and vice versa for y
    */
      m_sourceRectangle.w = 50;
      m_sourceRectangle.h = 50;
      
      
      
      m_destinationRectangle.x = m_sourceRectangle.x = 0;
      m_destinationRectangle.y = m_sourceRectangle.y = 0;
      m_destinationRectangle.w = m_sourceRectangle.w;
      m_destinationRectangle.h = m_sourceRectangle.h;

      m_sourceRectangle.x = 50;
      m_sourceRectangle.y = 50;

      m_destinationRectangle.x = 100;
      m_destinationRectangle.y = 100;

      
      
    }
    else 
    {
      std::cout << "error in sdl_load\n" << SDL_GetError() << "\n";
      return false; 
    }

  /**
   * SDL_loadBMp load image and returns SDL_Surface
   * from SDL_Surface we create SDL_Texture   
  */
  

  return true;
}

void Game::render()
{
  //clear the entire screen to out selected color
  SDL_RenderClear(m_pRenderer);

  SDL_RenderCopy(m_pRenderer, m_pTexture,NULL, NULL);

  //show the window 
  /* Up until now everything was drawn behind the scenes.
     This will show the new, red contents of the window
    */
  SDL_RenderPresent(m_pRenderer);
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
  if(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT:
        m_bRunning = false;
      break;

      default:
      break;
    }
  }
}

  Game *g_game = 0;

int main()
{
  //initialize SDL
  g_game = new Game();

  g_game->init("chapter1", 100,100,640,560,false);

  while(g_game->running())
  {
    g_game->handleEvents();
    // g_game->update();
    g_game->render();
  }
   g_game->clean();

  return 0;

}
