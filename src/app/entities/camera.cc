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

#include "camera.hh"
#include <src/config/config.hh>
#include <src/app/util/image_utils.hh>
#include <lib/wxWidgets/include/wx/image.h>

Camera::Camera() {
    stream = cv::VideoCapture(0);
    faceDetector = FaceDetector();
}

wxImage Camera::getCurrentFrame() {
    cv::Mat frame;
    cv::Mat mirroredFrame;

    stream.read(frame);

    mirroredFrame = cv::Mat(frame.rows, frame.cols, CV_8UC3);
    cv::flip(frame, mirroredFrame, 1);
    faceDetector.detectAndMarkFaces(mirroredFrame);

    return ImageUtils::matToWxImage(mirroredFrame);
}

int Camera::getCameraFrameWidth() const {
    return stream.get(CV_CAP_PROP_FRAME_WIDTH);
}

int Camera::getCameraFrameHeight() const {
    return stream.get(CV_CAP_PROP_FRAME_HEIGHT);
}
