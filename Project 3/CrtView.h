#pragma once
#include "afxwin.h"



// CrtView form view

class CrtView : public CFormView
{
	DECLARE_DYNCREATE(CrtView)

protected:
	CrtView();           // protected constructor used by dynamic creation
	virtual ~CrtView();

public:
	enum { IDD = IDD_VIEW_CART };

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
	CListBox descList;
	CListBox extList;
	CListBox priceList;
	CListBox quantList;
	CListBox stockList;
};


