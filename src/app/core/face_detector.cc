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

#include <iostream>
#include "face_detector.hh"

FaceDetector::FaceDetector() {
    loadFaceClassifier();
}

void FaceDetector::loadFaceClassifier() {
    try {
        bool loaded = faceClassifier.load(faceCascadeFileLocale);
        if (!loaded) std::cout << "Error loading face cascade file.";
    } catch (std::exception & e) { std::cout << e.what(); }
}

void FaceDetector::detectAndMarkFaces(cv::Mat & frame) {
    std::vector<cv::Rect> faces;
    cv::Mat grayedFrame;

    cvtColor(frame, grayedFrame, CV_BGR2GRAY);
    cv::equalizeHist(grayedFrame, grayedFrame);

    faceClassifier.detectMultiScale(grayedFrame, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));

    for(size_t i = 0; i < faces.size(); i++) {
        cv::Point center( faces[i].x + faces[i].width * 0.5, faces[i].y + faces[i].height * 0.5);
        ellipse( frame, center, cv::Size(faces[i].width * 0.5, faces[i].height * 0.5), 0, 0, 360, cv::Scalar(255, 255, 255), 4, 8, 0);
    }
}

FaceDetector::~FaceDetector() = default;
