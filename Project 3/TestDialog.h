#pragma once
#include "resource.h"
#include "afxwin.h"

// TestDialog dialog

class TestDialog : public CDialog
{
	DECLARE_DYNAMIC(TestDialog)

public:
	TestDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~TestDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_TEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox testComboBox;
};
