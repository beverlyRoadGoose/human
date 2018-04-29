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

#include <thread>
#include "mainframe.hh"
#include <src/config/config.hh>

MainFrame::MainFrame(const wxString & title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(HumanConfig::FRAME_WIDTH, HumanConfig::FRAME_HEIGHT)) {

    menuBar = new wxMenuBar;
    SetMenuBar(menuBar);
    videoFeedPanel = new VideoFeedPanel(this);
    Centre();
}

VideoFeedPanel *MainFrame::getVideoFeedPanel() const {
    return videoFeedPanel;
}

void MainFrame::quit(wxCommandEvent & event) {
    Close(true);
}

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(wxID_EXIT,  MainFrame::quit)
END_EVENT_TABLE()

