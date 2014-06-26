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

// include class definition
#include "CPlayState.h"

CPlayState CPlayState::m_PlayState;

/**
 * class constructor
 */
 CPlayState::CPlayState()
 {

 }

/**
 * initalizes game objects
 */
void CPlayState::init()
{
    log.EnableLogging(true);

    // pointer to screen surface
    SDL_Surface* screen = NULL;

    // get pointer to screen surface
    screen = SDL_GetVideoSurface();

    // load background file
    if(!g_Background.load("data/background.png"))
    {
        log.write("ERROR: Failed to load File:data/background.png State:PlayState");
        exit(-1);
    }

    // load crosshair file
    if(!g_Crosshair.load("data/crosshair.png"))
    {
        log.write("ERROR: Failed to load File:data/crosshair.png State:PlayState");
        exit(-2);
    }

    // load duck file
    if(!g_Duck.load("data/duck.png"))
    {
        log.write("ERROR: Failed to load File:data/duck.png State:PlayState");
        exit(-3);
    }

    // set the duck's initial x position
    g_Duck.position().setX(screen->w / 2);

    // set the duck's initial y position
    g_Duck.position().setY(screen->h / 2);

    // create instance of the random generator
    if(g_Random.random(1, 100) < 50)
    {
        // set duck's inital x velocity
        g_Duck.velocity().setX(3.1);
    }
    else
    {
        // set duck's inital x velocity
        g_Duck.velocity().setX(-3.1);
    }

    // create instance of the random generator
    if(g_Random.random(1, 100) < 50)
    {
        // set duck's inital y velocity
        g_Duck.velocity().setY(3.1);
    }
    else
    {
        // set duck's inital y velocity
        g_Duck.velocity().setY(-3.1);
    }

    for(int i=0; i < 11; i++)
    {
        if(!g_DuckSilhouette[i].load("data/silhouette.png"))
        {
            log.write("ERROR: Failed to load File:data/silhouette.png State:PlayState");
            exit(-4);
        }

        // set the silhouette's x positon
        g_DuckSilhouette[i].setX(screen->w - (g_DuckSilhouette[i].getWidth() * i));

        // set the silhouette's y positon
        g_DuckSilhouette[i].setY(screen->h - g_DuckSilhouette[i].getHeight());
    }

    for(int i=0; i < 11; i++)
    {
        if(!g_DuckSilhouetteHit[i].load("data/silhouette_hit.png"))
        {
            log.write("ERROR: Failed to load File:data/silhouette_hit.png State:PlayState");
            exit(-5);
        }

        // set the hit silhouette's x positon
        g_DuckSilhouetteHit[i].setX(screen->w - (g_DuckSilhouette[i].getWidth() * i));

        // set the hit silhouette's y positon
        g_DuckSilhouetteHit[i].setY(screen->h - g_DuckSilhouette[i].getHeight());
    }

    // load bullets
    for(int i=0; i < 4; i++)
    {
        if(!g_BulletIcons[i].load("data/bullet_icon.png"))
        {
            log.write("ERROR: Failed to load File:data/bullet_icon.png State:PlayState");
            exit(-6);
        }

        // set the silhouette's x positon
        g_BulletIcons[i].setX(80 - (g_BulletIcons[i].getWidth() * i));

        // set the silhouette's y positon
        g_BulletIcons[i].setY(screen->h - g_BulletIcons[i].getHeight());
    }

    // load the font and initalize the round counter
    if(!g_Round.load("data/lunchds.ttf", 16))
    {
        log.write("ERROR: Failed to load File:data/lunchds.ttf State:PlayState");
        exit(-7);
    }

    // round counter was initalizes successfully so set it's position
    g_Round.setPosition(10, screen->h - 60);

    // set the text
    g_Round.setText("Round: ");

    // load the font and initalize the score
    if(!g_Score.load("data/lunchds.ttf", 16))
    {
        log.write("ERROR: Failed to load File:data/lunchds.ttf State:PlayState");
        exit(-8);
    }

    // score was initalizes successfully so set it's position
    g_Score.setPosition(160, screen->h - 60);

    // set the text
    g_Score.setText("Score: ");

    // load gun fire audio file
    if(!g_Fire.load("data/fire.wav"))
    {
        log.write("ERROR: Failed to load File:data/fire.wav State:PlayState");
        exit(-9);
    }

    // load splat audio file
    if(!g_Splat.load("data/splat.wav"))
    {
        log.write("ERROR: Failed to load File:data/splat.wav State:PlayState");
        exit(-10);
    }

    // clear the scoreboard
    for(int i=0; i < 11; i++)
    {
        m_DuckScoreBoard[i] = false;
    }

    // set duck hit to false
    m_DuckHit = false;

    // set the duck counter's initial value
    m_DuckCounter = 1;

    // set starting round
    g_Round.setCounterValue(1);

    // initalize score
    g_Score.setCounterValue(0);

    // player starts with 3 bullets
    m_BulletsRemaining = 3;

    // reset all the timers
    g_DuckEscapeTimer.reset();
    g_ProgressTimer.reset();

    // start the timer
    g_DuckEscapeTimer.start(true);
}

