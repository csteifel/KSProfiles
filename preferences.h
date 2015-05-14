#pragma once
#ifndef PREFERENCES_H
#define PREFERENCES_H 

class wxWindow;
class wxDialog;
class wxButton;
class wxFlexGridSizer;
class wxCommandEvent;

class preferenceWindow : public wxDialog {
	public:
		preferenceWindow(wxWindow*);
	private:
		wxFlexGridSizer * layout;
		void onOk(wxCommandEvent&);
		void onOpen(wxCommandEvent&);
		wxButton * launchFileButton;
};

#endif