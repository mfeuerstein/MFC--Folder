#pragma once
#include "afxwin.h"



// InventoryView form view

class InventoryView : public CFormView
{
	DECLARE_DYNCREATE(InventoryView)

public:
	InventoryView();           // protected constructor used by dynamic creation
	InventoryView::InventoryView(LinkList list);
	virtual ~InventoryView();

	LinkList inventory;

public:
	enum { IDD = IDD_VIEW_INV };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	CStatic stockNumList;
	afx_msg void OnLbnSelchangeViewInvStock();
//	CStatic quantList;
//	CListBox descList;
	CListBox descList;
	CListBox priceList;
	CListBox quantList;
	CListBox stockList;
};


