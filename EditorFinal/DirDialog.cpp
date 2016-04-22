// DirDialog.cpp : implementation file
//

#include "stdafx.h"
#include "DirDialog.h"
#include "afxdialogex.h"


// DirDialog dialog

IMPLEMENT_DYNAMIC(DirDialog, CDialog)

DirDialog::DirDialog(CWnd* pParent /*=NULL*/)
	: CDialog(DirDialog::IDD, pParent)
{

}

DirDialog::~DirDialog()
{
}

void DirDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DIR, editDir);
}


BEGIN_MESSAGE_MAP(DirDialog, CDialog)
	ON_BN_CLICKED(IDOK, &DirDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// DirDialog message handlers


void DirDialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();

	CString path;

	CFileDialog fileDialog(TRUE,
		NULL, NULL,
		OFN_FILEMUSTEXIST, NULL);

	editDir.GetWindowTextW(path);

	fileDialog.m_ofn.lpstrInitialDir = path;

	fileDialog.DoModal();
}
