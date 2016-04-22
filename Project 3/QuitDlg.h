#pragma once


// QuitDlg dialog

class QuitDlg : public CDialogEx
{
	DECLARE_DYNAMIC(QuitDlg)

public:
	QuitDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~QuitDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_QUIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedOk();
};
