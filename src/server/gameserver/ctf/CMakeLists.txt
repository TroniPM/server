ADD_DEFINITIONS(-D__LINUX__ -D__GAME_SERVER__)
INCLUDE_DIRECTORIES(.. ../war)
SET(LIBCTF_SRC 
	FlagManager.cpp
	FlagWar.cpp
	NewbieFlagWar.cpp
)
ADD_LIBRARY(CTF STATIC ${LIBCTF_SRC})