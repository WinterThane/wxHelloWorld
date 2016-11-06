#pragma once
#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include "wx/wx.h"

enum ID_LIST
{
	PAINT_WINDOW = 400
};

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

	void OnPaint(wxPaintEvent &event);
	void OnMotion(wxMouseEvent &event);

private:
	wxWindow *paintWindow;
};

#endif
