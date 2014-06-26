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

#ifndef CTEXT_H
#define CTEXT_H

#include <string>
#include "SDL.h"
#include "SDL/SDL_ttf.h"
#include "CPoint2D.h"

/**
 * class for displaying simple text
 */
class CText {
    protected:
        CPoint2D m_Position;
        std::string m_Text;
        TTF_Font *m_Font;
        SDL_Color m_TextColor;
        SDL_Surface *m_TextString;

    public:
        CText();
        ~CText();
        bool init();
        bool load(std::string const filename, int const fontsize);
        bool draw(SDL_Surface* const screen);
        std::string const getText();
        void setText(std::string const text);
        void setColor(int const rgbred, int const rgbgreen, int const rgbblue);
        void setPosition(double const x, double const y);
  };
#endif
