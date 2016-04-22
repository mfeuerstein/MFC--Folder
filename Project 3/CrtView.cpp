// CrtView.cpp : implementation file
//

#include "stdafx.h"
#include "Project 3.h"
#include "CrtView.h"
#include "MainFrm.h"


// CrtView

IMPLEMENT_DYNCREATE(CrtView, CFormView)

CrtView::CrtView()
	: CFormView(CrtView::IDD)
{

}

CrtView::~CrtView()
{
}

void CrtView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VIEW_CRT_DESC, descList);
	DDX_Control(pDX, IDC_VIEW_CRT_EXTENSION, extList);
	DDX_Control(pDX, IDC_VIEW_CRT_PRICE, priceList);
	DDX_Control(pDX, IDC_VIEW_CRT_QUANT, quantList);
	DDX_Control(pDX, IDC_VIEW_CRT_STOCK, stockList);

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

		itemString = "$" + to_string(inventory.getProductAt(i).price);
		item = new wchar_t[itemString.length() + 1];
		copy(itemString.begin(), itemString.end(), item);
		item[itemString.length()] = 0;
		priceList.AddString(item);
		delete[] item;

		itemString = "$" + to_string(inventory.getProductAt(i).price * inventory.getProductAt(i).quantity);
		item = new wchar_t[itemString.length() + 1];
		copy(itemString.begin(), itemString.end(), item);
		item[itemString.length()] = 0;
		extList.AddString(item);
		delete[] item;
	}
}

BEGIN_MESSAGE_MAP(CrtView, CFormView)
END_MESSAGE_MAP()


// CrtView diagnostics

#ifdef _DEBUG
void CrtView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CrtView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CrtView message handlers
