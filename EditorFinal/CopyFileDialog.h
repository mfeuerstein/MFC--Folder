#pragma once
#include "afxwin.h"
#include "resource.h"

// CopyFileDialog dialog

class CopyFileDialog : public CDialog
{
	DECLARE_DYNAMIC(CopyFileDialog)

public:
	CopyFileDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CopyFileDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_COPY_FILE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit currPath;
	CEdit newPath;
	afx_msg void OnBnClickedOk();
};
