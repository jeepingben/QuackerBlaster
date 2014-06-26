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

#ifndef CSOUNDCLIP_H
#define CSOUNDCLIP_H

// include required game libraries
#include <SDL/SDL_mixer.h>
#include <string>

/**
 * class for managing sound clips
 */
class CSoundClip
{
    private:
        Mix_Chunk *m_Clip;
        std::string m_Filename;
		bool m_Looping;
		int m_Repeat;

    public:
		CSoundClip();
		~CSoundClip();

        Mix_Chunk* getClip() const;
		std::string getFilename() const;
		bool getLooping() const;
		int getRepeat() const;
		void setFilename(std::string const filename);
		void setLooping(bool const looping);
		void setRepeat(int const repeat);

        bool isLoaded() const;
        bool load(std::string const filename);
        void play();
        void stop();
};
#endif
