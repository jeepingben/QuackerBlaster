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

// include required libraries
#include "QuackerBlaster.h"
#include "SDL.h"
#include "CTimer.h"
int main(int argc, char* args[])
{
    //create instance of CGameEngine
    CGameEngine game;

    // initalize the engine
    game.init("Quacker Blaster");

    // was 1 argument passed in
    if(argc == 2)
    {
        // if the argument passed in was "-guntest"
        if(strcmp(args[1], "--guntest") == 0)
        {
            // load the gun test mode
            game.changeState(CGunTestState::instance());
        }
        // otherwise the gun test mode wasn't invoked correctly
        else
        {
            // so start a normal game
            game.changeState(CIntroState::instance());
        }
    }
    // otherwise gun test mode wasn't enabled
    else
    {
        // so load the intro
        game.changeState(CIntroState::instance());
    }

    // main loop
    CTimer fps;
    fps.start();
    const int FRAMES_PER_SECOND = 30;
    while(game.running())
    {
        game.processEvents();
        game.update();
        game.draw();
        if( ( fps.getTicks() < 1000 / FRAMES_PER_SECOND ) ) 
        { 
            //Sleep the remaining frame time 
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.getTicks() ); 
            fps.reset();
        }

    }

    // cleanup the engine
    game.destroy();

    // return success
    return 0;
}
