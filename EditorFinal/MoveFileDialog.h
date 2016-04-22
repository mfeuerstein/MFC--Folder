#pragma once


// MoveFileDialog dialog

#include "resource.h"
#include "afxwin.h"


class MoveFileDialog : public CDialog
{
	DECLARE_DYNAMIC(MoveFileDialog)

public:
	MoveFileDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~MoveFileDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_MOVEFILE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit currPath;
	CEdit newPath;
	afx_msg void OnBnClickedOk();
};
