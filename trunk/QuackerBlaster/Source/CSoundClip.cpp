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
#include "CSoundClip.h"

/**
 * class constructor
 */
CSoundClip::CSoundClip()
{
    //Initialize SDL_mixer
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

    // initalize variables
    m_Filename = "";

	m_Looping = 0;

	m_Repeat = false;
}

/**
 * class deconstructor
 */
CSoundClip::~CSoundClip()
{
    // if the audio clip is open, close it
    if(m_Clip != NULL)
    {
        Mix_FreeChunk(m_Clip);
    }

}

/**
 * Returns audio clip
 * @return audio clip
 */
Mix_Chunk* CSoundClip::getClip() const
{
    return m_Clip;
}

/**
 * returns filename of audio file
 * @return filename of audio file
 */
std::string CSoundClip::getFilename() const
{
	return m_Filename;
}

/**
 * returns if audio file is looping
 * @return if audio file is looping
 */
bool CSoundClip::getLooping() const
{
	return m_Looping;
}

/**
 * returns how many times audio file should repeat
 * @return how many audio file should repeat
 */
int CSoundClip::getRepeat() const
{
	return m_Repeat;
}

/**
 * sets filename of audio file
 * @param filename filename of audio file
 */
void CSoundClip::setFilename(std::string const filename)
{
	m_Filename = filename;
}

/**
 * sets if audio file should loop
 * @param looping true if audio file should loop, false if it should not
 */
void CSoundClip::setLooping(bool const looping)
{
	m_Looping = looping;
}

/**
 * sets how many times audio file should repeat
 * @param repeat how many times audio file should repeat
 */
void CSoundClip::setRepeat(int const repeat)
{
	m_Repeat = repeat;
}

/**
 * returns if audio clip is loaded
 * @return is audio clip loaded
 */
bool CSoundClip::isLoaded() const
{
     return (m_Clip != NULL);
}

/**
 * loads the audio clip
 * @param filename filename of audio clip to load
 * @return if audio clip loaded successfully
 */
bool CSoundClip::load(std::string const filename)
{
    // set the filename
    m_Filename = filename;

    // load the sound file
    m_Clip = Mix_LoadWAV(filename.c_str());

    // if the audio clip didn't load successfully
    //if(m_Clip == NULL)
    //{
        // return failure
        //return false;
    //}

    // otherwise the audio clip loaded successfully so return true
    return true;
}

/**
 * plays the audio clip
 */
void CSoundClip::play()
{
    // if the clip hasn't loaded
    if(!isLoaded()) return;

    // otherwise play the clip with optional looping
    if(m_Looping)
    {
        Mix_PlayChannel(-1, m_Clip, -1);
    }
    else
    {
        Mix_PlayChannel(-1, m_Clip, m_Repeat);
    }
}

/**
 * stops the audio clip
 */
void CSoundClip::stop()
{
    Mix_HaltMusic();
}
