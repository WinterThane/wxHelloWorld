#include "MainFrame.h"
#include "wx/image.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
	paintWindow = new wxWindow(this, PAINT_WINDOW);

	paintWindow->Connect(PAINT_WINDOW, -1, wxEVT_PAINT, (wxObjectEventFunction) &MainFrame::OnPaint, NULL, this);
	paintWindow->Connect(PAINT_WINDOW, -1, wxEVT_MOTION, (wxObjectEventFunction) &MainFrame::OnMotion, NULL, this);
}

void MainFrame::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(paintWindow);

	dc.DrawText(_T("neki"), 60, 70);
}

void MainFrame::OnMotion(wxMouseEvent& event)
{
	wxPoint mousePos = event.GetPosition();
	wxClientDC dest(paintWindow);

	wxImage myImage("test.bmp");
	wxBitmap myBitmap(myImage);

	//wxBitmap myResource = wxBITMAP(Item);

	dest.DrawBitmap(myBitmap, mousePos, false);
	//dest.SetPen(wxColor(255, 255, 255));
	//dest.SetBrush(wxColour(34, 145, 23));
	//dest.DrawCircle(mousePos, 10);
}
