// InventoryView.cpp : implementation file
//

#include "stdafx.h"
#include "Project 3.h"
#include "InventoryView.h"
#include "MainFrm.h"


// InventoryView

IMPLEMENT_DYNCREATE(InventoryView, CFormView)

InventoryView::InventoryView()
	: CFormView(InventoryView::IDD)
{

}

InventoryView::InventoryView(LinkList list)
	: CFormView(InventoryView::IDD)
{
	inventory = list;
}


InventoryView::~InventoryView()
{
}

void InventoryView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_VIEW_INV_DESC, descList);
	DDX_Control(pDX, IDC_VIEW_INV_PRICE, priceList);
	DDX_Control(pDX, IDC_VIEW_INV_QUANT, quantList);
	DDX_Control(pDX, IDC_VIEW_INV_STOCK, stockList);

	wchar_t *item;
	string itemString;

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

		itemString = "$" +  to_string(inventory.getProductAt(i).price);
		item = new wchar_t[itemString.length() + 1];
		copy(itemString.begin(), itemString.end(), item);
		item[itemString.length()] = 0;
		priceList.AddString(item);
		delete[] item;
	}
}

BEGIN_MESSAGE_MAP(InventoryView, CFormView)
	ON_LBN_SELCHANGE(IDC_VIEW_INV_STOCK, &InventoryView::OnLbnSelchangeViewInvStock)
END_MESSAGE_MAP()


// InventoryView diagnostics

#ifdef _DEBUG
void InventoryView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void InventoryView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// InventoryView message handlers


void InventoryView::OnLbnSelchangeViewInvStock()
{
	// TODO: Add your control notification handler code here
}
