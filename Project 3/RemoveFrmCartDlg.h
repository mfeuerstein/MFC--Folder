#pragma once
#include "MainFrm.h"
#include "afxwin.h"

// RemoveFrmCartDlg dialog

class RemoveFrmCartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RemoveFrmCartDlg)

public:
	RemoveFrmCartDlg(CWnd* pParent = NULL);   // standard constructor
	RemoveFrmCartDlg(const LinkList list, CWnd* pParent = NULL);
	virtual ~RemoveFrmCartDlg();
	string getStockID();
	int getQuantity();
	int getIndex();

	LinkList inventory;

// Dialog Data
	enum { IDD = IDD_REMOVE_FROM_CART };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSelchangeListRfcItems();
	afx_msg void OnSelchangeListRfcQuant();
	afx_msg void OnClickedIddRemoveItemBttn();
	CEdit rmvDesc;
	CEdit rmvPrice;
	CComboBox itemsCombo;
	CComboBox quantsCombo;
	int index, itemQuant;
	CButton okButton;
};
