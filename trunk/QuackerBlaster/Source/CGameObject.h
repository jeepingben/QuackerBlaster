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

#ifndef CGAMEOBJECT_H
#define CGAMEOBJECT_H

/**
 * class for basic object institation
 */
class CGameObject {
    protected:
        bool m_Alive;
        float m_X;
        float m_Y;
        float m_VX;
        float m_VY;
        float m_MoveAngle;
        float m_FaceAngle;

    public:
        CGameObject();
        bool isAlive() const;
        float getX() const;
        float getY() const;
        float getVX() const;
        float getVY() const;
        float getMoveAngle() const;
        float getFaceAngle() const;
        void setAlive(bool const alive);
        void setX(float const x);
        void incrementX(float const inc);
        void decrementX(float const dec);
        void setY(float const y);
        void incrementY(float const inc);
        void decrementY(float const dec);
        void setVX(float const vx);
        void incrementVX(float const inc);
        void decrementVX(float const dec);
        void setVY(float const vy);
        void incrementVY(float const inc);
        void decrementVY(float const dec);
        void setMoveAngle(float const angle);
        void incrementMoveAngle(float const inc);
        void decrementMoveAngle(float const dec);
        void setFaceAngle(float const angle);
        void incrementFaceAngle(float const inc);
        void decrementFaceAngle(float const dec);
  };
#endif
