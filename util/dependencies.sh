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

echo ---------- starting dependencies setup ----------
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
    echo removing old catch.
    echo
    rm -rf catch
fi

mkdir catch
cd catch

touch catch.cpp
touch catch.hpp

echo downloading catch.hpp v1.10.0
curl -L https://github.com/philsquared/Catch/releases/download/v1.10.0/catch.hpp >> catch.hpp

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
    echo removing old wxWidgets.
    echo
    rm -rf wxWidgets
fi

echo downloading wxWidgets zip
curl -L https://github.com/wxWidgets/wxWidgets/releases/download/v3.0.3.1/wxWidgets-3.0.3.1.zip -o wxWidgets.zip
mkdir wxWidgets
unzip wxWidgets.zip -d wxWidgets
rm -rf wxWidgets.zip
cd wxWidgets
mkdir build-debug
cd build-debug

echo ---------- building wxWidgets: this could take 20 minutes or more ----------

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

# back to project root dir
cd ../../..

echo ---------- dependencies setup complete ----------