#include <wx/wx.h>
#include <memory>
#include <iostream>
#include "main.h"
#include <wx/notebook.h>

mainWindow::mainWindow() : wxFrame(NULL, wxID_ANY, "KSProfiles") {
	Center();
	menuBar = new wxMenuBar();
	SetMenuBar(menuBar);
	menuBar->Show(true);

	wxMenu * fileMenu = new wxMenu;

	menuBar->Append(fileMenu, "File");
	fileMenu->Append(wxID_EXIT);

	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(mainWindow::OnQuit));


	tabManager = new wxNotebook(this, wxID_ANY);	
	wxWindow * test = new wxWindow(tabManager, wxID_ANY);
	wxWindow * test2 = new wxWindow(tabManager, wxID_ANY);
	tabManager->AddPage(test, "TEST", true);	
	tabManager->AddPage(test2, "TEST2");
}


void mainWindow::OnQuit(wxCommandEvent&){
	Close(true);
}


bool mainApp::OnInit(){
	topWindow.reset(new mainWindow);
	topWindow->Show(true);
	SetTopWindow(topWindow.get());
	return true;
}

IMPLEMENT_APP(mainApp);
