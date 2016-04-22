#pragma once
#include "afxwin.h"
#include "MainFrm.h"

class RemoveFromCartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RemoveFromCartDlg)

public:
	RemoveFromCartDlg(CWnd* pParent = NULL);   // standard constructor
	RemoveFromCartDlg(const LinkList list, CWnd* pParent = NULL);
	string getStockID();
	int getQuantity();
	int getIndex();
	virtual ~RemoveFromCartDlg();

	// Dialog Data
	enum { IDD = IDD_REMOVE_FROM_CART };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	CComboBox itemsCombo;
	CComboBox quantsCombo;
	LinkList inventory;
	CEdit itemDescription;
	CEdit itemPrice;
	int index, itemQuant;
	CButton okButton;
	afx_msg void OnClickedIddRemoveItemBttn();
	//afx_msg void OnSelchangeListRfcItems();
	//afx_msg void OnSelchangeListRfcQuant();
	afx_msg void OnSelchangeListRfcItems();
//	afx_msg void OnListAtcQuant();
	afx_msg void OnSelchangeListRfcQuant();
};