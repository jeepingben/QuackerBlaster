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

#ifndef TIMER_H
#define TIMER_H

// include required game libraries
#include <ctime>

/**
 * class for timed events
 */
class CTimer
{
    private:
        clock_t m_StartedAt;
        clock_t m_StoppedAt;
        bool m_Running;

    public:
        CTimer(bool const startNow = false);
        ~CTimer();


        void start(bool const reset = false);
        void stop();
        void reset();
        bool isRunning() const;
        double getTicks() const;
};
#endif
