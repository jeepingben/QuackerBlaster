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
#include "CPoint2D.h"

/**
 *  default class constructor
 */
 CPoint2D::CPoint2D()
{
    // initalize variables
    m_X = 0.0;
    m_Y = 0.0;
}

/**
 *  double class constructor
 * @param x object's x position as double
 * @param y object's y position as double
 */
 CPoint2D::CPoint2D(double const x, double const y)
{
    // initalize variables
    m_X = x;
    m_Y = y;
}

/**
 *  float class constructor
 * @param x object's x position as float
 * @param y object's y position as float
 */
 CPoint2D::CPoint2D(float const x, float const y)
{
    // initalize variables
    m_X = x;
    m_Y = y;
}

/**
 *  int class constructor
 * @param x object's x position as int
 * @param y object's y position as int
 */
 CPoint2D::CPoint2D(int const x, int const y)
{
    // initalize variables
    m_X = x;
    m_Y = y;
}

// accessor methods

/**
 * returns x coordinate of object as double
 * @return objects x coordinate
 */
double CPoint2D::doubleX() const
{
    return m_X;
}

/**
 * returns x coordinate of object as float
 * @return objects x coordinate
 */
float CPoint2D::floatX() const
{
    return m_X;
}

/**
 * returns x coordinate of object as int
 * @return objects x coordinate
 */
int CPoint2D::intX() const
{
    return m_X;
}

/**
 * returns y coordinate of object as double
 * @return objects y coordinate
 */
double CPoint2D::doubleY() const
{
    return m_Y;
}

/**
 * returns y coordinate of object as float
 * @return objects y coordinate
 */
float CPoint2D::floatY() const
{
    return m_Y;
}

/**
 * returns y coordinate of object as int
 * @return objects y coordinate
 */
int CPoint2D::intY() const
{
    return m_Y;
}

// mutalator functions

/**
 * sets x coordinate of object as double
 * @param x new x coordinate
 */
void CPoint2D::setX(double const x)
{
    m_X = x;
}

/**
 * sets x coordinate of object as float
 * @param x new x coordinate
 */
void CPoint2D::setX(float const x)
{
    m_X = x;
}

/**
 * sets x coordinate of object as int
 * @param x new x coordinate
 */
void CPoint2D::setX(int const x)
{
    m_X = x;
}

/**
 * sets y coordinate of object as double
 * @param y new y coordinate
 */
void CPoint2D::setY(double const y)
{
    m_Y = y;
}

/**
 * sets y coordinate of object as float
 * @param y new y coordinate
 */
void CPoint2D::setY(float const y)
{
    m_Y = y;
}

/**
 * sets y coordinate of object as int
 * @param y new y coordinate
 */
void CPoint2D::setY(int const y)
{
    m_Y = y;
}
