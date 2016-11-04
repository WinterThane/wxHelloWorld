#include "wx/wx.h"
#include "MainFrame.h"

class HelloWorldApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(HelloWorldApp)

bool HelloWorldApp::OnInit()
{
	MainFrame *frame = new MainFrame(_T("Control example"), wxPoint(60, 70), wxSize(500, 600));

	frame->Show(TRUE);

	SetTopWindow(frame);

	return true;
}