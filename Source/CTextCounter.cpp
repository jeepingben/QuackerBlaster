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
#include "CTextCounter.h"

/**
 * default class constructor
 */
 CTextCounter::CTextCounter()
{
    // initalize variables
    m_Counter = 0;

    // initalize the enviroment
    init();
}

/**
 * class destructor
 */
CTextCounter::~CTextCounter()
{
}

/**
 * draws the players score
 * @param screen pointer to screen surface
 * @return success or failure
 */
bool CTextCounter::draw(SDL_Surface* const screen)
{
    // create a buffer to hold the converted string
    char buffer[9];

    // convert the counter to a string
    sprintf(buffer, "%d", m_Counter);

    // render the text
    m_TextString = TTF_RenderText_Solid(m_Font, (m_Text + buffer).c_str(), m_TextColor);

    // if there was an error in rendering the text
    if(m_TextString == NULL )
    {
        return false;
    }

     // make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    // give the offsets to the rectangle
    offset.x = m_Position.doubleX();
    offset.y = m_Position.doubleY();

    // apply score to screen
    SDL_BlitSurface(m_TextString, NULL, screen, &offset);

    // if everything rendered fine
    return true;
}

/**
 * returns the value of counter
 * @return value of counter
 */
int CTextCounter::getCounterValue() const
{
     return m_Counter;
}

/**
 * sets the counters value
 * @param value new value to set counter to
 */
 void CTextCounter::setCounterValue(int const value)
{
    m_Counter = value;
}

/**
 * increments the counter
 * @param inc increment to increase counter by
 */
void CTextCounter::incrementCounter(int const inc)
{
    m_Counter += inc;
}

/**
 * decrements the counter
 * @param dec decrement to decrease counter by
 */
void CTextCounter::decrementCounter(int const dec)
{
    m_Counter -= dec;
}

/**
 * resets the counter
 */
void CTextCounter::resetCounter()
{
    m_Counter = 0;
}
