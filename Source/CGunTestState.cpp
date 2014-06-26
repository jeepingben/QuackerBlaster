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
#include "CGunTestState.h"

CGunTestState CGunTestState::m_GunTestState;

/**
 * class constructor
 */
 CGunTestState::CGunTestState()
 {

 }

/**
 * initalizes game objects
 */
void CGunTestState::init()
{
    log.EnableLogging(true);

    // load crosshair file
    if(!g_Crosshair.load("data/crosshair.png"))
    {
        log.write("ERROR: Failed to load File:data/crosshair.png State:GunTestState");
        exit(-1);
    }

    // load shot file
    if(!g_ShotMarker.load("data/shot_marker.png"))
    {
        log.write("ERROR: Failed to load File:data/shot_marker.png State:GunTestState");
        exit(-2);
    }

    // set the shot marker offscreen
    g_ShotMarker.position().setX(-32);
    g_ShotMarker.position().setY(-32);

    // load gun fire audio file
    if(!g_Fire.load("data/fire.wav"))
    {
        log.write("ERROR: Failed to load File:data/fire.wav State:GunTestState");
        exit(-3);
    }
}

/**
 * destroys all game objects and releases memory
 */
void CGunTestState::destroy()
{
}

/**
 * pauses state
 */
void CGunTestState::pause()
{

}

/**
 * resumes state
 */
void CGunTestState::resume()
{

}

/**
 * game loop
 * @param game game engine instance
 */
void CGunTestState::processEvents(CGameEngine* const game)
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

        // if the left mouse button was pressed this frame
        if(m_MouseListener.isClicked())
        {
            if(m_MouseListener.isLeftButtonDown())
            {
                // play the fire sound effect
                g_Fire.play();

                // set the shot marker's position to where the mouse was clicked
                g_ShotMarker.position().setX(m_MouseListener.getX() - (g_Crosshair.getWidth() / 2));
                g_ShotMarker.position().setY(m_MouseListener.getY() - (g_Crosshair.getHeight() / 2));

            }
        }
    }
}

/**
 * updates all game objects
 * @param game game engine instance
 */
void CGunTestState::update(CGameEngine* const game)
{
    // set the crosshair's position to the mouse's cursor
    g_Crosshair.position().setX(m_MouseListener.getX() - (g_Crosshair.getWidth() / 2));
    g_Crosshair.position().setY(m_MouseListener.getY() - (g_Crosshair.getHeight() / 2));

    // update the crosshair
    g_Crosshair.update();

    // update the shot marker
    g_ShotMarker.update();
}

/**
 * draws all game objects
 * @param game game engine instance
 */
void CGunTestState::draw(CGameEngine* const game)
{
    // so set the screen color to black
    SDL_FillRect(game->m_Screen, NULL, 0x000000);

    // draw the crosshair
    g_Crosshair.draw(game->m_Screen);

    // draw the shot icon
    g_ShotMarker.draw(game->m_Screen);

    // update Screen
    SDL_Flip(game->m_Screen);
}

/**
 * returns static class instance
 * @return static class instance
 */
CGunTestState* CGunTestState::instance()
{
    return &m_GunTestState;
}

/**
 * Returns if object intersects bottom boundry
 * @param y objects y position
 * @param offset offset to y position
 * @return if object intersects bottom boundry
 */
bool CGunTestState::intersectsBottomBoundry(double y, double offset)
{
     // pointer to screen surface
    SDL_Surface* screen = NULL;

    // get pointer to screen surface
    screen = SDL_GetVideoSurface();

    return (y > screen->h - offset);
}

/**
 * Returns if object intersects left boundry
 * @param x objects x position
 * @param offset offset to x position
 * @return if object intersects left boundry
 */
bool CGunTestState::intersectsLeftBoundry(double x, double offset)
{
    return (x < 0 + offset);
}

/**
 * Returns if object intersects right boundry
 * @param x objects x position
 * @param offset offset to x position
 * @return if object intersects right boundry
 */
bool CGunTestState::intersectsRightBoundry(double x, double offset)
{
     // pointer to screen surface
    SDL_Surface* screen = NULL;

    // get pointer to screen surface
    screen = SDL_GetVideoSurface();

    return (x > screen->w - offset);
}

/**
 * Returns if object intersects top boundry
 * @param y objects y position
 * @param offset offset to y position
 * @return if object intersects top boundry
 */
bool CGunTestState::intersectsTopBoundry(double y, double offset)
{
    return (y < 0 + offset);
}
