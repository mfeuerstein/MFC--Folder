// RemoveDirDialog.cpp : implementation file
//

#include "stdafx.h"
#include "RemoveDirDialog.h"
#include "afxdialogex.h"

// RemoveDirDialog dialog

IMPLEMENT_DYNAMIC(RemoveDirDialog, CDialog)

void RemoveAllInDir(CString strDir)
{
	WIN32_FIND_DATA   FileData;
	HANDLE hSearch;

	hSearch = FindFirstFile(strDir + "\\*", &FileData);

	while (hSearch != INVALID_HANDLE_VALUE &&
		FindNextFile(hSearch, &FileData))
	{
		
		if (FileData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
		{
			if (FileData.cFileName[0] != '.')
			{
				RemoveAllInDir(strDir + "\\" + FileData.cFileName);
			}
		}
		else 
		{
			CFile::Remove(strDir + "\\" + FileData.cFileName);
		}
	}
	if (hSearch != INVALID_HANDLE_VALUE)
	{
		FindClose(hSearch);
	}

	RemoveDirectory(strDir);
}

RemoveDirDialog::RemoveDirDialog(CWnd* pParent /*=NULL*/)
	: CDialog(RemoveDirDialog::IDD, pParent)
{

}

RemoveDirDialog::~RemoveDirDialog()
{
}

void RemoveDirDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_REMOVE_DIR, editRemove);
}


BEGIN_MESSAGE_MAP(RemoveDirDialog, CDialog)
	ON_BN_CLICKED(IDOK, &RemoveDirDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// RemoveDirDialog message handlers


void RemoveDirDialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();

	CString path;
	editRemove.GetWindowTextW(path);

	TCHAR* pathName = path.GetBuffer(path.GetLength());
	path.ReleaseBuffer();

	try
	{
		RemoveAllInDir(path);
	}
	catch (CFileException* pEx)
	{
		TRACE(_T("File %20s cannot be removed\n"), pathName);
		pEx->Delete();
	}
}
