#!/usr/bin/env bash

#../configure \
#    --prefix=/home/mi/workspace/code/PhoenixSimulator/Simulator/3rdParty/SDL_ttf \
#    SDL_LIBS=/home/mi/workspace/code/PhoenixSimulator/Simulator/3rdParty/SDL/lib/libSDL2.so \
#    SDL_FLAGS=-I/home/mi/workspace/code/PhoenixSimulator/Simulator/3rdParty/SDL/include/SDL2/ \
#    SDL2_CONFIG=/home/mi/workspace/code/PhoenixSimulator/Simulator/3rdParty/SDL/bin/sdl2-config

OS=""
Project_PATH=""

#if [[ `uname` == 'Darwin' ]]; then
#    echo "Mac OS"
#    OS="MAC"
#fi
#
#
#if [[ `uname` == 'Linux' ]]; then
#    echo "Linux"
#    OS="Linux"
#fi

if [[ "$(uname)" == "Darwin" ]]; then
# Mac OS X 操作系统
    echo "Mac"
    OS="macos"
elif [[ "$(expr substr $(uname -s) 1 5)" == "Linux" ]]; then
# GNU/Linux操作系统
    echo "Linux"
    OS="linux"
elif [[ "$(expr substr $(uname -s) 1 10)" == "MINGW32_NT" ]]; then
# Windows NT操作系统
    echo "Windows"
    OS="Windows"
#read -r -p "any Key to Continue"
elif [[ "$(expr substr $(uname -s) 1 6)" == "CYGWIN" ]]; then
    echo "CYGWIN"
    OS="CYGWIN"
else
    echo $(uname)
fi
read -r -p "any Key to Continue"

if [[ $OS == "macos" || $OS == "linux" ]]; then
    echo "prebuild begin"
    SHELL_FOLDER=$(cd "$(dirname "$0")" || exit;pwd)
    echo "$SHELL_FOLDER"
    cd ..
    Project_PATH=$(pwd)
#    echo $Project_PATH
    git submodule init
    git submodule sync
    git submodule update ThirdParty/SDL
    git submodule update ThirdParty/SDL_image
    git submodule update ThirdParty/SDL_mixer
    git submodule update ThirdParty/SDL_net
    git submodule update ThirdParty/SDL_rtf
    git submodule update ThirdParty/SDL_ttf
    git submodule update Resource/font/FiraCode

#${Project_PATH}/ThirdParty/SDL
#${Project_PATH}/ThirdParty/SDL_image
#${Project_PATH}/ThirdParty/SDL_mixer
#${Project_PATH}/ThirdParty/SDL_net
#${Project_PATH}/ThirdParty/SDL_rtf
#${Project_PATH}/ThirdParty/SDL_ttf
#${Project_PATH}/Resource/font/FiraCode
    mkdir ${Project_PATH}/Simulator/3rdParty/SDL/macos/
    mkdir ${Project_PATH}/Simulator/3rdParty/SDL/linux/

    export Phoenix_SDL_PREFINX=${Project_PATH}/Simulator/3rdParty/SDL/$OS
    cd "${Project_PATH}"/ThirdParty/SDL || exit 1
    mkdir build
    cd build || exit 1
    ../configure --prefix=$Phoenix_SDL_PREFINX --enable-shared=yes --enable-static=no
    make -j8
    make install

    cd ${Project_PATH} || exit 1

fi