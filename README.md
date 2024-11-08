# HelloWorld_SDL3

Quickstart for using the SDL3 library on Windows (msys).

https://github.com/libsdl-org/SDL

## Installation of SDL3

At present, there are no official releases for SDL3 on their Github page. The only way is to clone the repo and build it by hand.

First find a location on your machine to clone the SDL repo. Then do the following command.

```
git clone https://github.com/libsdl-org/SDL.git
```
Or to checkout a specific (branch) tag use instead:

```
 git clone --branch preview-3.1.6 --single-branch https://github.com/libsdl-org/SDL.git
```

## Building for Windows (msys2)

We will build SDL3 using the msys2 terminal environment. First go to the official msys2 website here: https://www.msys2.org/

Then follow the installation steps on their webpage and install the standard build tools etc that you need using `pacman` (package installer).

Note: we are using the msys terminal program located here: (it may be different on your machine, depending on where you have installed it.)
```
C:\msys64\ucrt64.exe
```

*Example:* `pacman` tool usage.
```
pacman S <SEARCH>  # To search for all packages with name <SEARCH>.

pacman Ss <package_name>  # To install <package_name>
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

Here are other build configurations for both clang and gcc:

<details>
<summary><b><u>SDL clang build Debug</u></b></summary>

```
cd /c/Work/deps/SDL
mkdir build_clang_debug
cd build_clang_debug
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug -DSDL_STATIC=ON ..
cmake --build . --config Debug --parallel
cmake --install . --config Debug --prefix /c/Libs/SDL3/SDL3_clang_debug
```

</details>

<details>
<summary><b><u>SDL clang build Debug ASAN</u></b></summary>
Note: the use of `-nodefaultlibs` fixes the duplicates symbols for malloc, free, etc. that `ASAN` uses from clashing with the ones from `ucrtbased.dll`. (The other way to fix this is to build in release mode).

```
cd /c/Work/deps/SDL
mkdir build_clang_debug_asan
cd build_clang_debug_asan
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug -DSDL_STATIC=ON -DCMAKE_C_FLAGS="-fsanitize=address" -DCMAKE_C_FLAGS="-nodefaultlibs" -DCMAKE_CXX_FLAGS="-fsanitize=address" -DCMAKE_CXX_FLAGS="-nodefaultlibs" ..
cmake --build . --config Debug --parallel
cmake --install . --config Debug --prefix /c/Libs/SDL3/SDL3_clang_debug_asan
```
</details>

<details>
<summary><b><u>SDL clang build Release</u></b></summary>

```
cd /c/Work/deps/SDL
mkdir build_clang_release
cd build_clang_release
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release -DSDL_STATIC=ON ..
cmake --build . --config Release --parallel
cmake --install . --config Release --prefix /c/Libs/SDL3/SDL3_clang_release
```

</details>

<details>
<summary><b><u>SDL clang build Release ASAN</u></b></summary>

```
cd /c/Work/deps/SDL
mkdir build_clang_release_asan
cd build_clang_release_asan
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release -DSDL_STATIC=ON -DCMAKE_C_FLAGS="-fsanitize=address" -DCMAKE_C_FLAGS="-nodefaultlibs" -DCMAKE_CXX_FLAGS="-fsanitize=address" -DCMAKE_CXX_FLAGS="-nodefaultlibs" ..
cmake --build . --config Release --parallel
cmake --install . --config Release --prefix /c/Libs/SDL3/SDL3_clang_release_asan
```
</details>

<details>
<summary><b><u>SDL clang build RelWithDebInfo</u></b></summary>

```
cd /c/Work/deps/SDL
mkdir build_clang_release_deb
cd build_clang_release_deb
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=RelWithDebInfo -DSDL_STATIC=ON ..
cmake --build . --config RelWithDebInfo --parallel
cmake --install . --config RelWithDebInfo --prefix /c/Libs/SDL3/SDL3_clang_release_deb
```

</details>

<details>
<summary><b><u>SDL clang build RelWithDebInfo ASAN</u></b></summary>

```
cd /c/Work/deps/SDL
mkdir build_clang_release_deb_asan
cd build_clang_release_deb_asan
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=RelWithDebInfo -DSDL_STATIC=ON -DCMAKE_C_FLAGS="-fsanitize=address" -DCMAKE_C_FLAGS="-nodefaultlibs" -DCMAKE_CXX_FLAGS="-fsanitize=address" -DCMAKE_CXX_FLAGS="-nodefaultlibs" ..
cmake --build . --config RelWithDebInfo --parallel
cmake --install . --config RelWithDebInfo --prefix /c/Libs/SDL3/SDL3_clang_release_deb_asan
```
</details>

<details>
<summary><b><u>SDL gcc build Debug</u></b></summary>

```
cd /c/Work/deps/SDL
mkdir build_gcc_debug
cd build_gcc_debug
cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug -DSDL_STATIC=ON ..
cmake --build . --config Debug --parallel
cmake --install . --config Debug --prefix /c/Libs/SDL3/SDL3_gcc_debug
```

</details>

<details>
<summary><b><u>SDL gcc build Release</u></b></summary>

```
cd /c/Work/deps/SDL
mkdir build_gcc_release
cd build_gcc_release
cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release -DSDL_STATIC=ON ..
cmake --build . --config Release --parallel
cmake --install . --config Release --prefix /c/Libs/SDL3/SDL3_gcc_release
```

</details>

<details>
<summary><b><u>SDL gcc build RelWithDebInfo</u></b></summary>

```
cd /c/Work/deps/SDL
mkdir build_gcc_release_deb
cd build_gcc_release_deb
cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=RelWithDebInfo -DSDL_STATIC=ON ..
cmake --build . --config RelWithDebInfo --parallel
cmake --install . --config RelWithDebInfo --prefix /c/Libs/SDL3/SDL3_gcc_release_deb
```

</details>

--

Now you are ready to run the HelloWorld_SDL3 example from this repo.

## HelloWorld_SDL3

Clone the repo if you haven't already done so.

```
git clone https://github.com/odinphillips/HelloWorld_SDL3.git
```

## Copy SDL3 dll file
Copy the installed SDL3 .dll to the local `dlls` directory. E.g.

```
# cp /c/Program\ Files\ \(x86\)/SDL3/bin/SDL3.dll HelloWorld_SDL3/dlls
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
