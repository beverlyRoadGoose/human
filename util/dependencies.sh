#!/usr/bin/env bash

#
#  Copyright 2018 Oluwatobi Adeyinka
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#

echo "---------- starting dependencies setup (this could take a while) ----------"
echo

# cmake, boost
if [[ "$(uname)" == "Darwin" ]]; then # osx
    brew install cmake
    brew install boost
elif [[ "$(expr substr $(uname -s) 1 5)" == "Linux" ]]; then # linux
    sudo apt-get install cmake
    sudo apt-get install libcurl4-gnutls-dev
    sudo apt-get install libboost-all-dev
fi


# create a libraries directory if it doesnt exist
if [ ! -d "lib" ]; then
    echo libraries directory doesn\'t exist, creating it.
    mkdir lib
    echo create libraries directory \(lib\)
    echo
fi

# step into libraries directory
cd lib


#############################################
# Catch
#############################################

echo ---------- setting up Catch ----------

if [ -d "catch" ]; then
    echo catch lib dir already exists, skipping.
    echo
else
    mkdir catch
    cd catch

    touch catch.cpp
    touch catch.hpp

    echo downloading catch.hpp v1.10.0
    curl -L https://github.com/philsquared/Catch/releases/download/v1.10.0/catch.hpp >> catch.hpp
fi

# back to lib dir
cd ..

echo ---------- Catch successfully setup ----------
echo

#################################################
# wxWidgets
#################################################

echo ---------- setting up wxWidgets ----------
echo

if [ -d "wxWidgets" ]; then
    echo wxWidgets lib dir already exists, skipping build.
    echo
else
    echo downloading wxWidgets 3.1.2
    curl -L https://github.com/wxWidgets/wxWidgets/releases/download/v3.1.2/wxWidgets-3.1.2.zip -o wxWidgets.zip
    mkdir wxWidgets
    unzip wxWidgets.zip -d wxWidgets
    rm -rf wxWidgets.zip
    cd wxWidgets
    mkdir build-debug
    cd build-debug



    if [[ "$(uname)" == "Darwin" ]]; then # osx
        ../configure CPPFLAGS=-D__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES=1 --enable-debug --enable-monolithic --with-macosx-version-min=10.9
    elif [[ "$(expr substr $(uname -s) 1 5)" == "Linux" ]]; then # linux
        ../configure --enable-debug --enable-monolithic
    fi

    make

    echo ---------- finished building wxWidgets ----------
    echo

    echo ---------- wxWidgets setup succesfully ----------
    echo
fi

# back to lib root dir
cd ../..

#################################################
# opencv-4.0
#################################################

echo ---------- setting up OpenCV ----------
echo

if [ -d "opencv-4.0.1" ]; then
    echo OpenCV lib dir already exists, skipping build.
    echo
else
    echo downloading OpenCV 4.0.1
    https://github.com/opencv/opencv/archive/4.0.1.zip -o OpenCV.zip
    mkdir OpenCV
    unzip Open.zip -d OpenCV
    rm -rf OpenCV.zip
    cd OpenCV
    mkdir build
    cd build
    cmake -G "Unix Makefiles" ..
    make -j8
    make install

    echo ---------- finished building OpenCV ----------
    echo

    echo ---------- OpenCV setup succesfully ----------
    echo
fi

# back to project root dir
cd ../../..

echo ---------- dependencies setup complete ----------
