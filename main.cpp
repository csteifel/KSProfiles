#include <wx/wx.h>
#include <memory>
#include <iostream>
#include "main.h"
#include "preferences.h"
#include <wx/notebook.h>


mainWindow::mainWindow() : wxFrame(NULL, wxID_ANY, "KSProfiles") {
	Center();
	menuBar = new wxMenuBar();
	SetMenuBar(menuBar);
	menuBar->Show(true);

	wxMenu * fileMenu = new wxMenu;

	menuBar->Append(fileMenu, "File");
	fileMenu->Append(wxID_PREFERENCES);
	fileMenu->Append(wxID_EXIT);

	Bind(wxEVT_COMMAND_MENU_SELECTED, &mainWindow::OpenPreferences, this, wxID_PREFERENCES);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &mainWindow::OnQuit, this, wxID_EXIT);


	tabManager = new wxNotebook(this, wxID_ANY);	
	wxWindow * test = new wxWindow(tabManager, wxID_ANY);
	wxWindow * test2 = new wxWindow(tabManager, wxID_ANY);
	tabManager->AddPage(test, "TEST", true);	
	tabManager->AddPage(test2, "TEST2");
}


void mainWindow::OnQuit(wxCommandEvent&){
	Close(true);
}


void mainWindow::OpenPreferences(wxCommandEvent&){
	preferenceWindow * pWin = new preferenceWindow(this);
	pWin->Show(); //Can be changed to ShowModal if needed
}

bool mainApp::OnInit(){
	topWindow.reset(new mainWindow);
	topWindow->Show(true);
	SetTopWindow(topWindow.get());
	return true;
}

IMPLEMENT_APP(mainApp);
