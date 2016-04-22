
// MainFrm.h : interface of the CMainFrame class
//

#include "Project 3.h"
#include "InventoryView.h"
#include "CrtView.h"
#include "CheckoutView.h"

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

LinkList inventory; 
LinkList CustPurchases;
	
// Operations
public:

	void purchaseItem(string, int, int);
	void removeItem(string, int, int);
	void mainWindow();
// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
	afx_msg void OnAppAbout();
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar        m_wndStatusBar;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnShopmenuAddtocart();
	afx_msg void OnShopmenuRemovefromcart();
	afx_msg void OnShopmenuViewinventory();
	afx_msg void OnShopmenuDisplaycontentsofcart();
	afx_msg void OnShopmenuCheckout();
	afx_msg void OnShopmenuQuit();
	afx_msg void OnShopmenuTest();
};


