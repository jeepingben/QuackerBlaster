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
#include "CIntroState.h"

CIntroState CIntroState::m_IntroState;

/**
 * class constructor
 */
 CIntroState::CIntroState()
 {

 }

/**
 * initalizes game objects
 */
void CIntroState::init()
{
    log.EnableLogging(true);

    // pointer to screen surface
    SDL_Surface* screen = NULL;

    // get pointer to screen surface
    screen = SDL_GetVideoSurface();

    // load background file
    if(!g_Background.load("data/background.png"))
    {
        log.write("ERROR: Failed to load File:data/background.png State:IntroState");
        exit(-1);
    }

    // load the font and initalize the title
    if(!g_Title.load("data/lunchds.ttf", 36))
    {
        log.write("ERROR: Failed to load File:data/lunchds.ttf State:IntroState");
        exit(-2);
    }

    // title text was initalizes successfully so set it's position
    g_Title.setPosition(screen->w / 3.25, 80);

    // set the text
    g_Title.setText("Quacker Blaster");

    // load the font and initalize the press start text
    if(!g_PressTrigger.load("data/lunchds.ttf", 18))
    {
        log.write("ERROR: Failed to load File:data/lunchds.ttf State:IntroState");
        exit(-3);
    }

    // press start text was initalizes successfully so set it's position
    g_PressTrigger.setPosition(screen->w / 2.5, screen->h - 240);

    // set the text
    g_PressTrigger.setText("Press Trigger");

    // load the font and initalize the version info
    if(!g_Version.load("data/lunchds.ttf", 10))
    {
        log.write("ERROR: Failed to load File:data/lunchds.ttf State:IntroState");
        exit(-4);
    }

    // score was initalizes successfully so set it's position
    g_Version.setPosition(screen->w -120, screen->h - 40);

    // set the text
    g_Version.setText("Version: 2013.12.15");

    // instantate mouse listener
    m_MouseListener = CMouseListener();
}

/**
 * destroys all game objects and releases memory
 */
void CIntroState::destroy()
{
}

/**
 * pauses state
 */
void CIntroState::pause()
{

}

/**
 * resumes state
 */
void CIntroState::resume()
{

}

/**
 * game loop
 * @param game game engine instance
 */
void CIntroState::processEvents(CGameEngine* game)
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
            // poll for mouse events
            m_MouseListener.pollMouse(event);
    }
}

/**
 * updates all game objects
 * @param game game engine instance
 */
void CIntroState::update(CGameEngine* game)
{
    if(m_MouseListener.isLeftButtonDown() || m_MouseListener.isRightButtonDown())
    {
        // change the game state to the play state
        game->changeState(CPlayState::instance());
    }
}

/**
 * draws all game objects
 * @param game game engine instance
 */
void CIntroState::draw(CGameEngine* game)
{
    // set the sky color to blue
    SDL_FillRect(game->m_Screen, NULL, 0x87CEEB);

    // draw the background
    g_Background.draw(game->m_Screen);

    // draw the title info
    g_Title.draw(game->m_Screen);

    // draw the press start info
    g_PressTrigger.draw(game->m_Screen);

        // draw the version info
    g_Version.draw(game->m_Screen);

    // update Screen
    SDL_Flip(game->m_Screen);
}

/**
 * returns static class instance
 * @return static class instance
 */
CIntroState* CIntroState::instance()
{
    return &m_IntroState;
}
