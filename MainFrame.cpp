#include "MainFrame.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(OK_BUTTON, MainFrame::OnOk)
	EVT_BUTTON(ADD_BUTTON, MainFrame::AddBeginning)
	EVT_MENU(MNU_ADD, MainFrame::OnAdd)
	EVT_MENU(MNU_EXIT, MainFrame::OnExit)

	EVT_CHECKBOX(CHK_BOX, MainFrame::OnSelectionChanged)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
	wxMenu *file_menu = new wxMenu;

	file_menu->Append(MNU_ADD, _T("&Add"));
	file_menu->Append(MNU_EXIT, _T("E&xit"));

	wxMenuBar *menu_bar = new wxMenuBar;
	menu_bar->Append(file_menu, _T("&File"));

	SetMenuBar(menu_bar);
	
	//custom controls
	wxPanel *mainPanel = new wxPanel(this, -1);

	listBox = new wxListBox(mainPanel, LIST_ITEMS, wxDefaultPosition, wxSize(100, 300));
	listBox->Insert(_T("test"), 0);

	Connect(LIST_ITEMS, wxEVT_COMMAND_LISTBOX_SELECTED, (wxObjectEventFunction) &MainFrame::OnSelected);

	txtControl = new wxTextCtrl(mainPanel, -1, _T("Nothing"));

	chkList = new wxCheckBox(mainPanel, CHK_BOX, _T("Add to the end of the list"));

	wxButton *btnADD = new wxButton(mainPanel, ADD_BUTTON, _T("Add"), wxPoint(0, 0), wxSize(100, 50));
	wxButton *btnOK = new wxButton(mainPanel, OK_BUTTON, _T("Ok"), wxPoint(60, 60), wxSize(100, 50));

	wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

	mainSizer->Add(chkList, 0, wxGROW|wxALL, 5);
	mainSizer->Add(txtControl, 0, wxGROW|wxALL, 5);
	mainSizer->Add(btnADD, 0, wxGROW | wxLEFT, 0);
	mainSizer->Add(listBox, 1, wxGROW, 0);
	mainSizer->Add(btnOK, 0, wxGROW | wxLEFT, 0);
	
	mainPanel->SetAutoLayout(true);
	mainPanel->SetSizer(mainSizer);
}

void MainFrame::OnOk(wxCommandEvent& event)
{
	wxMessageBox(_T("OK button pressed"), _T("Button OK event"));
}

void MainFrame::OnAdd(wxCommandEvent& event)
{
	listBox->Insert(txtControl->GetValue(), listBox->GetCount()); // 0 first place -- listBox->GetCount() last place
}

void MainFrame::OnExit(wxCommandEvent& event)
{
	Close(TRUE);
}

void MainFrame::OnSelected(wxCommandEvent& event)
{
	wxString selected = listBox->GetString(listBox->GetSelection());
	wxMessageBox(selected, _T("selected item"));
}

void MainFrame::AddBeginning(wxCommandEvent& event)
{
	listBox->Insert(txtControl->GetValue(), 0);
}

void MainFrame::AddEnd(wxCommandEvent& event)
{
	listBox->Insert(txtControl->GetValue(), listBox->GetCount());
}


void MainFrame::OnSelectionChanged(wxCommandEvent& event)
{
	if(chkList->IsChecked())
	{
		Connect(ADD_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&MainFrame::AddEnd);
	}
	else
	{
		Connect(ADD_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&MainFrame::AddBeginning);
	}
}
