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

#ifndef CPOINT2D_H
#define CPOINT2D_H

/**
 * class for managing points on the screen
 */
class CPoint2D {
    protected:
        double m_X;
        double m_Y;

    public:
        CPoint2D();
        CPoint2D(double const x, double const y);
        CPoint2D(float const x, float const y);
        CPoint2D(int const x, int const y);
        double doubleX() const;
        float floatX() const;
        int intX() const;
        double doubleY() const;
        float floatY() const;
        int intY() const;
        void setX(double const x);
        void setX(float const x);
        void setX(int const x);
        void setY(double const y);
        void setY(float const y);
        void setY(int const y);
  };
#endif
