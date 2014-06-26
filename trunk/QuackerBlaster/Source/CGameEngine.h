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

#ifndef CGAMEENGINE_H
#define CGAMEENGINE_H

// include required libraries
#include <vector>
#include <SDL.h>

class CGameState;

/**
 * class for processing events, states and game objects
 */
class CGameEngine {

    private:
        /** stack of game states */
        std::vector<CGameState*> states;
        bool m_Running;
        bool m_fullscreen;

    public:
        SDL_Surface* m_Screen;

        void init(const char* title, int const width=480, int const height=600, int const bpp=0, bool const fullscreen=0, bool hidemouse=true);
        void destroy();

        void changeState(CGameState* const state);
        void pushState(CGameState* const state);
        void popState();

        void processEvents();
        void update();
        void draw();

        bool running();
        void quit();
  };
#endif
