#include <wx/wx.h>
#include "preferences.h"



preferenceWindow::preferenceWindow(wxWindow * parent) : wxDialog(parent, wxID_ANY, "KSProfiles Preferences", wxDefaultPosition, wxDefaultSize, wxCAPTION | wxRESIZE_BORDER) {
	layout = new wxFlexGridSizer(2, 5, 5); //2 cols with 5 pixels padding between cells
	wxButton * okButton = new wxButton(this, wxID_OK);
	wxButton * cancelButton = new wxButton(this, wxID_CANCEL);


	wxStaticText * installLoc = new wxStaticText(this, wxID_ANY, "Install location");
	launchFileButton = new wxButton(this, wxID_OPEN);

	Bind(wxEVT_BUTTON, &preferenceWindow::onOk, this, wxID_OK);
	Bind(wxEVT_BUTTON, &preferenceWindow::onOpen, this, wxID_OPEN);


	layout->Add(installLoc, 1, wxEXPAND);
	layout->Add(launchFileButton, 1, wxEXPAND);
	layout->Add(okButton, 1, wxEXPAND);
	layout->Add(cancelButton, 1, wxEXPAND);
	layout->AddGrowableCol(1,1);
	SetSizer(layout);
}


void preferenceWindow::onOk(wxCommandEvent&){
	Close(true);
}

void preferenceWindow::onOpen(wxCommandEvent&){
	wxDirDialog * file = new wxDirDialog(this, "Select.....");
	if(file->ShowModal() != wxID_OK){
		return;
	}

	const wxString installPath = file->GetPath();
	launchFileButton->SetLabel(installPath);
}