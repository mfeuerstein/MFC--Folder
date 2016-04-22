/*// SplashDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SplashDlg.h"
#include "afxdialogex.h"

// CSplashDlg dialog

IMPLEMENT_DYNAMIC(CSplashDlg, CDialog)

CSplashDlg::CSplashDlg(CWnd* pParent /*=NULL*/)
: CDialog(CSplashDlg::IDD, pParent)
{

}

CSplashDlg::~CSplashDlg()
{
}

void CSplashDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSplashDlg, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CSplashDlg message handlers


void CSplashDlg::ShowSplashScreen(CWnd* pParentWnd)
{
	// Allocate a new splash screen, and create the window.
	c_pSplashDlg = new CSplashDlg;
	if (!c_pSplashDlg->Create(CSplashDlg::IDD, pParentWnd))
		delete c_pSplashDlg;
	else
		c_pSplashDlg->ShowWindow(SW_SHOW);
	c_pSplashDlg->UpdateWindow();

	c_pSplashDlg->SetTimer(1, 2000, NULL);
}


void CSplashDlg::HideSplashScreen()
{
	// Destroy the window, and update the mainframe.
	c_pSplashDlg->KillTimer(1);
	DestroyWindow();
	AfxGetMainWnd()->UpdateWindow();
	delete c_pSplashDlg;
	c_pSplashDlg = NULL;
}


BOOL CSplashDlg::PreTranslateAppMessage(MSG* pMsg)
{
	if (c_pSplashDlg == NULL)
		return FALSE;

	// If you receive a keyboard or mouse message, hide the splash screen.
	if (c_pSplashDlg->m_hWnd != NULL && pMsg->message == WM_KEYDOWN ||
		pMsg->message == WM_SYSKEYDOWN ||
		pMsg->message == WM_LBUTTONDOWN ||
		pMsg->message == WM_RBUTTONDOWN ||
		pMsg->message == WM_MBUTTONDOWN ||
		pMsg->message == WM_NCLBUTTONDOWN ||
		pMsg->message == WM_NCRBUTTONDOWN ||
		pMsg->message == WM_NCMBUTTONDOWN)
	{
		c_pSplashDlg->HideSplashScreen();
		return TRUE;	// message handled here
	}

	return FALSE;	// message not handled
}


void CSplashDlg::OnTimer(UINT_PTR nIDEvent)
{
	// Destroy the splash screen window.
	HideSplashScreen();
}


BOOL CSplashDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CenterWindow();

	SetWindowPos(&CWnd::wndTopMost, 0, 0, 0, 0,
		SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}*/