project(QuackerBlaster)
cmake_minimum_required(VERSION 2.8)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(SDL_mixer REQUIRED)

include_directories(SYSTEM ${SDL_INCLUDE_DIR})

# Add additional flags to gcc and clang
if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_definitions("-std=c++11 -pedantic -Wall -Wextra")
endif ()

add_executable(${PROJECT_NAME}
CAnimatedSprite.cpp
CErrorLogger.cpp
CGameEngine.cpp
CGameObject.cpp
CGunTestState.cpp
CImageEntity.cpp
CIntroState.cpp
CMouseListener.cpp
CPlayState.cpp
CPoint2D.cpp
CRandom.cpp
CSoundClip.cpp
CSprite.cpp
CText.cpp
CTextCounter.cpp
CTimer.cpp
QuackerBlaster.cpp
SDL_collide.cpp
CAnimatedSprite.h
CErrorLogger.h
CGameEngine.h
CGameObject.h
CGameState.h
CGunTestState.h
CImageEntity.h
CIntroState.h
CMouseListener.h
CPlayState.h
CPoint2D.h
CRandom.h
CSoundClip.h
CSprite.h
CText.h
CTextCounter.h
CTimer.h
QuackerBlaster.h
SDL_collide.h
)

target_link_libraries(${PROJECT_NAME}
${SDL_LIBRARY}
${SDLIMAGE_LIBRARY}
${SDLTTF_LIBRARY}
${SDLMIXER_LIBRARY}
)
