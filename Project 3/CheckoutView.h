#pragma once
#include "afxwin.h"



// CheckoutView form view

class CheckoutView : public CFormView
{
	DECLARE_DYNCREATE(CheckoutView)

protected:
	CheckoutView();           // protected constructor used by dynamic creation
	virtual ~CheckoutView();

public:
	enum { IDD = IDD_VIEW_CHECKOUT };
	LinkList inventory;
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
	CEdit editTotal;
	CEdit editTax;
	CEdit editShip;
	CEdit EditName;
	CEdit editAddress;
	CListBox stockList;
	CListBox quantList;
	CListBox priceList;
	CListBox descList;
	CListBox extList;
};


