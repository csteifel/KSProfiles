#pragma once
#ifndef PREFERENCES_H
#define PREFERENCES_H 

class wxWindow;
class wxDialog;
class wxButton;
class wxFlexGridSizer;

class preferenceWindow : public wxDialog {
	public:
		preferenceWindow(wxWindow*);
	private:
		wxFlexGridSizer * layout;
};

#endif