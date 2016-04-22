// CheckoutView.cpp : implementation file
//

#include "stdafx.h"
#include "Project 3.h"
#include "CheckoutView.h"
#include "MainFrm.h"

// CheckoutView

IMPLEMENT_DYNCREATE(CheckoutView, CFormView)

CheckoutView::CheckoutView()
	: CFormView(CheckoutView::IDD)
{
	EditName.SetFocus();
}

CheckoutView::~CheckoutView()
{
}

void CheckoutView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_TOTAL, editTotal);
	DDX_Control(pDX, IDC_EDIT_TAX, editTax);
	DDX_Control(pDX, IDC_EDIT_SHIP, editShip);
	DDX_Control(pDX, IDC_EDIT_NAME, EditName);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, editAddress);
	DDX_Control(pDX, IDC_VIEW_RT_STOCK, stockList);
	DDX_Control(pDX, IDC_VIEW_CRT_QUANT, quantList);
	DDX_Control(pDX, IDC_VIEW_CRT_PRICE, priceList);
	DDX_Control(pDX, IDC_VIEW_CRT_DESC, descList);
	DDX_Control(pDX, IDC_VIEW_CRT_EXTENSION, extList);

	wchar_t *item;
	string itemString;

	double total = 0;

	for (int i = 0; i < 10; i++)
	{
		itemString = inventory.getProductAt(i).stockID;
		item = new wchar_t[itemString.length() + 1];
		copy(itemString.begin(), itemString.end(), item);
		item[itemString.length()] = 0;
		stockList.AddString(item);
		delete[] item;

		itemString = "" + to_string(inventory.getProductAt(i).quantity);
		item = new wchar_t[itemString.length() + 1];
		copy(itemString.begin(), itemString.end(), item);
		item[itemString.length()] = 0;
		quantList.AddString(item);
		delete[] item;

		itemString = inventory.getProductAt(i).description;
		item = new wchar_t[itemString.length() + 1];
		copy(itemString.begin(), itemString.end(), item);
		item[itemString.length()] = 0;
		descList.AddString(item);
		delete[] item;

		itemString = "$" + to_string(inventory.getProductAt(i).price);
		item = new wchar_t[itemString.length() + 1];
		copy(itemString.begin(), itemString.end(), item);
		item[itemString.length()] = 0;
		priceList.AddString(item);
		delete[] item;

		total += inventory.getProductAt(i).price * inventory.getProductAt(i).quantity;

		itemString = "$" + to_string(inventory.getProductAt(i).price * inventory.getProductAt(i).quantity);
		item = new wchar_t[itemString.length() + 1];
		copy(itemString.begin(), itemString.end(), item);
		item[itemString.length()] = 0;
		extList.AddString(item);
		delete[] item;
	}

	itemString = "$" + to_string(total * .0625);
	item = new wchar_t[itemString.length() + 1];
	copy(itemString.begin(), itemString.end(), item);
	item[itemString.length()] = 0;
	editTax.SetWindowTextW(item);
	delete[] item;

	total += total * .0625;

	itemString = "$" + to_string(9.95);
	item = new wchar_t[itemString.length() + 1];
	copy(itemString.begin(), itemString.end(), item);
	item[itemString.length()] = 0;
	editShip.SetWindowTextW(item);
	delete[] item;

	total += 9.95;

	itemString = "$" + to_string(total);
	item = new wchar_t[itemString.length() + 1];
	copy(itemString.begin(), itemString.end(), item);
	item[itemString.length()] = 0;
	editTotal.SetWindowTextW(item);
	delete[] item;
}

BEGIN_MESSAGE_MAP(CheckoutView, CFormView)
END_MESSAGE_MAP()


// CheckoutView diagnostics

#ifdef _DEBUG
void CheckoutView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CheckoutView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CheckoutView message handlers
