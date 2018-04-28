//
// Created by Oluwatobi Adeyinka on 29.04.18.
//

#ifndef HUMAN_CAMERA_HPP
#define HUMAN_CAMERA_HPP

class Camera {
private:
    cv::VideoCapture stream;
public:
    Camera();
    void startStreaming();
};

#endif //HUMAN_CAMERA_HPP
