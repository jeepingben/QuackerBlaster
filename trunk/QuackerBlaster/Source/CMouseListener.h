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

#ifndef CMOUSELISTENER_H
#define CMOUSELISTENER_H

#include <SDL.h>

/**
 * class for handling mouse input
 */
class CMouseListener {
    protected:
        double m_X;
        double m_Y;
        bool m_Clicked;
        bool m_LeftDown;
        bool m_RightDown;

    public:
        CMouseListener();
        float getX() const;
        float getY() const;
        bool isClicked() const;
        bool isLeftButtonDown() const;
        bool isRightButtonDown() const;
        void pollMouse(SDL_Event const event);
  };
#endif
