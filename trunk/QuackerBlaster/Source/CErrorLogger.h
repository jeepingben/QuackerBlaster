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

#ifndef CERRORLOGGER_H
#define CERRORLOGGER_H

// include required game libraries
//#include <stdio.h>
#include <string>
#include <fstream>

/**
 * class for logging errors and debug info
 */
class CErrorLogger
{
    private:
        bool m_LoggingAvailiable;
        bool m_LoggingEnabled;
        std::string m_Filename;
        std::ofstream m_OutFile;

    public:
        CErrorLogger();
        ~CErrorLogger();
        void EnableLogging(bool const enable);
        void write(std::string const error);
};
#endif
