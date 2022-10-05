#include "main-frame.h"

MainFrame::MainFrame(const wxString &title)
	: wxFrame(nullptr, 33, title) {
	CreateStatusBar();

	panelTop = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(-1,100));
	panelMenu = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(200,-1));
	panelList = new wxScrolledWindow(this);
	panelTest = new wxScrolledWindow(this);
	panelTop->Bind(wxEVT_PAINT, &MainFrame::SetTopPaint, this);
	panelMenu->Bind(wxEVT_PAINT, &MainFrame::SetMenuPaint, this);
	panelList->Bind(wxEVT_PAINT, &MainFrame::SetListPaint, this);
	panelTest->Bind(wxEVT_PAINT, &MainFrame::SetListPaint, this);
	//panelTop->SetBackgroundColour(wxColor(10, 10, 10));
	//panelMenu->SetBackgroundColour(wxColor(20, 20, 10));
	//panelList->SetBackgroundColour(wxColor(30, 30, 10));
	
	wxButton *btn1 = new wxButton(panelTop, wxID_ANY, "panel Top", wxPoint(100, 20), wxSize(100,50));
	wxButton *btn2 = new wxButton(panelMenu, wxID_ANY, "Game List", wxPoint(20, 50), wxSize(100, 50));
	wxButton *btn3 = new wxButton(panelMenu, wxID_ANY, "6DOF Test", wxPoint(20, 120), wxSize(100, 50));
	btn3->Bind(wxEVT_BUTTON, &MainFrame::ShowTest, this);
	wxButton *btn4 = new wxButton(panelList, wxID_ANY, "panel List", wxPoint(50,50), wxSize(100,50));
	wxButton *btn5 = new wxButton(panelTest, wxID_ANY, "panel Test", wxPoint(50,50), wxSize(200,200));

	sizerMain = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *sizer1 = new wxBoxSizer(wxHORIZONTAL);
	sizer1->Add(panelMenu, 0, wxEXPAND | wxALL);
	sizer1->Add(panelList, 1, wxEXPAND | wxALL);
	
	sizerList = new wxBoxSizer(wxVERTICAL);
	sizerList->Add(panelList, 1, wxEXPAND | wxALL);
	sizer1->Add(sizerList, 1, wxEXPAND | wxALL);
	sizerTest = new wxBoxSizer(wxVERTICAL);
	sizerTest->Add(panelTest, 1, wxEXPAND | wxALL);
	sizer1->Add(sizerTest, 1, wxEXPAND | wxALL);

	sizerMain->Add(panelTop, 0, wxEXPAND | wxALL);
	sizerMain->Add(sizer1, 1, wxEXPAND | wxALL);

	
	//panelTest->Hide();
	sizerTest->ShowItems(false);


	this->SetSizer(sizerMain);

}

void MainFrame::ShowTest(const wxCommandEvent &evt) {
	//panelList->Hide();
	//panelTest->Show();

	sizerList->ShowItems(false);
	sizerTest->ShowItems(true);

	sizerMain->Layout();
}



void MainFrame::SetTopPaint(const wxEvent &evt) {
	wxLogStatus("execute");
	wxPaintDC dc(panelTop);
	wxRect clientRect = GetClientRect();
	wxRect gradientRect = clientRect;
	dc.GradientFillLinear(gradientRect, wxColour(30, 30, 35), wxColour(28, 28, 33), wxSOUTH);
	gradientRect.Offset(0, gradientRect.GetHeight());
	dc.GradientFillLinear(gradientRect, wxColour(26, 26, 31), wxColour(24, 24, 29), wxSOUTH);

	dc.SetPen(wxColor(255, 0, 0));
	dc.SetBrush(*wxTRANSPARENT_BRUSH);
	dc.DrawRectangle(0, 0, clientRect.GetWidth(), clientRect.GetHeight());
	dc.SetFont(GetFont());
	dc.SetTextForeground(GetForegroundColour());
}

void MainFrame::SetMenuPaint(const wxEvent &evt) {
	wxLogStatus("execute");
	wxPaintDC dc(panelMenu);
	wxRect clientRect = GetClientRect();
	wxRect gradientRect = clientRect;
	dc.GradientFillLinear(gradientRect, wxColour(50, 50, 55), wxColour(48, 48, 53), wxSOUTH);
	gradientRect.Offset(0, gradientRect.GetHeight());
	dc.GradientFillLinear(gradientRect, wxColour(46, 46, 51), wxColour(44, 44, 49), wxSOUTH);

	dc.SetPen(wxColor(255, 0, 0));
	dc.SetBrush(*wxTRANSPARENT_BRUSH);
	dc.DrawRectangle(0, 0, clientRect.GetWidth(), clientRect.GetHeight());
	dc.SetFont(GetFont());
	dc.SetTextForeground(GetForegroundColour());
}

void MainFrame::SetListPaint(const wxEvent &evt) {
	wxLogStatus("execute");
	wxPaintDC dc(panelList);
	wxRect clientRect = GetClientRect();
	wxRect gradientRect = clientRect;
	dc.GradientFillLinear(gradientRect, wxColour(40, 40, 45), wxColour(38, 38, 43), wxSOUTH);
	gradientRect.Offset(0, gradientRect.GetHeight());
	dc.GradientFillLinear(gradientRect, wxColour(36, 36, 41), wxColour(34, 34, 39), wxSOUTH);

	dc.SetPen(wxColor(255, 0, 0));
	dc.SetBrush(*wxTRANSPARENT_BRUSH);
	dc.DrawRectangle(0, 0, clientRect.GetWidth(), clientRect.GetHeight());
	dc.SetFont(GetFont());
	dc.SetTextForeground(GetForegroundColour());
}