@echo off

 set buildDir=%~dp0..\build

if not exist %buildDir% mkdir %buildDir%

pushd %buildDir%

:: compiler input
set objDir=.\obj\
set outputExe=LD41
set libs=SDL2.lib SDL2main.lib SDL2_image.lib SDL2_mixer.lib SDL2_ttf.lib
set files=..\LD41\main.cpp
set files=%files% ..\LD41\App.cpp
set files=%files% ..\LD41\BeatmapViewerComponent.cpp
set files=%files% ..\LD41\BitButtonComponent.cpp
set files=%files% ..\LD41\BytePanelComponent.cpp
set files=%files% ..\LD41\Component.cpp
set files=%files% ..\LD41\Graphics.cpp
set files=%files% ..\LD41\GraphicsComponent.cpp
set files=%files% ..\LD41\InputComponent.cpp
set files=%files% ..\LD41\main.cpp
set files=%files% ..\LD41\NeneComponent.cpp
set files=%files% ..\LD41\NumberSpinnerComponent.cpp
set files=%files% ..\LD41\OperatorButtonComponent.cpp
set files=%files% ..\LD41\ProgramEditor.cpp
set files=%files% ..\LD41\ProgramEditorRow.cpp
set files=%files% ..\LD41\Sounds.cpp
set files=%files% ..\LD41\SoundsComponent.cpp
set files=%files% ..\LD41\Tape.cpp
set files=%files% ..\LD41\Turing.cpp
set files=%files% ..\LD41\TuringComponent.cpp

:: compiler flags:
:: /Zi enable debugging information
:: /FC use full path in diagnostics
:: /Fo<path> the path to write object files
:: /Fe<path> the path to write the executable file
set compileFlags=/Zi /FC /Fo%objDir% /Fe%outputExe%

:: linker flags:
:: /SUBSYSTEM specifies exe env - defines entry point symbol
set linkFlags=/link /SUBSYSTEM:CONSOLE

if not exist %objDir% mkdir %objDir%

cl %compileFlags% %files% %libs% %linkFlags%

:: Copy dependencies
xcopy /y ..\external\SDL\lib\x64\SDL2.dll .
xcopy /y ..\external\SDL2_mixer\lib\x64\*.dll .
xcopy /y ..\external\SDL2_ttf\lib\x64\*.dll .
xcopy /y ..\external\SDL2_image\lib\x64\*.dll .
echo D | xcopy /y ..\resources .\resources
popd