/**
 * destroys all game objects and releases memory
 */
void CPlayState::destroy()
{
}

/**
 * pauses state
 */
void CPlayState::pause()
{

}

/**
 * resumes state
 */
void CPlayState::resume()
{

}

/**
 * game loop
 * @param game game engine instance
 */
void CPlayState::processEvents(CGameEngine* const game)
{
    // event thread
    SDL_Event event;

    // while there's an event to handle
    while(SDL_PollEvent(&event))
    {
        // if the user has x'ed the window
        if(event.type == SDL_QUIT)
        {
                // terminate the game
                game->quit();
        }

            // poll for mouse events
            m_MouseListener.pollMouse(event);

        // if the left mouse button was pressed this frame
            // set the crosshair's position to the mouse's cursor^M                                                              
        if(m_MouseListener.isClicked())
        {
            if(m_MouseListener.isLeftButtonDown())
            {
                // if the duck isn't dead already
                if(m_DuckHit == false)
                {
                    // if the player has bullets remaining and the time hasn't expired
                    if(m_BulletsRemaining > 0 && g_DuckEscapeTimer.getTicks() < 5.0 - (g_Round.getCounterValue() * .10) && g_DuckEscapeTimer.isRunning())
                    {
                        // play the fire sound effect
                        g_Fire.play();

                        // remove 1 bullet from the player
                        m_BulletsRemaining -= 1;

                        // did the player hit the duck
                        if(g_Crosshair.collidesWith(g_Duck))
                        {
                            // set the duck's hit state to true
                            m_DuckHit = true;

                            // stop the timer
                            g_DuckEscapeTimer.stop();

                            // set the duck x velocity to 0
                            g_Duck.velocity().setX(0);

                            // and the duck's y velocity to 1
                            g_Duck.velocity().setY(12);

                            //calculate the score increment based on the round
                            int round = g_Round.getCounterValue();

                            // if we are in the first 5 rounds
                            if(round < 6)
                            {
                                // increment the player's score by 500
                                g_Score.incrementCounter(500);
                            }
                            // if we are in round 6 - 10
                            else if(round > 5 && round < 11)
                            {
                                // increment the player's score by 500
                                g_Score.incrementCounter(800);
                            }
                            // if we are in round 11 - 15
                            else if(round > 10)
                            {
                                // increment the player's score by 500
                                g_Score.incrementCounter(1000);
                            }

                            // update the scoreboard
                            m_DuckScoreBoard[m_DuckCounter] = true;
                        }
                    }
                }
            }
        }
    }
}

/**
 * updates all game objects
 * @param game game engine instance
 */
