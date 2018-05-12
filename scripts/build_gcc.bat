@echo off

set buildDir=%~dp0..\build

if not exist %buildDir% mkdir %buildDir%

make

:: Copy dependencies
xcopy /y external\GCC\SDL2\x86_64-w64-mingw32\bin\SDL2.dll build\
xcopy /y external\GCC\SDL2_mixer\x86_64-w64-mingw32\bin\*.dll build\
xcopy /y external\GCC\SDL2_ttf\x86_64-w64-mingw32\bin\*.dll build\
xcopy /y external\GCC\SDL2_image\x86_64-w64-mingw32\bin\*.dll build\
echo D | xcopy /y resources build\resources
popd