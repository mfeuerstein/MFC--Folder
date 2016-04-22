/*#include "resource.h"
#pragma once

// CSplashDlg dialog

class CSplashDlg : public CDialog
{
	DECLARE_DYNAMIC(CSplashDlg)

public:
	CSplashDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSplashDlg();

	// Dialog Data
	enum { IDD = IDD_SPLASH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	static CSplashDlg* c_pSplashDlg;
	static void ShowSplashScreen(CWnd*);
	void HideSplashScreen();
	static BOOL PreTranslateAppMessage(MSG*);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
};

*/