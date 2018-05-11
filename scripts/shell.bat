@echo off
 
set scriptsDir=%~dp0
 
cd /d %scriptsDir%..
 
:: uncomment the line below line to debug the vcvars
:: set VSCMD_DEBUG=1
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"

set path=%scriptsDir%;%path%
 
:: Add dependencies to our include and lib paths (used by cl.exe)
set INCLUDE=%scriptsDir%..\external\sdl\include;%INCLUDE%
set INCLUDE=..\external\sdl2_mixer\include;%INCLUDE%
set INCLUDE=..\external\sdl2_image\include;%INCLUDE%
set INCLUDE=..\external\sdl2_ttf\include;%INCLUDE%

set LIB=%scriptsDir%..\external\sdl\lib\x64;%LIB%
set LIB=..\external\sdl2_mixer\lib\x64;%LIB%
set LIB=..\external\sdl2_image\lib\x64;%LIB%
set LIB=..\external\sdl2_ttf\lib\x64;%LIB%
