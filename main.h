#pragma once
#ifndef MAIN_H
#define MAIN_H

class wxCommandEvent;
class wxMenuBar;
class wxWindow;
class wxFrame;
class wxNotebook;

class windowDeleter {
	public:
		void operator()(wxWindow* window){window->Destroy();}
};

class mainApp : public wxApp {
	public:
		bool OnInit();
	private:
		std::unique_ptr<wxFrame, windowDeleter> topWindow;
};

class mainWindow : public wxFrame {
	public:
		mainWindow();	
		void onQuit(wxCommandEvent&);
		void openPreferences(wxCommandEvent&);
	private:
		wxMenuBar * menuBar;
		wxNotebook * tabManager;
};

#endif
