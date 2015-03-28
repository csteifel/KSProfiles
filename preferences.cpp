#include <wx/wx.h>
#include "preferences.h"

preferenceWindow::preferenceWindow(wxWindow * parent) : wxDialog(parent, wxID_ANY, "KSProfiles Preferences", wxDefaultPosition, wxDefaultSize, wxCAPTION | wxRESIZE_BORDER) {
	layout = new wxFlexGridSizer(2, 5, 5); //2 cols with 5 pixels padding between cells
	wxButton * okButton = new wxButton(this, wxID_OK);
	wxButton * cancelButton = new wxButton(this, wxID_CANCEL);

	layout->Add(okButton, 1, wxEXPAND);
	layout->Add(cancelButton, 1, wxEXPAND);
	layout->AddGrowableRow(0,1);
	layout->AddGrowableCol(1,1);
	okButton->Show();
	cancelButton->Show();
	SetSizer(layout);
}
