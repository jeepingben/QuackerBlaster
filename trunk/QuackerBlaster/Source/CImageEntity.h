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

#ifndef CIMAGEENTITY_H
#define CIMAGEENTITY_H

// include required libraries
#include "CGameObject.h"
#include <string>
#include <SDL/SDL_image.h>

/**
 * class for basic image image mulipulation
 */
class CImageEntity : public CGameObject {
public:
        CImageEntity();
        ~CImageEntity();
        int getWidth() const;
        int getHeight() const;
        double getCenterX() const;
        double getCenterY() const;
        bool load(std::string const filename);
        void draw(SDL_Surface* const screen);
        SDL_Rect getBounds();
        SDL_Surface* m_Image;
  };
#endif
