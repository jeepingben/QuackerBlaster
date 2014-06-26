/*
 *   This file is part of Quacker Blaster.
 *
 *   Quacker Blaster is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Quacker Blaster is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Quacker Blaster.  If not, see <http://www.gnu.org/licenses/>.
 */

// include class definition
#include "CGameEngine.h"
#include "CGameState.h"

/**
 * initalizes game objects
 * @param title title of game window
 * @param width screen width
 * @param height screen height
 * @param bpp bitmap depth of screen
 * @param fullscreen true to enable fullscreen, flase to enable windowed mode
 * @param hidemouse true to hide mouse, false to show it
 */
void CGameEngine::init(const char* title, int const width, int const height, int const bpp, bool const fullscreen, bool hidemouse)
{
    int flags = 0;

    // initalize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // set the title bar text
    SDL_WM_SetCaption(title, title);

    // if fullscreen is selected
    if(fullscreen)
    {
        // set the fullscreen flag
        flags = SDL_FULLSCREEN;

    }

    // create the screen surface
    m_Screen = SDL_SetVideoMode(width, height, bpp, flags);

    // hide the cursor if requested
    if(hidemouse == true)
    {
       SDL_ShowCursor(SDL_DISABLE);
    }

    // save the fullscreen flag
    m_fullscreen = fullscreen;

    // set running to true
    m_Running = true;
}

/**
 * destroys all game objects and releases memory
 */
void CGameEngine::destroy()
{
    // cleanup all the states
    while(!states.empty())
    {
        states.back()->destroy();
        states.pop_back();
    }

    // switch back to windowed modeso other programs won't get accidentally resized
    if(m_fullscreen)
    {
        m_Screen = SDL_SetVideoMode(640, 480, 0, 0);
    }

    // if the mouse cursor was hidden show it
    if(SDL_ShowCursor(SDL_QUERY) == SDL_DISABLE)
    {
        SDL_ShowCursor(SDL_ENABLE);
    }

    // shutdown SDL
    SDL_Quit();
}

/**
 * changes the game state
 * @param state the new state
 */
void CGameEngine::changeState(CGameState* const state)
{
    // cleanup the currentstate
    if(!states.empty())
    {
        states.back()->destroy();
        states.pop_back();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->init();
}

/**
 * pushes the game state
 * @param state state to push into the stack
 */
void CGameEngine::pushState(CGameState* const state)
{
    // pause current state
    if(!states.empty())
    {
        states.back()->pause();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->init();
}

/**
 * pops the game state
 */
void CGameEngine::popState()
{
    // cleanup the current state
    if(!states.empty())
    {
        states.back()->destroy();
        states.pop_back();
    }

    // resume previoud=s state
    if(!states.empty())
    {
        states.back()->resume();
    }
}

/**
 * handles events
 */
 void CGameEngine::processEvents()
 {
     // let the state handle events
     states.back()->processEvents(this);
 }

/**
 * updates objects
 */
 void CGameEngine::update()
 {
     // let the state update the game
     states.back()->update(this);
 }

 /**
  * draws objects
  */
 void CGameEngine::draw()
 {
     // let the state draw the screen
     states.back()->draw(this);
 }

/**
 * returns running state
 * @return if game is running
 */
 bool CGameEngine::running()
 {
     return m_Running;
 }

 /**
 * sets running flag to false
 */
 void CGameEngine::quit()
 {
     m_Running = false;
 }
