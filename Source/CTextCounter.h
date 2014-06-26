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

#ifndef CTEXTCOUNTER_H
#define CTEXTCOUNTER_H

#include <string>
#include "SDL.h"
#include "SDL/SDL_ttf.h"
#include "CText.h"
#include "CPoint2D.h"

/**
 * class for displaying text with a counter
 */
class CTextCounter : public CText {
    protected:
        int m_Counter;

    public:
        CTextCounter();
        ~CTextCounter();
        bool draw(SDL_Surface* const screen);
        int getCounterValue() const;
        void setCounterValue(int const value);
        void incrementCounter(int const inc);
        void decrementCounter(int const dec);
        void resetCounter();
  };
#endif
