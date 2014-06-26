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
#include "CErrorLogger.h"

/**
 * class constructor
 */
CErrorLogger::CErrorLogger()
{
    // set log file
    m_Filename = "errorLog.txt";

    // logging is availiable for now
    m_LoggingAvailiable = true;

    // disable logging
    m_LoggingEnabled = false;

    // attempt to open a file stream
    m_OutFile.open(m_Filename, std::iostream::out | std::iostream::app);

    // if the file stream couldn't be opened
    if(!m_OutFile.is_open())
    {
        // disable logging completely
        m_LoggingAvailiable = false;
        m_LoggingEnabled = false;
    }
}

/**
 * class deconstructor
 */
CErrorLogger::~CErrorLogger()
{
    // if the file stream is open
    if(m_OutFile.is_open())
    {
        // close it
        m_OutFile.close();
    }

}

/**
 * enabled error logging
 * @param enable true to enable logging or false to disable
 */
void CErrorLogger::EnableLogging(bool const enable)
{
    // if logging is availiable
    if(m_LoggingAvailiable)
    {
        // enable/disable logging
        m_LoggingEnabled = enable;
    }
}

/**
 * Writes the message to the log file
 * @param error error  message to write to log file
 */
void CErrorLogger::write(std::string const error)
{
    // if error logging is enabled
    if(m_LoggingEnabled)
    {
        m_OutFile << error << std::endl;
    }
}
