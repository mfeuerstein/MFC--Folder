// AddToCartDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Project 3.h"
#include "AddToCartDlg.h"
#include "afxdialogex.h"
#include <iomanip>
#include <sstream>


// AddToCartDlg dialog

IMPLEMENT_DYNAMIC(AddToCartDlg, CDialogEx)

AddToCartDlg::AddToCartDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddToCartDlg::IDD, pParent)
{
	index = -1;
	itemQuant = -1;

}

AddToCartDlg::AddToCartDlg(const LinkList list, CWnd* pParent)
	: CDialogEx(AddToCartDlg::IDD, pParent)
{
	inventory = list;
}

AddToCartDlg::~AddToCartDlg()
{
}

void AddToCartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	wchar_t *item;
	string itemString;

	DDX_Control(pDX, IDC_ATC_COMBO_ITEMS, itemsCombo);
	DDX_Control(pDX, IDC_ATC_COMBO_QUANTS, quantsCombo);

	for (int i = 0; i < 10; i++)
	{
		itemString = inventory.getProductAt(i).stockID;
		item = new wchar_t[itemString.length() + 1];
		copy(itemString.begin(), itemString.end(), item);
		item[itemString.length()] = 0;
		itemsCombo.AddString(item);
		delete[] item;
	}

	DDX_Control(pDX, IDC_EDIT_ATC_DESC, itemDescription);
	DDX_Control(pDX, IDC_EDIT_ATC_PRICE, itemPrice);
	DDX_Control(pDX, IDD_ADD_ITEM_BTTN, okButton);
}


BEGIN_MESSAGE_MAP(AddToCartDlg, CDialogEx)
	ON_WM_ACTIVATE()
	ON_CBN_SELCHANGE(IDC_ATC_COMBO_ITEMS, &AddToCartDlg::OnCbnSelchangeAtcComboItems)
	ON_CBN_SELCHANGE(IDC_ATC_COMBO_QUANTS, &AddToCartDlg::OnCbnSelchangeAtcComboQuants)
	ON_BN_CLICKED(IDD_ADD_ITEM_BTTN, &AddToCartDlg::OnBnClickedAddItemBttn)
END_MESSAGE_MAP()


// AddToCartDlg message handlers

void AddToCartDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialogEx::OnActivate(nState, pWndOther, bMinimized);
}



void AddToCartDlg::OnCbnSelchangeAtcComboItems()
{
	wchar_t *item;
	index;

	okButton.EnableWindow(false);

	index = itemsCombo.GetCurSel();

	// Display item description of selected stock number
	string itemString = inventory.getProductAt(index).description;
	item = new wchar_t[itemString.length() + 1];
	copy(itemString.begin(), itemString.end(), item);
	item[itemString.length()] = 0;
	itemDescription.SetWindowTextW(item);
	delete[] item;

	// Display price of selected stock number
	double price = inventory.getProductAt(index).price;
	stringstream out;
	out << setprecision(2) << showpoint << fixed << price;
	itemString = "$" + out.str();
	item = new wchar_t[itemString.length() + 1];
	copy(itemString.begin(), itemString.end(), item);
	item[itemString.length()] = 0;
	itemPrice.SetWindowTextW(item);
	delete[] item;

	quantsCombo.ResetContent();

	if (inventory.getProductAt(index).quantity <= 0)
	{
		itemString = "OUT OF STOCK";
		item = new wchar_t[itemString.length() + 1];
		copy(itemString.begin(), itemString.end(), item);
		item[itemString.length()] = 0;
		quantsCombo.AddString(item);
		delete[] item;
	}

	else
	{
		for (int i = 1; i <= inventory.getProductAt(index).quantity; i++)
		{
			itemString = to_string(i);
			item = new wchar_t[itemString.length() + 1];
			copy(itemString.begin(), itemString.end(), item);
			item[itemString.length()] = 0;
			quantsCombo.AddString(item);
			delete[] item;
		}
	}
	// fill quantity
}


void AddToCartDlg::OnCbnSelchangeAtcComboQuants()
{
	CString str;

	int quantIndex = quantsCombo.GetCurSel();
	quantsCombo.GetLBText(quantIndex, str);

	if (quantIndex >= 0 && wcscmp(str, L"OUT OF STOCK") != 0)
	{
		okButton.EnableWindow(true);
		itemQuant = quantIndex + 1;
	}
	else
		okButton.EnableWindow(false);
}

string AddToCartDlg::getStockID()
{
	return inventory.getProductAt(index).stockID;
}

int AddToCartDlg::getQuantity()
{
	return itemQuant;
}


void AddToCartDlg::OnBnClickedAddItemBttn()
{
	EndDialog(IDOK);
}

int AddToCartDlg::getIndex()
{
	return index;
}

