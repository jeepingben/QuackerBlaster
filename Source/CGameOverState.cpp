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
#include "CGameOverState.h"

CGameOverState CGameOverState::m_GameOverState;

/**
 * class constructor
 */
 CGameOverState::CGameOverState()
 {

 }

/**
 * initalizes game objects
 */
void CGameOverState::init()
{
    log.EnableLogging(true);

    // pointer to screen surface
    SDL_Surface* screen = NULL;

    // get pointer to screen surface
    screen = SDL_GetVideoSurface();

    // load background file
    if(!g_Background.load("data/background.png"))
    {
        log.write("ERROR: Failed to load File:data/background.png State:GameOverState");
        exit(-1);
    }

    // load the font and initalize the title
    if(!g_GameOver.load("data/lunchds.ttf", 36))
    {
        log.write("ERROR: Failed to load File:data/lunchds.ttf State:GameOverState");
        exit(-2);
    }

    // gameover text was initalizes successfully so set it's position
    g_GameOver.setPosition(screen->w / 3.25, 80);

    // set the text
    g_GameOver.setText("Game Over!");

    // ret the timers
    m_Timer.reset();

    // start the timer
    m_Timer.start(true);
}

/**
 * destroys all game objects and releases memory
 */
void CGameOverState::destroy()
{
}

/**
 * pauses state
 */
void CGameOverState::pause()
{

}

/**
 * resumes state
 */
void CGameOverState::resume()
{

}

/**
 * game loop
 * @param game game engine instance
 */
void CGameOverState::processEvents(CGameEngine* game)
{
    // event thread
    SDL_Event event;

    // while there's an event to handle
    while(SDL_PollEvent(&event))
    {
        // if the user has x'ed the window
        if(event.type == SDL_QUIT)
        {
                // terminate the game
                game->quit();
        }
    }
}

/**
 * updates all game objects
 * @param game game engine instance
 */
void CGameOverState::update(CGameEngine* game)
{
    // if 5 seconds has passed since the game was over
    if(m_Timer.getTicks() > 5.0)
    {
        // change the game state to the intro state
        game->changeState(CIntroState::instance());
    }
}

/**
 * draws all game objects
 * @param game game engine instance
 */
void CGameOverState::draw(CGameEngine* game)
{
    // set the sky color to blue
    SDL_FillRect(game->m_Screen, NULL, 0x87CEEB);

    // draw the background
    g_Background.draw(game->m_Screen);

    // draw the title info
    g_GameOver.draw(game->m_Screen);

    // update Screen
    SDL_Flip(game->m_Screen);
}

/**
 * returns static class instance
 * @return static class instance
 */
CGameOverState* CGameOverState::instance()
{
    return &m_GameOverState;
}
