OBJS = $(wildcard LD41/*.cpp)

OBJ_NAME = build/LD41

INCLUDE_PATHS = -Iexternal\GCC\SDL2\x86_64-w64-mingw32\include\SDL2 -Iexternal\GCC\SDL2_image\x86_64-w64-mingw32\include\SDL2 -Iexternal\GCC\SDL2_mixer\x86_64-w64-mingw32\include\SDL2 -Iexternal\GCC\SDL2_ttf\x86_64-w64-mingw32\include\SDL2

LIBRARY_PATHS = -Lexternal\GCC\SDL2\x86_64-w64-mingw32\lib -Lexternal\GCC\SDL2_image\x86_64-w64-mingw32\lib -Lexternal\GCC\SDL2_mixer\x86_64-w64-mingw32\lib -Lexternal\GCC\SDL2_ttf\x86_64-w64-mingw32\lib

COMPILER_FLAGS = -w
#These flags are left out for debug builds
#-Wl,-subsystem,windows

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
#    This flag is left out for debug builds
#-mwindows

# When adding SDL_Mixer (Or possibly SDL_Image) add flag -SDL_Mixer (Or -SDL_Image for SDL_Image obviously)

STD = -std=c++17

all: $(OBJS)
	g++ $(OBJS) $(STD) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) $(COMPILER_FLAGS) -o $(OBJ_NAME)