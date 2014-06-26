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
#include "CTimer.h"

/**
 * class constructor
 */
CTimer::CTimer(bool const startNow)
{
    // initialize start time
    m_StartedAt = 0;

    // initalize pause time
    m_StoppedAt = 0;

    // set running to false
    m_Running = false;

    // if you want to start the timer now
    if (startNow)
    {
        // start it and reset the timer
        start(true);
    }
}

/**
 * class deconstructor
 */
CTimer::~CTimer()
{

}

/**
* starts the timer
*/
void CTimer::start(bool const reset)
{
    // if the timer isn't running
     if (!m_Running)
    {
        // if the timer is to be reset
        if (reset)
        {
            // set the start time to the current time
            m_StartedAt = clock();
        }

    // set running to true
    m_Running = true;
    }
}

/**
 * stops the timer
 */
void CTimer::stop()
{
    // if the timer is running
     if (m_Running)
    {
        // set the stop time to the current time
        m_StoppedAt = clock();

        // set running to false
        m_Running = false;
    }
}

/**
 * resets the timer
 */
void CTimer::reset()
{
    m_StartedAt = clock();
}

/**
 * returns if the timer is running
 * @return true if the timer is running otherwise false
 */
bool CTimer::isRunning() const
{
    return m_Running;
}

double CTimer::getTicks() const
{
    // if the timer has been started
    if(m_Running)
    {
        // return current eclipsed time
        return (double)(clock() - m_StartedAt) / CLOCKS_PER_SEC;
    }

    // otherwise return time the timer was stopped at
	 return (double)(m_StoppedAt - m_StartedAt) / CLOCKS_PER_SEC;
}
