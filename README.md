# HelloWorld_SDL3

Quickstart for using the SDL3 library on Windows (msys).

https://github.com/libsdl-org/SDL

## Installation of SDL3

At present, there are no official releases for SDL3 on their Github page. The only way is to clone the repo and build it by hand.

First find a location on your machine to clone the SDL repo. Then do the following command.

```
git clone https://github.com/libsdl-org/SDL.git
```
## Building for Windows (msys2)

We will build SDL3 using the msys2 terminal environment. First go to the official msys2 website here: https://www.msys2.org/

Then follow the installation steps on their webpage and install the standard build tools etc that you need using `pacman` (package installer).

Note: we are using the msys terminal program located here: (it may be different on your machine, depending on where you have installed it.)
```
C:\msys64\ucrt64.exe
```
## SDL3 build and install

Launch a new msys `ucrt64` terminal (remember to right-click on the app and 'Run as administrator' this is needed for the cmake install step later).

Go to the directory on your system where you cloned the SDL repo. E.g.

```
odinp@Moon UCRT64 ~
# cd /c/Work/SDL

odinp@Moon UCRT64 /c/Work/SDL
#
```
Then do the following `cmake` build procedure as described here (Linux/Unix):
https://wiki.libsdl.org/SDL3/Installation

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release --parallel
cmake --install . --config Release
```
Make a note of where it installs the built files, e.g.
```
-- Installing: C:/Program Files (x86)/SDL3/*
```
Now you are ready to run the HelloWorld_SDL3 example from this repo.

## HelloWorld_SDL3

Clone the repo if you haven't already done so.

```
git clone https://github.com/odinphillips/HelloWorld_SDL3.git
```

## Copy SDL3 dll file
Copy the installed SDL3 .dll to the local `dlls` directory. E.g.

```
# cd HelloWorld_SDL3
# cp /c/Program\ Files\ \(x86\)/SDL3/bin/SDL3.dll dlls
```

## Build

```
cd HelloWorld_SDL3
mkdir build
cd build
cmake ..
make
# or try any of the following commands
# ninja
# cmake --build .
```


An executable file should have been created in the current directory.

Run it!
```
.\helloworld-sdl3.exe
```
