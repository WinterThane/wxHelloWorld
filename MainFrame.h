#pragma once
#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include "wx/wx.h"

enum ID_Lists
{
	OK_BUTTON = 400,
	ADD_BUTTON,

	MNU_ADD,
	MNU_EXIT,

	LIST_ITEMS,
	CHK_BOX
};

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

	void OnOk(wxCommandEvent &event);
	void OnAdd(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event);
	void OnSelected(wxCommandEvent &event);
	void OnSelectionChanged(wxCommandEvent &event);

	void AddEnd(wxCommandEvent &event);
	void AddBeginning(wxCommandEvent &event);

private:
	wxListBox *listBox;
	wxTextCtrl *txtControl;
	wxCheckBox *chkList;

	DECLARE_EVENT_TABLE()
};

#endif
