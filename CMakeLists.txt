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

cmake_minimum_required(VERSION 3.2)
project(Human)

# cmake & compile configs
include(${PROJECT_SOURCE_DIR}/cmake/configs.cmake)

# include directories
include(${PROJECT_SOURCE_DIR}/cmake/includes.cmake)

# app libraries
include(${PROJECT_SOURCE_DIR}/cmake/libraries.cmake)

# create app executable
add_executable(Human src/main.hpp src/main.cpp)

# Testing
include(${PROJECT_SOURCE_DIR}/cmake/testing.cmake)
