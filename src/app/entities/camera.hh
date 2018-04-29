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

#ifndef HUMAN_CAMERA_HPP
#define HUMAN_CAMERA_HPP

#include <wx/wx.h>
#include <opencv/cv.hpp>
#include <src/app/core/face_detector.hh>

class Camera {
private:
    cv::VideoCapture stream;
    FaceDetector faceDetector;
public:
    Camera();
    wxImage getCurrentFrame();
    int getCameraFrameWidth() const;
    int getCameraFrameHeight() const ;
};

#endif //HUMAN_CAMERA_HPP
