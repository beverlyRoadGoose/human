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

#include "video_feed_panel.hh"

VideoFeedPanel::VideoFeedPanel(wxWindow * parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(800, 800)) {
    camera = Camera();
    startVideoRefreshFeedThread();
}

void VideoFeedPanel::render(wxPaintEvent &event) {
    wxUnusedVar(event);
    wxPaintDC dc(this);
    wxBitmap bmp(camera.getCurrentFrame());
    dc.DrawBitmap(bmp, 0, 0, true);
}

void VideoFeedPanel::startVideoRefreshFeedThread() {
    videoFeedUpdateThread = new std::thread([this]{
        while (true) {
            Refresh();
            Update();
        }
    });
    videoFeedUpdateThread->detach();
}

void VideoFeedPanel::stopVideoRefreshFeedThread() {
    videoFeedUpdateThread->join();
    delete videoFeedUpdateThread;
}

BEGIN_EVENT_TABLE(VideoFeedPanel, wxPanel)
    EVT_PAINT(VideoFeedPanel::render)
END_EVENT_TABLE()
