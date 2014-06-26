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

#ifndef CGAMESTATE_H
#define CGAMESTATE_H

// include required game libraries
#include "CGameEngine.h"

class CGameEngine;

/**
 * class for managing game states
 */
class CGameState {

    public:
        virtual void init() = 0;
        virtual void destroy() = 0;

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void processEvents(CGameEngine* game) = 0;
        virtual void update(CGameEngine* game) = 0;
        virtual void draw(CGameEngine* game) = 0;

        void changeState(CGameEngine* game, CGameState* state)
        {
            game->changeState(state);
        }

    protected:
        CGameState() {}
};
#endif
