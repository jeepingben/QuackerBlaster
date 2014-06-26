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

// include required libraries
#include "CAnimatedSprite.h"

/**
 * class constructor
 */
CAnimatedSprite::CAnimatedSprite()
{
    m_CurrentFrame = 0;
    m_TotalFrames = 0;
    m_AnimationDirection = 1;
    m_FrameCount = 0;
    m_FrameDelay = 0;
    m_FrameWidth = 0;
    m_FrameHeight = 0;
    m_Columns = 0;
}

/**
 * Loads the image
 * @param filename image file to load
 */
bool CAnimatedSprite::load(std::string const filename, int const columns, int const rows, int const width, int const height)
{
    // set number of columns
    m_Columns = columns;

    // set number of total frames
    m_TotalFrames = columns * rows;

    // set each frames width
    m_FrameWidth = width;

        // set each frames height
    m_FrameHeight = height;

    // return success
    return true;
}

/**
 * returns current frame
 * @return current animation frame
 */
int CAnimatedSprite::currentFrame() const
{
    return m_CurrentFrame;
}

/**
 * returns frame width
 * @return animation frame width
 */
int CAnimatedSprite::frameWidth() const
{
    return m_FrameWidth;
}

/**
 * returns frame height
 * @return animation frame height
 */
int CAnimatedSprite::frameHeight() const
{
    return m_FrameHeight;
}

/**
 * returns total animation frames
 * @return total animation frames
 */
int CAnimatedSprite::totalFrames() const
{
    return m_TotalFrames;
}

/**
 * returns animation direction
 * @return current animation direction
 */
int CAnimatedSprite::animationDirection() const
{
    return m_AnimationDirection;
}

/**
 * returns frame delay
 * @return animation frame delay
 */
int CAnimatedSprite::frameDelay() const
{
    return m_FrameDelay;
}

/**
 * returns number of columns in animation strip
 * @return number of columns in animation strip
 */
int CAnimatedSprite::columns() const
{
    return m_Columns;
}

/**
 * returns animation strip image
 * @return animation strip image
 */
SDL_Surface* CAnimatedSprite::getAnimationImage() const
{
    return m_Image.m_Image;
}

/**
 * sets animation frame
 * @param frame new animation frame
 */
void CAnimatedSprite::setCurrentFrame(int const frame)
{
    m_CurrentFrame = frame;
}

/**
 * sets animation frame width
 * @param width new animation frame width
 */
void CAnimatedSprite::setFrameWidth(int const width)
{
    m_FrameWidth = width;
}

/**
 * sets animation frame height
 * @param height new animation frame height
 */
void CAnimatedSprite::setFrameHeight(int const height)
{
    m_FrameHeight = height;
}

/**
 * sets total number of animation frames
 * @param totalframes new total of animation frames
 */
void CAnimatedSprite::setTotalFrames(int const totalframes)
{
    m_TotalFrames = totalframes;
}

/**
 * sets animation direction
 * @param direction new animation direction
 */
void CAnimatedSprite::setAnimationDirection(int const direction)
{
    m_AnimationDirection = direction;
}

/**
 * sets animation frame delay
 * @param delay new animation frame delay
 */
void CAnimatedSprite::setFrameDelay(int const delay)
{
    m_FrameDelay = delay;
}

/**
 * sets number of columns in animation strip
 * @param columns new number of columns in animation strip
 */
void CAnimatedSprite::setColumns(int const columns)
{
    m_Columns = columns;
}

/**
 * sets animation image
 * @param image new animation image
 */
void CAnimatedSprite::setAnimationImage(SDL_Surface* const image)
{
    m_Image.m_Image = image;
}

/**
 * updates animation
 */
 void CAnimatedSprite::updateAnimation()
{
     // increment frame count
     m_FrameCount++;

    // if frame count is greater then frame delay
    if(m_FrameCount > m_FrameDelay)
    {
        // set frame count to 0
        m_FrameCount = 0;

        // update the animation frame
        m_CurrentFrame += m_AnimationDirection;

        // if we are on the last frame of the animation moving fowards
        if(m_CurrentFrame > m_TotalFrames - 1)
        {
            // set the animation to the first frame
            m_CurrentFrame = 0;
        }
        // otherwise if we are on the first frame of the animation moving backwards
        else if(m_CurrentFrame < 0)
        {
            // set the animation to the last frame
            m_CurrentFrame = m_TotalFrames - 1;
        }
    }
}

/**
* updates the frame of the animation
*/
void CAnimatedSprite::draw(SDL_Surface* screen)
{
    // temporary frame variables
    int frameX = 0;
    int frameY = 0;

    // if the total frames are greater then 0
    if(m_TotalFrames > 0)
    {
        // calculate the frame's X and Y position
        frameX = (m_CurrentFrame % m_Columns) * m_FrameWidth;
        frameY = (m_CurrentFrame / m_Columns) * m_FrameHeight;
    }

    // make a temporary rectangle to hold the source coordinate
    SDL_Rect source;

    // make a temporary rectangle to hold the destination coordinate
    SDL_Rect destination;

    // get the source coordinate
    source.x = frameX + m_FrameWidth;
    source.y = frameY + m_FrameHeight;
    source.w = m_FrameWidth;
    source.h = m_FrameHeight;

    // get the destination coordinate
    destination.x = getBounds().x;
    destination.y = getBounds().y;

    // draw the frame
    SDL_BlitSurface(m_Image.m_Image, &source, screen, &destination);
}
