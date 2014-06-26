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
#include "CText.h"

/**
 * default class constructor
 */
 CText::CText()
{
    // set the score's x position
    m_Position.setX(0.0);

    // set the score's y position
    m_Position.setY(0.0);

    // set font color
	m_TextColor.r = 255;
	m_TextColor.g = 255;
	m_TextColor.b = 255;

    // initalize the enviroment
    init();
}

/**
 * class destructor
 */
CText::~CText()
{
    // if the surface used to display the text loaded successfully
    if(m_TextString != NULL)
    {
        // free the surface
        SDL_FreeSurface(m_TextString);
    }

    // if the font was loaded successfully
    if(m_Font != NULL)
    {
        // close the font that was used
        TTF_CloseFont(m_Font);
    }

    // quit SDL_ttf
    TTF_Quit();
}

/**
 * initalizes the enviroment
 * @return true if initalization succeeded false otherwise
 */
bool CText::init()
{
    //Initialize SDL_ttf
    if(TTF_Init() == -1)
    {
        return false;
    }

    // if everything initialized fine
    return true;
}

/**
 * loads the font and sets it's size
 * @param font to load
 * @param font size
 * @return true if funt was loaded successfully otherwise false
 */
bool CText::load(std::string const filename, int const fontsize)
{
    //Open the font
    m_Font = TTF_OpenFont(filename.c_str(), fontsize);

    // if there was an error in loading the font
    if(m_Font == NULL )
    {
        return false;
    }

    // if everything loaded fine
    return true;
}

/**
 * draws the players score
 * @param pointer to screen surface
 * @return success or failure
 */
bool CText::draw(SDL_Surface* const screen)
{
    // render the text
    m_TextString = TTF_RenderText_Solid(m_Font, m_Text.c_str(), m_TextColor);

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
 * returns the value of text string
 * @return value of text string
 */
std::string const CText::getText()
{
     return m_Text;
}

/**
 * sets the text string
 * @param value to set text string to
 */
void CText::setText(std::string const text)
{
    m_Text = text;
}

/**
 * sets the fonts color
 * @param rgbred red color intensity
 * @param rgbgreen green color intensity
 * @param rgbblue blue color intensity
 */
void CText::setColor(int const rgbred, int const rgbgreen, int const rgbblue)
{
	m_TextColor.r = (Uint8)rgbred;
	m_TextColor.g = (Uint8)rgbgreen;
	m_TextColor.b = (Uint8)rgbblue;
}

/**
 * set's text's position on the screen
 * @param x score's x position
 * @param y score's y position
 */
void CText::setPosition(double const x, double const y)
{
   // set the text's x position
   m_Position.setX(x);

   // set the text's y position
   m_Position.setY(y);
}
