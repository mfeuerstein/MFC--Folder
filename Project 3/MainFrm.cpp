
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MainFrm.h"
#include "AddToCartDlg.h"
#include "RemoveFrmCartDlg.h"
#include "TestDialog.h"
#include "TestC.h"
#include "QuitDlg.h"
#include <fstream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_APP_ABOUT, &CMainFrame::OnAppAbout)
	ON_COMMAND(ID_SHOPMENU_ADDTOCART, &CMainFrame::OnShopmenuAddtocart)
	ON_COMMAND(ID_SHOPMENU_REMOVEFROMCART, &CMainFrame::OnShopmenuRemovefromcart)
	ON_COMMAND(ID_SHOPMENU_VIEWINVENTORY, &CMainFrame::OnShopmenuViewinventory)
	ON_COMMAND(ID_SHOPMENU_DISPLAYCONTENTSOFCART, &CMainFrame::OnShopmenuDisplaycontentsofcart)
	ON_COMMAND(ID_SHOPMENU_CHECKOUT, &CMainFrame::OnShopmenuCheckout)
	ON_COMMAND(ID_SHOPMENU_QUIT, &CMainFrame::OnShopmenuQuit)
	ON_COMMAND(ID_SHOPMENU_TEST, &CMainFrame::OnShopmenuTest)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	const char * file = "testProds.dat";
	
	inventory.insert(new Product("A100", 20, "Hammer", 9.95));
	inventory.insert(new Product("A250", 25, "Saw", 13.95));
	inventory.insert(new Product("B400", 50, "Flat-Head Nails", 11.99));
	inventory.insert(new Product("C888", 50, "Flat-Head Screwdriver", 6.59));
	inventory.insert(new Product("A499", 75, "Pliers", 4.95));
	inventory.insert(new Product("C667", 50, "Drill", 22.95));
	inventory.insert(new Product("B875", 70, "Plumber's Wrench", 11.90));
	inventory.insert(new Product("D547", 60, "Ladder 10 foot", 70.44));
	inventory.insert(new Product("A910", 85, "Flashlight 10 inch", 9.99));
	inventory.insert(new Product("B123", 90, "Assorted Buss Fuses", 4.99));
	
	CustPurchases.insert(new Product("A100", 0, "Hammer", 9.95));
	CustPurchases.insert(new Product("A250", 0, "Saw", 13.95));
	CustPurchases.insert(new Product("B400", 0, "Flat-Head Nails", 11.99));
	CustPurchases.insert(new Product("C888", 0, "Flat-Head Screwdriver", 6.59));
	CustPurchases.insert(new Product("A499", 0, "Pliers", 4.95));
	CustPurchases.insert(new Product("C667", 0, "Drill", 22.95));
	CustPurchases.insert(new Product("B875", 0, "Plumber's Wrench", 11.90));
	CustPurchases.insert(new Product("D547", 0, "Ladder 10 foot", 70.44));
	CustPurchases.insert(new Product("A910", 0, "Flashlight 10 inch", 9.99));
	CustPurchases.insert(new Product("B123", 0, "Assorted Buss Fuses", 4.99));

	/*
	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);

	fout.write((char *)&inventory, sizeof inventory);

	fout.close();
	

	ifstream fIn(file, ios_base::in | ios_base::binary);

	fIn.read((char *)&inventory, sizeof inventory);

	fIn.close();*/
	
	//inventory.insert(new Product("A100", 20, "Hammer", 9.95));

	//inventory.saveList(file);
	//inventory.loadList(file);

	TestC testC;
	CString test = L"Hi";
	testC.money = L"buffalo";
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	/*// First, build the view context structure
	CCreateContext ccx;

	// Designate the class from which to build the view
	ccx.m_pNewViewClass = RUNTIME_CLASS(InventoryView);

	// Using the structure, create a view
	i_View = DYNAMIC_DOWNCAST(InventoryView, this->CreateView(&ccx));

	// Did we succeed ?
	if (!i_View)
	{
		TRACE0("Creation of view failed\n");
		return -1;
	}

	RecalcLayout();

	// Show the view and do an initial update
	i_View->ShowWindow(SW_SHOW);
	i_View->OnInitialUpdate();

	// Set this view active
	SetActiveView(i_View);


	// Order it to resize the parent window's client area to fit
	i_View->ResizeParentToFit(FALSE);

	*/


	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}


#endif //_DEBUG


// CMainFrame message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CMainFrame::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// Add to Cart

