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

#ifndef CPLAYSTATE_H
#define CPLAYSTATE_H

// include required libraries
#include "CGameState.h"
#include "CGameOverState.h"
#include <SDL.h>
#include "CErrorLogger.h"
#include "CImageEntity.h"
#include "CSprite.h"
#include "CMouseListener.h"
#include "CText.h"
#include "CTextCounter.h"
#include "CTimer.h"
#include "CSoundClip.h"
#include "CRandom.h"

/**
 * class for managing the play state (game mode)
 */
class CPlayState : public CGameState {

    private:
        CErrorLogger log;
        CMouseListener m_MouseListener;
        CTimer g_DuckEscapeTimer;
        CTimer g_ProgressTimer;
        CRandom g_Random;
        int m_BulletsRemaining;
        int m_DuckCounter;
        bool m_DuckScoreBoard[11];
        bool m_DuckHit;

        // game object instances
        CImageEntity g_Background;
        CImageEntity g_DuckSilhouette[11];
        CImageEntity g_DuckSilhouetteHit[11];
        CImageEntity g_BulletIcons[4];
        CTextCounter g_Round;
        CTextCounter g_Score;
        CSprite g_Crosshair;
        CSprite g_Duck;
        CSoundClip g_Fire;
        CSoundClip g_Splat;

    public:
        void init();
        void destroy();

        void pause();
        void resume();

        void processEvents(CGameEngine* const game);
        void update(CGameEngine* const game);
        void draw(CGameEngine* const game);

        static CPlayState* instance();

        bool intersectsBottomBoundry(double y, double offset);
        bool intersectsLeftBoundry(double x, double offset);
        bool intersectsRightBoundry(double x, double offset);
        bool intersectsTopBoundry(double y, double offset);

    protected:
        CPlayState();

    private:
        static CPlayState m_PlayState;
  };
#endif
