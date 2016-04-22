// MoveFileDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MoveFileDialog.h"
#include "afxdialogex.h"
#include <windows.h>


// MoveFileDialog dialog

IMPLEMENT_DYNAMIC(MoveFileDialog, CDialog)

MoveFileDialog::MoveFileDialog(CWnd* pParent /*=NULL*/)
	: CDialog(MoveFileDialog::IDD, pParent)
{

}

MoveFileDialog::~MoveFileDialog()
{
}

void MoveFileDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CURRENTPATH, currPath);
	DDX_Control(pDX, IDC_EDIT_NEWPATH, newPath);
}


BEGIN_MESSAGE_MAP(MoveFileDialog, CDialog)
	ON_BN_CLICKED(IDOK, &MoveFileDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// MoveFileDialog message handlers


void MoveFileDialog::OnBnClickedOk()
{
	CDialog::OnOK();

	CString csCurrent, csNew;
	currPath.GetWindowTextW(csCurrent);
	newPath.GetWindowTextW(csNew);

	MoveFile(csCurrent, csNew);
}
