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
#include "CGameObject.h"

/*
 * class constructor
 */
 CGameObject::CGameObject()
{
    // initalize variables
    m_Alive = false;
    m_X = 0.0;
    m_Y = 0.0;
    m_VX = 0.0;
    m_VY = 0.0;
    m_MoveAngle = 0.0;
    m_FaceAngle = 0.0;
}

// accessor methods

/*
 * returns if object is alive
 * @return is object alive
 */
 bool CGameObject::isAlive() const
{
    return m_Alive;
}

/*
 * returns x position of object
 * @return x position
 */
float CGameObject::getX() const
{
    return m_X;
}

/*
 * returns y position of object
 * @return y position
 */
float CGameObject::getY() const
{
    return m_Y;
}

/*
 * returns x velocity of object
 * @ return x velocity
 */
float CGameObject::getVX() const
{
    return m_VX;
}

/*
 *   returns y velocity of object
 *   @return y velocity
 */
float CGameObject::getVY() const
{
    return m_VY;
}

/*
 *   returns move angle of object
 *   @return move angle
 */
float CGameObject::getMoveAngle() const
{
    return m_MoveAngle;
}

/*
 *   returns face angle of object
 *   @return face angle
 */
float CGameObject::getFaceAngle() const
{
    return m_FaceAngle;
}

// mutalator functions

/*
 *   sets if object is alive
 *   @param alive new object alive status
 */
void CGameObject::setAlive(bool const alive)
{
    m_Alive = alive;
}

/*
 *   sets x position of object
 *   @param x new x position
 */
void CGameObject::setX(float const x)
{
    m_X = x;
}

/*
 *   increments x position of object
 *   @param inc increment of new x position
 */
void CGameObject::incrementX(float const inc)
{
    m_X += inc;
}

/*
 *   decrements x position of object
 *   @param dec decrement of new x position
 */
void CGameObject::decrementX(float const dec)
{
    m_X -= dec;
}

/*
 *   sets y position of object
 *   @param y new y position
 */
void CGameObject::setY(float const y)
{
    m_Y = y;
}

/*
 *   increments y position of object
 *   @param inc increment of new y position
 */
void CGameObject::incrementY(float const inc)
{
    m_Y += inc;
}

/*
 *   decrements y position of object
 *   @param dec decrement of new y position
 */
void CGameObject::decrementY(float const dec)
{
    m_Y -= dec;
}

/*
 *   sets x velocity of object
 *   @param vx new x velocity
 */
void CGameObject::setVX(float const vx)
{
    m_VX = vx;
}

/*
 *   increments x velocity of object
 *   @param inc increment of new x velocity
 */
void CGameObject::incrementVX(float const inc)
{
    m_VX += inc;
}

/*
 *   decrements x velocity of object
 *   @param dec decrement of new x velocity
 */
void CGameObject::decrementVX(float const dec)
{
    m_VX -= dec;
}

/*
 *   sets y velocity of object
 *   @param vy new y velocity
 */
void CGameObject::setVY(float const vy)
{
    m_VY = vy;
}

/*
 *   increments y velocity of object
 *   @param inc increment of new y velocity
 */
void CGameObject::incrementVY(float const inc)
{
    m_VY += inc;
}

/*
 *   decrements y velocity of object
 *   @param dec decrement of new y velocity
 */
void CGameObject::decrementVY(float const dec)
{
    m_VY -= dec;
}

/*
 *   sets move of object
 *   @param angle new move angle
 */
void CGameObject::setMoveAngle(float const angle)
{
    m_MoveAngle = angle;
}

/*
 *   increments move angle of object
 *   @param inc increment of new move angle
 */
void CGameObject::incrementMoveAngle(float const inc)
{
    m_MoveAngle += inc;
}

/*
 *   decrements move angle of object
 *   @param dec decrement of new move angle
 */
void CGameObject::decrementMoveAngle(float const dec)
{
    m_MoveAngle -= dec;
}

/*
 *   sets face of object
 *   @param angle new face angle
 */
void CGameObject::setFaceAngle(float const angle)
{
    m_FaceAngle = angle;
}

/*
 *   increments face angle of object
 *   @param inc increment of new face angle
 */
void CGameObject::incrementFaceAngle(float const inc)
{
    m_FaceAngle += inc;
}

/*
 *   decrements face angle of object
 *   @param dec decrement of new face angle
 */
void CGameObject::decrementFaceAngle(float const dec)
{
    m_FaceAngle -= dec;
}