void CPlayState::update(CGameEngine* const game)
{
    // pointer to screen surface
    SDL_Surface* screen = NULL;

    // get pointer to screen surface
    screen = SDL_GetVideoSurface();

    m_MouseListener.getGyroPosition();
    // if the duck escape timer has expired
    if(g_DuckEscapeTimer.getTicks() >= 5.0 - (g_Round.getCounterValue() * .10) && g_DuckEscapeTimer.isRunning())
    {
        // stop the timer
        g_DuckEscapeTimer.stop();

        // set the ducks x velocity to 0
        g_Duck.velocity().setX(0);

        // set the ducks x velocity to fly upward
        g_Duck.velocity().setY(-2);
    }

    // if the progress timer has expired
    if(g_ProgressTimer.getTicks() >= 1.0 && !g_DuckEscapeTimer.isRunning())
    {
        g_ProgressTimer.stop();

        // set the ducks x position
        g_Duck.position().setX(64);

        // set the ducks y position
        g_Duck.position().setY(screen->h - (g_Duck.getHeight() * 5));

        // create instance of the random generator
        if(g_Random.random(1, 100) < 50)
        {
            // set duck's inital x velocity
            g_Duck.velocity().setX(4.5 + g_Round.getCounterValue() * 0.3);
        }
        else
        {
            // set duck's inital y velocity
            g_Duck.velocity().setX(-(4.5 + g_Round.getCounterValue() * 0.3));
        }

        // set the ducks y velocity
        g_Duck.velocity().setY(-(4.5 + g_Round.getCounterValue() * 0.3));

        // set the duck alive status to true
        g_Duck.setAlive(true);

        // if this isn't the end of the round
        if(m_DuckCounter < 10)
        {
            // increment the duck counter
            m_DuckCounter++;
        }
        else
        {
            // number of ducks hit
            int ducksHit;

            // set ducks hit to 0
            ducksHit = 0;

            // for each duck counter in the scoreboard
            for(int i=0; i < 11; i++)
            {
                //if the player hit the duck
                if(m_DuckScoreBoard[i] == true)
                {
                    ducksHit++;
                }

                // clear the duck scoreboard
                m_DuckScoreBoard[i] = false;
            }

            // get current round
            int round = g_Round.getCounterValue();

            // if we are in the first 10 rounds and 6 ducks were not hit
            if(round < 11 && ducksHit < 6)
            {
                // change the game state to the gameover state
                game->changeState(CGameOverState::instance());
            }
            // if we are in round 11, 12 and 7 ducks were not hit
            else if((round == 11 || round == 12) && ducksHit < 7)
            {
                // change the game state to the gameover state
                game->changeState(CGameOverState::instance());
            }
            // if we are in round 13, 14 and 8 ducks were not hit
            else if((round == 13 || round == 14) && ducksHit < 8)
            {
                // change the game state to the gameover state
                game->changeState(CGameOverState::instance());
            }
            // if we are in round 15 - 19 and 9 ducks were not hit
            else if(round > 14 && round < 20 && ducksHit < 9)
            {
                // change the game state to the gameover state
                game->changeState(CGameOverState::instance());
            }
            // if we are in round round 20 and beyond and 10 ducks were not hit
            else if(round > 19 && ducksHit < 10)
            {
                // change the game state to the gameover state
                game->changeState(CGameOverState::instance());
            }

             // go to the next round
            g_Round.setCounterValue(g_Round.getCounterValue() + 1);

            // set duck counter to 0
            m_DuckCounter = 1;
        }

        // set duck hit flag to false
        m_DuckHit = false;

        // reset the players bullets
        m_BulletsRemaining = 3;

        // restart the duck escape timer
        g_DuckEscapeTimer.start(true);

        g_ProgressTimer.reset();
    }

    // set the crosshair's position to the mouse's cursor
    g_Crosshair.position().setX(m_MouseListener.getX() - (g_Crosshair.getWidth() / 2));
    g_Crosshair.position().setY(m_MouseListener.getY() - (g_Crosshair.getHeight() / 2));

    g_Crosshair.update();

    // determine the ducks new x position based on it's velocity
    double tempX = g_Duck.position().doubleX() + g_Duck.velocity().doubleX();

    // if the duck intersects the left boundry
    if(intersectsLeftBoundry(tempX, 0))
    {
        // set it's x position to the left boundry
        g_Duck.position().setX(0);

        // and reverse it's velocity
        g_Duck.velocity().setX(-g_Duck.velocity().doubleX());
    }

    // if the duck intersects the right boundry
    if(intersectsRightBoundry(tempX, g_Duck.getWidth()))
    {
        // set it's x position to the right boundry
        g_Duck.position().setX(game->m_Screen->w - g_Duck.getWidth());

        // and reverse it's velocity
        g_Duck.velocity().setX(-g_Duck.velocity().doubleX());
    }

    // determine the ducks new y position based on it's velocity
    double tempY = g_Duck.position().doubleY() + g_Duck.velocity().doubleY();

    // if the duck intersects the top boundry
    if(intersectsTopBoundry(tempY, 0))
    {
        // if the timer has expired
        if(g_DuckEscapeTimer.getTicks() >= 5.0 - (g_Round.getCounterValue() * .10))
        {
            // set it's y velocity to 0
            g_Duck.velocity().setY(0);

            // and set it's alive status to false
            g_Duck.setAlive(false);

            // start the progress timer
            g_ProgressTimer.start(true);
        }
        else
        {
            // set it's y position to the top boundry
            g_Duck.position().setY(0);

            // and reverse it's velocity
            g_Duck.velocity().setY(-g_Duck.velocity().doubleY());
        }
    }

    // if the duck intersects the bottom boundry
    if(intersectsBottomBoundry(tempY, g_Duck.getHeight()))
    {
        // if the duck is dead
        if(m_DuckHit == true)
        {
            // set it's y velocity to 0
            g_Duck.velocity().setY(0);

            // and set it's alive status to false
            g_Duck.setAlive(false);

            // play the splat sound effect
            g_Splat.play();

            // start the progress timer
            g_ProgressTimer.start(true);
        }
        // otherwise the duck isn't dead
        else
        {
        // set it's y position to the bottom boundry
        g_Duck.position().setY(game->m_Screen->h - g_Duck.getHeight());

        // and reverse it's velocity
        g_Duck.velocity().setY(-g_Duck.velocity().doubleY());
        }
    }

    // update the duck's position
    g_Duck.update();
}

