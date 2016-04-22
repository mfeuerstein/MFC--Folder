// TestDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Project 3.h"
#include "TestDialog.h"
#include "afxdialogex.h"


// TestDialog dialog

IMPLEMENT_DYNAMIC(TestDialog, CDialog)

TestDialog::TestDialog(CWnd* pParent /*=NULL*/)
	: CDialog(TestDialog::IDD, pParent)
{

}

TestDialog::~TestDialog()
{
}

void TestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEST_COMBO, testComboBox);
}


BEGIN_MESSAGE_MAP(TestDialog, CDialog)
END_MESSAGE_MAP()


// TestDialog message handlers
