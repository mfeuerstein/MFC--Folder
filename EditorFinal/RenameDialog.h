#pragma once

#include "resource.h"
#include "afxwin.h"

// RenameDialog dialog

class RenameDialog : public CDialog
{
	DECLARE_DYNAMIC(RenameDialog)

public:
	RenameDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~RenameDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_RENAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit editNewName;
	CEdit editOldName;
	afx_msg void OnBnClickedOk();
};