/**
 * draws all game objects
 * @param game game engine instance
 */
void CPlayState::draw(CGameEngine* const game)
{
    // if the player has taken too long to shot the duck
    if(g_DuckEscapeTimer.getTicks() >= 5.0 - (g_Round.getCounterValue() * .10))
    {
        // set the sky color to pink
        SDL_FillRect(game->m_Screen, NULL, 0xFFE5B4);
    }
    // otherwise the player still has time
    else
    {
        // so set the sky color to blue
        SDL_FillRect(game->m_Screen, NULL, 0x87CEEB);
    }

    // draw the background
    g_Background.draw(game->m_Screen);

    // draw the crosshair
    g_Crosshair.draw(game->m_Screen);

    // if the duck is alive
    if(g_Duck.alive())
    {
        // draw the duck
        g_Duck.draw(game->m_Screen);
    }

    // draw the current round
    g_Round.draw(game->m_Screen);

    // draw the score
    g_Score.draw(game->m_Screen);

    // draw the bullet icons
    for(int i=0; i < m_BulletsRemaining; i++)
    {
        g_BulletIcons[i].draw(game->m_Screen);
    }

    for(int i=0; i < 11; i++)
    {
        // if the duck has been hit for that stage
        if(m_DuckScoreBoard[11 - i] == true)
        {
            // draw the duck hit marker
            g_DuckSilhouetteHit[i].draw(game->m_Screen);
        }
        // otherwise the duck wasn't hit that stage
        else
        {
            // so draw the silhouette
            g_DuckSilhouette[i].draw(game->m_Screen);
        }
    }

    // update Screen
    SDL_Flip(game->m_Screen);
}

/**
 * returns static class instance
 * @return static class instance
 */
CPlayState* CPlayState::instance()
{
    return &m_PlayState;
}

/**
 * Returns if object intersects bottom boundry
 * @param y objects y position
 * @param offset offset to y position
 * @return if object intersects bottom boundry
 */
bool CPlayState::intersectsBottomBoundry(double y, double offset)
{
     // pointer to screen surface
    SDL_Surface* screen = NULL;

    // get pointer to screen surface
    screen = SDL_GetVideoSurface();

    return (y > screen->h - offset);
}

/**
 * Returns if object intersects left boundry
 * @param x objects x position
 * @param offset offset to x position
 * @return if object intersects left boundry
 */
bool CPlayState::intersectsLeftBoundry(double x, double offset)
{
    return (x < 0 + offset);
}

/**
 * Returns if object intersects right boundry
 * @param x objects x position
 * @param offset offset to x position
 * @return if object intersects right boundry
 */
bool CPlayState::intersectsRightBoundry(double x, double offset)
{
     // pointer to screen surface
    SDL_Surface* screen = NULL;

    // get pointer to screen surface
    screen = SDL_GetVideoSurface();

    return (x > screen->w - offset);
}

/**
 * Returns if object intersects top boundry
 * @param y objects y position
 * @param offset offset to y position
 * @return if object intersects top boundry
 */
bool CPlayState::intersectsTopBoundry(double y, double offset)
{
    return (y < 0 + offset);
}
