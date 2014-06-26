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
#include <fstream>
#include "CGyroListener.h"

/**
 *  default class constructor
 */
CGyroListener::CGyroListener()
: CMouseListener()
{
this->xcal = 0;
this->ycal = 0;
int calibration_samples = 0;                                                                                 
float x;
float y;
this->gyroPollingTimer.start();
for (; calibration_samples < 50; calibration_samples++)
{
  getGyroRotationsPerSecond(x, y);                                                                         
  xcal+=x;                                                                                          
  ycal+=y;                                                                                          
}
xcal/=calibration_samples;                                                                               
ycal/=calibration_samples;    

}



void CGyroListener::getGyroRotationsPerSecond( float& xDegrees, float& yDegrees)
{                                        
       int rawVal;                                                                                    
       std::ifstream xstream;
       std::ifstream ystream;
       xstream.open (XROTATIONNODE);
       xstream >> rawVal;
       xDegrees = -1.0 * rawVal / LBSPERDEGSEC;                                               
       ystream.open (YROTATIONNODE);                                           
       ystream >> rawVal;                                                       
       yDegrees = -1.0 * rawVal / LBSPERDEGSEC;
}

void CGyroListener::getGyroRotations(float& xDegrees, float& yDegrees)
{                                                                        
         float degPerSecX = 0.0;
	 float degPerSecY = 0.0;                                                                              
         double now = this->gyroPollingTimer.getTicks();
	 getGyroRotationsPerSecond(degPerSecX, degPerSecY);                                                           
         double fraction_of_second = (now - this->lastTime ) ;
	 this->lastTime = now;                                                     
         xDegrees = (degPerSecX - xcal) * fraction_of_second;                                      
         yDegrees = (degPerSecY - ycal) * fraction_of_second; 
}

void CGyroListener::getGyroPosition()                                                                                
{
         //TODO - these don't belong here
	 const int win_width = 480;
	 const int win_height = 620;

         float Xdeg = 0.0;
	 float Ydeg = 0.0;                                                 
         getGyroRotations(Xdeg, Ydeg);                                                                        
         this->m_X -= Xdeg * 250;                                                                    
         if (this->m_X < 0)                                                                           
           this->m_X = 0;                                                                             
         else if (this->m_X > win_width)                                                                 
           this->m_X = win_width;                                                                     
         this->m_Y -= Ydeg * 150;                                                                    
         if (this->m_Y < 0)                                                                           
           this->m_Y = 0;                                                                             
         else if (this->m_Y > win_height)                                                                
           this->m_Y = win_height;
}






/**
 *  polls the queue for mouse event
 * @param event sdl event pointer
 */
 void CGyroListener::pollMouse(SDL_Event const event)
{
    // set mouse clicked to false
    m_Clicked = false;

//	this->getGyroPosition();

    // if a button was pressed
    if(event.type == SDL_MOUSEBUTTONDOWN )
    {
        m_Clicked = true;

        //If the left mouse button was pressed
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            // set left button state to true
            m_LeftDown = true;
        }

        // if the left mouse button was pressed
        if(event.button.button == SDL_BUTTON_RIGHT)
        {
            // set right button state to true
            m_RightDown = true;
        }
    }

    // if a button was depressed
    if(event.type == SDL_MOUSEBUTTONUP )
    {
        // if the left mouse button was depressed
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            // set left button state to true
            m_LeftDown = false;
        }

        // if the left mouse button was depressed
        if(event.button.button == SDL_BUTTON_RIGHT)
        {
            // set right button state to true
            m_RightDown = false;
        }
    }
}
