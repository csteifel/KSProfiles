#include <wx/wx.h>
#include <memory>
#include <iostream>


class windowDeleter {
	public:
		void operator()(wxFrame* window){window->Destroy();}
};

class mainApp : public wxApp {
	public:
		mainApp();
		bool OnInit();
	private:
		std::unique_ptr<wxFrame, windowDeleter> mainWindow;
};

IMPLEMENT_APP(mainApp);

mainApp::mainApp(){
}

bool mainApp::OnInit(){
	mainWindow.reset(new wxFrame(NULL, wxID_ANY, "Test"));
	mainWindow->Show(true);
	SetTopWindow(mainWindow.get());
	return true;
}