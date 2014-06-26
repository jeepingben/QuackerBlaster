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
#include "CImageEntity.h"

/**
 * class constructor
 */
 CImageEntity::CImageEntity()
 {
     // initalize variables
     m_Image = NULL;
     m_Alive = true;
 }

/**
 * class deconstructor
 */
CImageEntity::~CImageEntity()
{
    // if an image was loaded
    if(m_Image != NULL)
    {
        // free the image
        SDL_FreeSurface(m_Image);
    }
}

/**
 * Returns image width
 * @return image width
 */
int CImageEntity::getWidth() const
{
    // if the image has loaded
    if(m_Image != NULL)
    {
        // return image width
        return m_Image->w;
    }
    // otherwise the image isn't load
    else
    {
        // so return false
        return 0;
    }
}

/**
 * Returns image height
 * @return image height
 */
int CImageEntity::getHeight() const
{
    // if the image has loaded
    if(m_Image != NULL)
    {
        // return image height
        return m_Image->h;
    }
    // otherwise the image isn't load
    else
    {
        // so return false
        return 0;
    }
}

/**
 * Returns center x position of image
 * @return center x of image
 */
double CImageEntity::getCenterX() const
{
    return m_X + m_Image->w / 2;
}

/**
 * Returns center y position of image
 * @return center y of image
 */
double CImageEntity::getCenterY() const
{
    return m_Y + m_Image->h / 2;
}

/**
 * Loads the image
 * @param filename image file to load
 */
 bool CImageEntity::load(std::string const filename)
 {
    // temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;

    // the optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    // load the image
    loadedImage = IMG_Load(filename.c_str());

    // if nothing went wrong in loading the image
    if(loadedImage == NULL)
    {
        // image failed to load so return false
        return false;
    }

    // create an optimized image
    optimizedImage = SDL_DisplayFormat(loadedImage);

    // free the old image
    SDL_FreeSurface(loadedImage);

    // if the image wasn't optimized
    if(optimizedImage == NULL)
    {
        // return false
        return false;
    }

    // map the color key
    Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0xFF, 0x69, 0xB4);

    // set all pixels of color R 0xFF, G 0x69, B 0xB4 to be transparent
    SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);

    // set the optimized image at the member image
    m_Image = optimizedImage;

    // return success
    return true;
 }

/**
 * Draws the image
 * @param screen SDL surface pointer to screen
 */
 void CImageEntity::draw(SDL_Surface* const screen)
 {
     // make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    // give the offsets to the rectangle
    offset.x = m_X;
    offset.y = m_Y;

    // apply image to screen
    SDL_BlitSurface(m_Image, NULL, screen, &offset);
 }

/**
 * returns the imageentity's bounding
 * @return screen SDL rectangle image entity bounding box
 */
 SDL_Rect CImageEntity::getBounds()
 {
     // create bounding box
     SDL_Rect rect = {(Sint16)m_X, (Sint16)m_Y, (Uint16)getWidth(), (Uint16)getHeight()};

     // return the bounding box
     return rect;
 }
