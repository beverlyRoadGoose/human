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

#include <opencv2/imgproc.hpp>
#include "image_utils.hh"

wxImage ImageUtils::matToWxImage(cv::Mat &image) {
    cv::Mat imageCopy;

    if (image.channels()==1) cvtColor(image, imageCopy, CV_GRAY2RGB);
    else if (image.channels() == 4) cvtColor(image, imageCopy, CV_BGRA2RGB);
    else cvtColor(image, imageCopy, CV_BGR2RGB);

    long imageSize = imageCopy.rows * imageCopy.cols* imageCopy.channels();
    wxImage wx(imageCopy.cols, imageCopy.rows,(unsigned char*)malloc(imageSize), false);

    unsigned char * s= imageCopy.data;
    unsigned char * d= wx.GetData();

    for (long i = 0; i < imageSize; i++) { d[i] = s[i];}
    return wx;
}

cv::Mat ImageUtils::wxImageToMat(wxImage &image) {
    cv::Mat mat(cv::Size(image.GetWidth(), image.GetHeight()), CV_8UC3, image.GetData());
    cvtColor(mat, mat, CV_RGB2BGR);
    return mat;
}
