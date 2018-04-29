/*
 *  Copyright 2018 Oluwatobi Adeyinka
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#include <lib/wxWidgets/include/wx/image.h>
#include <src/config/config.hh>
#include "camera.hh"

Camera::Camera() {
    stream = cv::VideoCapture(0);
}

wxImage Camera::getCurrentFrame() {
    cv::Mat frame;
    stream.read(frame);
    wxImage image(500, 500, frame.data, TRUE);
    return image;
}