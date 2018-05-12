@echo off

set scriptsDir=%~dp0

cd /d %scriptsDir%..

:: uncomment the line below line to debug the vcvars
:: set VSCMD_DEBUG=1
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"

set path=%scriptsDir%;%path%

:: Add dependencies to our include and lib paths (used by cl.exe)
set INCLUDE=%scriptsDir%..\external\MSVC\sdl2\include;%INCLUDE%
set INCLUDE=..\external\MSVC\sdl2_mixer\include;%INCLUDE%
set INCLUDE=..\external\MSVC\sdl2_image\include;%INCLUDE%
set INCLUDE=..\external\MSVC\sdl2_ttf\include;%INCLUDE%

set LIB=%scriptsDir%..\external\MSVC\sdl2\lib\x64;%LIB%
set LIB=..\external\MSVC\sdl2_mixer\lib\x64;%LIB%
set LIB=..\external\MSVC\sdl2_image\lib\x64;%LIB%
set LIB=..\external\MSVC\sdl2_ttf\lib\x64;%LIB%
