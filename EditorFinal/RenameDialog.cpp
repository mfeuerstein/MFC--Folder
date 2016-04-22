// RenameDialog.cpp : implementation file
//

#include "stdafx.h"
#include "RenameDialog.h"
#include "afxdialogex.h"


// RenameDialog dialog

IMPLEMENT_DYNAMIC(RenameDialog, CDialog)

RenameDialog::RenameDialog(CWnd* pParent /*=NULL*/)
	: CDialog(RenameDialog::IDD, pParent)
{

}

RenameDialog::~RenameDialog()
{
}

void RenameDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RENAME_NEW, editNewName);
	DDX_Control(pDX, IDC_EDIT_RENAME_OLD, editOldName);
}


BEGIN_MESSAGE_MAP(RenameDialog, CDialog)
	ON_BN_CLICKED(IDOK, &RenameDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// RenameDialog message handlers


void RenameDialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();

	CString oldPath, newPath;
	editOldName.GetWindowTextW(oldPath);
	editNewName.GetWindowTextW(newPath);

	TCHAR* oldPathName = oldPath.GetBuffer(oldPath.GetLength());
	oldPath.ReleaseBuffer();
	TCHAR* newPathName = newPath.GetBuffer(newPath.GetLength());
	newPath.ReleaseBuffer();

	try
	{
		CFile::Rename(oldPathName, newPathName);
	}
	catch (CFileException* pEx)
	{
		TRACE(_T("File %20s cannot be renamed\n"), oldPathName);
		pEx->Delete();
	}
}