void CMainFrame::OnShopmenuAddtocart()
{
	AddToCartDlg addDlg(inventory);

	INT_PTR nRet = -1;

	nRet = addDlg.DoModal();

	// Check the return value of DoModal
	if (nRet == IDOK)
	{
		// Process the user's input
		string stockID = addDlg.getStockID();
		int itemQuantity = addDlg.getQuantity();
		int index = addDlg.getIndex();
		purchaseItem(stockID, itemQuantity, index);
	}
}


void CMainFrame::OnShopmenuRemovefromcart()
{
	RemoveFrmCartDlg rmvDlg(CustPurchases);

	INT_PTR nRet = -1;

	nRet = rmvDlg.DoModal();

	// Check the return value of DoModal
	if (nRet == IDOK)
	{
		string stockID = rmvDlg.getStockID();
		int itemQuantity = rmvDlg.getQuantity();
		int index = rmvDlg.getIndex();
		removeItem(stockID, itemQuantity, index);
	}

}

void CMainFrame::purchaseItem(string stockID, int quantity, int index)
{
	int newQuantity = inventory.getProductAt(index).quantity - quantity;
	inventory.setQuantity(stockID, newQuantity);

	newQuantity = CustPurchases.getProductAt(index).quantity + quantity;
	CustPurchases.setQuantity(stockID, newQuantity);
}

void CMainFrame::removeItem(string stockID, int quantity, int index)
{
	int newQuantity = inventory.getProductAt(index).quantity + quantity;
	inventory.setQuantity(stockID, newQuantity);

	newQuantity = CustPurchases.getProductAt(index).quantity - quantity;
	CustPurchases.setQuantity(stockID, newQuantity);
}

void CMainFrame::OnShopmenuViewinventory()
{
	// First, build the view context structure
	CCreateContext ccx;

	// Designate the class from which to build the view
	ccx.m_pNewViewClass = RUNTIME_CLASS(InventoryView);

	InventoryView* i_View = new InventoryView(inventory);

	// Using the structure, create a view
	i_View = DYNAMIC_DOWNCAST(InventoryView, this->CreateView(&ccx));

	// Did we succeed ?
	if (!i_View)
	{
		TRACE0("Creation of view failed\n");
	}

	RecalcLayout();

	i_View->inventory = inventory;
	// Show the view and do an initial update
	i_View->ShowWindow(SW_SHOW);
	i_View->OnInitialUpdate();

	// Set this view active
	SetActiveView(i_View);



	// Order it to resize the parent window's client area to fit
	i_View->ResizeParentToFit(TRUE);
}

void CMainFrame::mainWindow()
{
	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");

	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));
}


void CMainFrame::OnShopmenuDisplaycontentsofcart()
{
	// First, build the view context structure
	CCreateContext ccx;

	// Designate the class from which to build the view
	ccx.m_pNewViewClass = RUNTIME_CLASS(CrtView);

	// Using the structure, create a view
	CrtView *c_View = DYNAMIC_DOWNCAST(CrtView, this->CreateView(&ccx));

	// Did we succeed ?
	if (!c_View)
	{
		TRACE0("Creation of view failed\n");
	}

	RecalcLayout();

	c_View->inventory = CustPurchases;
	// Show the view and do an initial update
	c_View->ShowWindow(SW_SHOW);
	c_View->OnInitialUpdate();

	// Set this view active
	SetActiveView(c_View);


	// Order it to resize the parent window's client area to fit
	c_View->ResizeParentToFit(FALSE);
}


void CMainFrame::OnShopmenuCheckout()
{
	// First, build the view context structure
	CCreateContext ccx;

	// Designate the class from which to build the view
	ccx.m_pNewViewClass = RUNTIME_CLASS(CheckoutView);

	// Using the structure, create a view
	CheckoutView *o_View = DYNAMIC_DOWNCAST(CheckoutView, this->CreateView(&ccx));

	// Did we succeed ?
	if (!o_View)
	{
		TRACE0("Creation of view failed\n");
	}

	RecalcLayout();

	o_View->inventory = CustPurchases;
	// Show the view and do an initial update
	o_View->ShowWindow(SW_SHOW);
	o_View->OnInitialUpdate();

	// Set this view active
	SetActiveView(o_View);

	// Order it to resize the parent window's client area to fit
	o_View->ResizeParentToFit(FALSE);
}


void CMainFrame::OnShopmenuQuit()
{
	QuitDlg quit;
	

	INT_PTR nRet = quit.DoModal();



	// Check the return value of DoModal
	if (nRet == IDOK)
	{
		AfxGetMainWnd()->PostMessage(WM_CLOSE);
	}
		
}


void CMainFrame::OnShopmenuTest()
{
	TestDialog testDlg;

	testDlg.DoModal();
}
