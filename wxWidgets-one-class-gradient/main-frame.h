#ifndef main_frame_h
#define main_frame_h

#include <wx/wx.h>

class MainFrame : public wxFrame {
	private:

	public:
		MainFrame(const wxString &title);

		void SetTopPaint(const wxEvent &evt);
		void SetMenuPaint(const wxEvent &evt);
		void SetListPaint(const wxEvent &evt);
		void SetTestPaint(const wxEvent &evt);

		void ShowTest(const wxCommandEvent &evt);

		wxScrolledWindow *panelTop;
		wxScrolledWindow *panelMenu;
		wxScrolledWindow *panelList;
		wxScrolledWindow *panelTest;

		wxBoxSizer *sizerMain;
		wxBoxSizer *sizerList;
		wxBoxSizer *sizerTest;
};

#endif