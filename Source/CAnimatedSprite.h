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

#ifndef CANIMATEDSPRITE_H
#define CANIMATEDSPRITE_H

// include required library
#include "CSprite.h"

/**
 * class for animated sprites
 */
class CAnimatedSprite : public CSprite
{
    private:
        CImageEntity m_Image;
        int m_CurrentFrame;
        int m_TotalFrames;
        int m_AnimationDirection;
        int m_FrameCount;
        int m_FrameDelay;
        int m_FrameWidth;
        int m_FrameHeight;
        int m_Columns;

    public:
        CAnimatedSprite();
        bool load(std::string const filename, int const columns, int const rows, int const width, int const height);
        int currentFrame() const;
        int frameWidth() const;
        int frameHeight() const ;
        int totalFrames() const ;
        int animationDirection() const;
        int frameDelay() const;
        int columns() const;
        SDL_Surface* getAnimationImage() const;
        void setCurrentFrame(int const frame);
        void setFrameWidth(int const width);
        void setFrameHeight(int const height);
        void setTotalFrames(int const totalframes);
        void setAnimationDirection(int const direction);
        void setFrameDelay(int const delay);
        void setColumns(int const columns);
        void setAnimationImage(SDL_Surface* const image);
        void updateAnimation();
        void draw(SDL_Surface* screen);
};
#endif
