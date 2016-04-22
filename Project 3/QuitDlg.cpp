// QuitDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Project 3.h"
#include "QuitDlg.h"
#include "afxdialogex.h"


// QuitDlg dialog

IMPLEMENT_DYNAMIC(QuitDlg, CDialogEx)

QuitDlg::QuitDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(QuitDlg::IDD, pParent)
{

}

QuitDlg::~QuitDlg()
{
}

void QuitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(QuitDlg, CDialogEx)
//	ON_BN_CLICKED(IDOK, &QuitDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK, &QuitDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// QuitDlg message handlers




void QuitDlg::OnBnClickedOk()
{
	EndDialog(IDOK);
}
