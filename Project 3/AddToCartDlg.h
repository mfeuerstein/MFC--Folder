#pragma once
#include "afxwin.h"
#include "MainFrm.h"

class AddToCartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddToCartDlg)

public:
	AddToCartDlg(CWnd* pParent = NULL);   // standard constructor
	AddToCartDlg(const LinkList list, CWnd* pParent = NULL);   
	string getStockID();
	int getQuantity();
	int getIndex();
	virtual ~AddToCartDlg();

// Dialog Data
	enum { IDD = IDD_ADD_TO_CART };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	CComboBox itemsCombo;
	CComboBox quantsCombo;
	LinkList inventory;
	afx_msg void OnCbnSelchangeAtcComboItems();
	CEdit itemDescription;
	CEdit itemPrice;
	int index, itemQuant;
	afx_msg void OnCbnSelchangeAtcComboQuants();
	CButton okButton;
	afx_msg void OnBnClickedAddItemBttn();
};
