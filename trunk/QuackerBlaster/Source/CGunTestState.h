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

#ifndef CGUNTESTSTATE_H
#define CGUNTESTSTATE_H

// include required libraries
#include "CGameState.h"
#include <SDL.h>
#include "CErrorLogger.h"
#include "CImageEntity.h"
#include "CSprite.h"
#include "CMouseListener.h"
#include "CSoundClip.h"

/**
 * class for managing the gun test state (mode for testing lightgun)
 */
class CGunTestState : public CGameState {

    private:
        CErrorLogger log;
        CMouseListener m_MouseListener;

        // game object instances
        CSprite g_Crosshair;
        CSprite g_ShotMarker;
        CSoundClip g_Fire;
    public:
        void init();
        void destroy();

        void pause();
        void resume();

        void processEvents(CGameEngine* const game);
        void update(CGameEngine* const game);
        void draw(CGameEngine* const game);

        static CGunTestState* instance();

        bool intersectsBottomBoundry(double y, double offset);
        bool intersectsLeftBoundry(double x, double offset);
        bool intersectsRightBoundry(double x, double offset);
        bool intersectsTopBoundry(double y, double offset);

    protected:
        CGunTestState();

    private:
        static CGunTestState m_GunTestState;
  };
#endif
