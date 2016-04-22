#pragma once
#include "afxwin.h"
#include "resource.h"


// DirDialog dialog

class DirDialog : public CDialog
{
	DECLARE_DYNAMIC(DirDialog)

public:
	DirDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~DirDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_DIR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit editDir;
	afx_msg void OnBnClickedOk();
};
