#pragma once
#include "afxwin.h"
#include "resource.h"

// NewFileDialog dialog

class NewFileDialog : public CDialog
{
	DECLARE_DYNAMIC(NewFileDialog)

public:
	NewFileDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~NewFileDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_NEWFILE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit editName;
	CEdit editPath;
	afx_msg void OnBnClickedOk();
};
