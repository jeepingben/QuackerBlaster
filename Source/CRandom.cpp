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
#include "CRandom.h"

/**
 * class constructor
 */
CRandom::CRandom()
{
    // generate a random seed
    m_Seed = time(NULL);

    // randomize the generator
    srand(m_Seed);
}

/**
 * class overload constructor
 * @param seed random generator seed
 */
CRandom::CRandom(int const seed)
{
    //set the seed value
    m_Seed = seed;

    // randomize the generator
    srand(seed);
}

/**
 * class deconstructor
 */
CRandom::~CRandom()
{

}

/**
 * returns the current seed value
 * @return current seed value
 */
int CRandom::getSeed() const
{
    return m_Seed;
}

/**
 * sets the seed value
 * @param seed new seed value
 */
void CRandom::setSeed(int const seed)
{
    m_Seed = seed;
}

/**
 * generates a random number between a predetermined range
 * @param low lower bounds of random number range
 * @param high higher bounds of random number range
 * @return random random number between the low and high ranges
 */
int CRandom::random(int const low, int const high)
{
    return rand() % (high - low) + low;
}
