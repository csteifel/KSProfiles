#include <wx/wx.h>
#include <memory>
#include <iostream>
#include "main.h"
#include <fstream>
#include "preferences.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <errno.h>
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

	Bind(wxEVT_COMMAND_MENU_SELECTED, &mainWindow::openPreferences, this, wxID_PREFERENCES);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &mainWindow::onQuit, this, wxID_EXIT);


	tabManager = new wxNotebook(this, wxID_ANY);	
	wxWindow * test = new wxWindow(tabManager, wxID_ANY);
	wxWindow * test2 = new wxWindow(tabManager, wxID_ANY);
	tabManager->AddPage(test, "TEST", true);	
	tabManager->AddPage(test2, "TEST2");
}


void mainWindow::onQuit(wxCommandEvent&){
	Close(true);
}


void mainWindow::openPreferences(wxCommandEvent&){
	preferenceWindow * pWin = new preferenceWindow(this);
	pWin->Show(); //Can be changed to ShowModal if needed
}

bool mainApp::OnInit(){

	std::fstream configFile;


	struct stat fileStat;
	if(stat("config", &fileStat) == -1 && errno == ENOENT){
		configFile.open("config", std::ios_base::out);
		std::cout << errno << std::endl;
		assert(configFile.is_open());
		//Create a default configuration
		rapidjson::Document root;
		rapidjson::Value gameInstallDir;
		rapidjson::Value modDownloadDir;

		root.SetObject();

		root.AddMember("gameInstallDirectory", "", root.GetAllocator()); 
		root.AddMember("modDownloadDirectory", "", root.GetAllocator());

		rapidjson::StringBuffer buf;
		rapidjson::Writer<rapidjson::StringBuffer> writer(buf);
		root.Accept(writer);


		configFile.write(buf.GetString(), buf.GetSize());
		configFile.close();
	}
	configFile.open("config", std::ios_base::in);

	//Read configuration

	configFile.close();

	topWindow.reset(new mainWindow);
	topWindow->Show(true);
	SetTopWindow(topWindow.get());
	return true;
}

IMPLEMENT_APP(mainApp);
