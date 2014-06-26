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

#ifndef CSPRITE_H
#define CSPRITE_H

// include required libraries
#include "CImageEntity.h"
#include "CPoint2D.h"

/**
 * class for managing sprites
 */
class CSprite {
    private:
        CImageEntity m_Entity;

    protected:
        CPoint2D m_Position;
        CPoint2D m_Velocity;
        double m_rotationRate;
        int m_CurrentState;

    public:
        CSprite();
        bool load(std::string const filename);
        void draw(SDL_Surface* const screen);
        void update();
        double rotationRate() const;
        void setRotationRate(double const rate);
        void updateRotation();
        int state() const;
        void setState(int const state);
        double doubleFaceAngle() const;
        void setFaceAngle(double const angle);
        float floatFaceAngle() const;
        void setFaceAngle(float const angle);
        int intFaceAngle() const;
        void setFaceAngle(int const angle);
        double doubleMoveAngle() const;
        void setMoveAngle(double const angle);
        float floatMoveAngle() const;
        void setMoveAngle(float const angle);
        int intMoveAngle() const;
        void setMoveAngle(int const angle);
        SDL_Rect getBounds();
        CPoint2D &position();
        CPoint2D &velocity();
        CPoint2D center();
        bool alive() const;
        void setAlive(bool const alive);
        int getWidth() const;
        int getHeight() const;
        bool collidesWith(CSprite &other);
        bool collidesCenterWith(CSprite &other);
  };
#endif
