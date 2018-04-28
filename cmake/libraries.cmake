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

find_package(wxWidgets COMPONENTS adv core base REQUIRED)
include(${wxWidgets_USE_FILE})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_library(human-entities src/app/entities/camera.cc src/app/entities/camera.hh)
target_link_libraries(human-entities ${OpenCV_LIBS})

add_library(human-ui src/app/ui/mainframe.cc src/app/ui/mainframe.hh)
target_link_libraries(human-ui ${wxWidgets_LIBRARIES})