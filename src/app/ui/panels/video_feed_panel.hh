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

#ifndef HUMAN_VIDEO_FEED_PANEL_HH
#define HUMAN_VIDEO_FEED_PANEL_HH

#include <thread>
#include <wx/wx.h>
#include <src/app/entities/camera.hh>
#include <lib/wxWidgets/include/wx/generic/panelg.h>

class VideoFeedPanel : public wxPanel {
private:
    Camera camera;
    std::thread * videoFeedUpdateThread;
    void render(wxPaintEvent & event);
    DECLARE_EVENT_TABLE();
public:
    explicit VideoFeedPanel(wxWindow * parent);
    void startVideoRefreshFeedThread();
    void stopVideoRefreshFeedThread();
    const Camera &getCamera() const;
};


#endif //HUMAN_VIDEO_FEED_PANEL_HH
