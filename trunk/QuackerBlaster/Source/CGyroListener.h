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

#ifndef CGYROLISTENER_H
#define CGYROLISTENER_H

#include <SDL.h>
#include "CMouseListener.h"
#include "CTimer.h"
#define XROTATIONNODE "/sys/devices/platform/omap_i2c.2/i2c-2/2-0068/iio:device1/in_anglvel_x_raw"
#define YROTATIONNODE "/sys/devices/platform/omap_i2c.2/i2c-2/2-0068/iio:device1/in_anglvel_y_raw"
#define LBSPERDEGSEC 14.375
/**
 * class for handling input from the openphoenux gyroscope
 */
class CGyroListener : public CMouseListener{
    public:
        CGyroListener();
        void pollMouse(SDL_Event const event);
        void getGyroPosition();
    private: 
        void getGyroRotationsPerSecond(float& x, float& y);
        void getGyroRotations(float& x, float& y);
	float xcal;
	float ycal;
	double lastTime;
	CTimer gyroPollingTimer;
  };
#endif
