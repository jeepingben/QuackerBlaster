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
#include "CSprite.h"
#include "SDL_collide.h"

/**
 * class constructor
 */
 CSprite::CSprite()
{
    // initalize variables
    m_Entity.setAlive(true);
    m_Position.setX(0.0);
    m_Position.setY(0.0);
    m_Velocity.setX(0.0);
    m_Velocity.setY(0.0);
}

/**
 * loads the image
 * @param filename image file to load
 */
bool CSprite::load(std::string const filename)
 {
    // load the image
    return m_Entity.load(filename);
 }

/**
 * draws the image
 * @param screen pointer to screen surface
 */
void CSprite::draw(SDL_Surface* const screen)
 {
    // draw the image
    m_Entity.draw(screen);
 }

/**
 * updates the sprites position
 */
void CSprite::update()
 {
    // update sprites position based on its' velocity
    m_Position.setX(m_Position.doubleX() + m_Velocity.doubleX());
    m_Position.setY(m_Position.doubleY() + m_Velocity.doubleY());
    m_Entity.setX(m_Position.doubleX());
    m_Entity.setY(m_Position.doubleY());
 }

// methods related to automatic rotation factor

/**
 * Returns rotation rate
 * @return rotation rate of sprite
 */
double CSprite::rotationRate() const
{
    return m_rotationRate;
}

/**
 * sets rotation rate of sprite
 * @param rate new rotation rate of sprite
 */
void CSprite::setRotationRate(double const rate)
{
    m_rotationRate = rate;
}

/**
 * updates sprites rotation
 */
void CSprite::updateRotation()
{
    // set the face angle
    m_Entity.setFaceAngle(m_Entity.getFaceAngle() + m_rotationRate);

    // if the face angle is negitive
    if(m_Entity.getFaceAngle() < 0)
    {
        // set the face angle within the boundry
        m_Entity.setFaceAngle(360 - m_rotationRate);
    }
    // otherwise if the face angle is greater then 360
    else if(m_Entity.getFaceAngle() > 360)
    {
        // set the face angle within the boundry
        m_Entity.setFaceAngle(m_rotationRate);
    }
}

// generic sprite state variable (alive, dead, collided)

/**
 * returns the sprites current state
 * @return current state of sprite
 */
int CSprite::state() const
{
   return m_CurrentState;
}

/**
 * sets the sprites current state
 * @param state new state of sprite
 */
void CSprite::setState(int const state)
{
    // set new sprite state
    m_CurrentState = state;
}

/**
 * returns sprites' bounding rectangle
 * @return bounding rectangle of sprite
 */
SDL_Rect CSprite::getBounds()
{
   return m_Entity.getBounds();
}

/**
 * returns sprites' position
 * @return position of sprite
 */
CPoint2D &CSprite::position()
{
    return m_Position;
}

/**
 * returns sprites' velocity
 * @return velocity of sprite
 */
CPoint2D &CSprite::velocity()
{
    return m_Velocity;
}

/**
 * returns center of sprites as point
 * @return center of sprite
 */
CPoint2D CSprite::center()
{
    // get x center of entity
    int x = m_Entity.getCenterX();

    // get x center of entity
    int y = m_Entity.getCenterY();

    // create local instance of CPoint2D
    CPoint2D position(x, y);

    // return center of sprite
    return position;
}

// generic variable for selectivly using sprites

/**
 * returns if sprite is alive
 * @return alive status of sprite
 */
bool CSprite::alive() const
{
    // return alive status
    return m_Entity.isAlive();
}

/**
 * sets alive status of sprite
 * @param alive new alive status of sprite
 */
void CSprite::setAlive(bool const alive)
{
    // set  new alive status
    m_Entity.setAlive(alive);
}

/**
 * Returns face angle of sprite as double
 * @return face angle of sprite as double
 */
double CSprite::doubleFaceAngle() const
{
    return m_Entity.getFaceAngle();
}

/**
 * Sets face angle of sprite as double
 * @param angle new face angle of sprite as double
 */
void CSprite::setFaceAngle(double const angle)
{
    m_Entity.setFaceAngle(angle);
}

/**
 * Returns face angle of sprite as float
 * @return face angle of sprite as float
 */
float CSprite::floatFaceAngle() const
{
    return m_Entity.getFaceAngle();
}

/**
 * Sets face angle of sprite as float
 * @param angle new face angle of sprite as float
 */
void CSprite::setFaceAngle(float const angle)
{
    m_Entity.setFaceAngle(angle);
}

/**
 * Returns face angle of sprite as int
 * @return face angle of sprite as int
 */
int CSprite::intFaceAngle() const
{
    return m_Entity.getFaceAngle();
}

/**
 * Sets face angle of sprite as int
 * @param angle new face angle of sprite as int
 */
void CSprite::setFaceAngle(int const angle)
{
    m_Entity.setFaceAngle(angle);
}

// move angle indicates which direction sprite is moving

/**
 * Returns move angle of sprite as double
 * @return move angle of sprite as double
 */
double CSprite::doubleMoveAngle() const
{
    return m_Entity.getMoveAngle();
}

/**
 * Sets move angle of sprite as double
 * @param angle new move angle of sprite as double
 */
void CSprite::setMoveAngle(double const angle)
{
    m_Entity.setMoveAngle(angle);
}

/**
 * Returns move angle of sprite as float
 * @return move angle of sprite as float
 */
float CSprite::floatMoveAngle() const
{
    return m_Entity.getMoveAngle();
}

/**
 * Sets move angle of sprite as float
 * @param angle new move angle of sprite as float
 */
void CSprite::setMoveAngle(float const angle)
{
    m_Entity.setMoveAngle(angle);
}

/**
 * Returns move angle of sprite as int
 * @return move angle of sprite as int
 */
int CSprite::intMoveAngle() const
{
    return m_Entity.getMoveAngle();
}

/**
 * Sets move angle of sprite as int
 * @param angle new move angle of sprite as int
 */
void CSprite::setMoveAngle(int const angle)
{
    m_Entity.setMoveAngle(angle);
}

/**
 * Returns image width
 * @return image width
 */
int CSprite::getWidth() const
{
    // return image width
    return m_Entity.getWidth();
}

/**
 * Returns image height
 * @return image height
 */
int CSprite::getHeight() const
{
    // return image height
    return m_Entity.getHeight();
}

/**
 * Returns if a collision between the two sprites have occured
 * @param other sprite class instance to test collision with
 * @return if collision occured between the two sprites
 */
bool CSprite::collidesWith(CSprite& other)
{
    return SDL_CollidePixel(m_Entity.m_Image, m_Position.intX(), m_Position.intY(), other.m_Entity.m_Image, other.m_Position.intX(), other.m_Position.intY());
}

/**
 * Returns if a collision between the two sprites have occured with a center origin
 * @param other sprite class instance to test collision with
 * @return if collision occured between the two sprites
 */
bool CSprite::collidesCenterWith(CSprite& other)
{
    return SDL_CollidePixel(m_Entity.m_Image, m_Position.intX() / 2, m_Position.intY() / 2, other.m_Entity.m_Image, other.m_Position.intX() / 2, other.m_Position.intY() / 2);
}
