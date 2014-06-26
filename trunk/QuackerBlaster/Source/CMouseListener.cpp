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
#include "CMouseListener.h"

/**
 *  default class constructor
 */
CMouseListener::CMouseListener()
{
    // initalize variables
    m_X = 0.0;
    m_Y = 0.0;
    m_Clicked = false;
    m_LeftDown = false;
    m_RightDown = false;

}

/**
 *  returns the mouse's x position
 * @return mouse's x position
 */
 float CMouseListener::getX() const
{
    return m_X;
}

/**
 *  returns the mouse's y position
 * @return mouse's y position
 */
 float CMouseListener::getY() const
{
    return m_Y;
}

/**
 *  returns if a button is clicked
 * @return is mouse button down
 */
bool CMouseListener::isClicked() const
{
    return m_Clicked;
}

/**
 *  returns if the left mouse button is down
 * @return is left mouse button down
 */
bool CMouseListener::isLeftButtonDown() const
{
    return m_LeftDown;
}

/**
 *  returns if the right mouse button is down
 * @return is right mouse button down
 */
 bool CMouseListener::isRightButtonDown() const
{
    return m_RightDown;
}

/**
 *  polls the queue for mouse event
 * @param event sdl event pointer
 */
 void CMouseListener::pollMouse(SDL_Event const event)
{
    // set mouse clicked to false
    m_Clicked = false;

    // if the user has x'ed the window
    if(event.type == SDL_MOUSEMOTION)
    {
        // set the mouse's coordinates
        m_X = event.motion.x;
        m_Y = event.motion.y;
    }

    // if a button was pressed
    if(event.type == SDL_MOUSEBUTTONDOWN )
    {
        m_Clicked = true;

        //If the left mouse button was pressed
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            // set left button state to true
            m_LeftDown = true;
        }

        // if the left mouse button was pressed
        if(event.button.button == SDL_BUTTON_RIGHT)
        {
            // set right button state to true
            m_RightDown = true;
        }
    }

    // if a button was depressed
    if(event.type == SDL_MOUSEBUTTONUP )
    {
        // if the left mouse button was depressed
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            // set left button state to true
            m_LeftDown = false;
        }

        // if the left mouse button was depressed
        if(event.button.button == SDL_BUTTON_RIGHT)
        {
            // set right button state to true
            m_RightDown = false;
        }
    }
}
