#pragma once
#include "afxwin.h"
#include "resource.h"


// TypeDialog dialog

class TypeDialog : public CDialog
{
	DECLARE_DYNAMIC(TypeDialog)

public:
	TypeDialog(CWnd* pParent = NULL);   // standard constructor
	CString getEditText();
	virtual ~TypeDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_TYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit pathname;
	afx_msg void OnBnClickedOk();
};
