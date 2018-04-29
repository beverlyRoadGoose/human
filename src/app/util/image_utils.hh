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

#ifndef HUMAN_IMAGE_UTILS_HH
#define HUMAN_IMAGE_UTILS_HH

#include <lib/wxWidgets/include/wx/image.h>
#include <opencv2/core/mat.hpp>

namespace ImageUtils {
    static wxImage matToWxImage(cv::Mat & image);
    static cv::Mat wxImageToMat(wxImage & image);
}

#endif //HUMAN_IMAGE_UTILS_HH
