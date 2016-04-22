#pragma once
#include "afxwin.h"
#include "resource.h"


// RemoveDirDialog dialog

class RemoveDirDialog : public CDialog
{
	DECLARE_DYNAMIC(RemoveDirDialog)

public:
	RemoveDirDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~RemoveDirDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_REMOVE_DIR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit editRemove;
	afx_msg void OnBnClickedOk();
};
