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

#ifndef CINTROSTATE_H
#define CINTROSTATE_H

// include required libraries
#include "CGameState.h"
#include "CPlayState.h"
#include "CErrorLogger.h"
#include <SDL.h>
#include "CImageEntity.h"
#include "CMouseListener.h"
#include "CText.h"

/**
 * class for handling the intro state (title screen)
 */
class CIntroState : public CGameState {

    private:
        CErrorLogger log;
        CMouseListener m_MouseListener;

        // game object instances
        CImageEntity g_Background;
        CText g_Title;
        CText g_PressTrigger;
        CText g_Version;

    public:
        void init();
        void destroy();

        void pause();
        void resume();

        void processEvents(CGameEngine* game);
        void update(CGameEngine* game);
        void draw(CGameEngine* game);

        static CIntroState* instance();

    protected:
        CIntroState();

    private:
        static CIntroState m_IntroState;
  };
#endif
