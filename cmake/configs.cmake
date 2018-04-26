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

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/modules)

if (APPLE)
    set(CMAKE_CXX_FLAGS "-I${PROJECT_SOURCE_DIR}/lib/wxWidgets/build-debug/lib/wx/include/osx_cocoa-unicode-3.0 -I/${PROJECT_SOURCE_DIR}/lib/wxWidgets/include -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXMAC__ -D__WXOSX__ -D__WXOSX_COCOA__  -stdlib=libc++ -std=c++11")
    set(CMAKE_SHARED_LINKER_FLAGS "-L${PROJECT_SOURCE_DIR}/lib/wxWidgets/build-debug/lib -framework IOKit -framework Carbon -framework Cocoa -framework AudioToolbox -framework System -framework OpenGL -lwx_osx_cocoau-3.0")
elseif (UNIX AND NOT APPLE)
    set(CMAKE_CXX_FLAGS "-I/${PROJECT_SOURCE_DIR}/lib/wxWidgets/build-debug/lib/wx/include/gtk3-unicode-3.0 -I/${PROJECT_SOURCE_DIR}/lib/wxWidgets/include -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread")
    set(CMAKE_SHARED_LINKER_FLAGS "-L/${PROJECT_SOURCE_DIR}/lib/wxWidgets/build-debug/lib -pthread   -Wl,-rpath,/${PROJECT_SOURCE_DIR}/lib/wxWidgets/build-debug/lib -lwx_gtk3u-3.0")
endif ()
