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

#ifndef CRANDOM_H
#define CRANDOM_H

// include required game libraries
#include <cstdlib>
#include <ctime>

/**
 * class for generating random numbers
 */
class CRandom
{
    private:
        int m_Seed;

    public:
        CRandom();
        CRandom(int const seed);
        ~CRandom();
        int getSeed() const;
        void setSeed(int const seed);
        int random(int const low, int const high);
};
#endif
