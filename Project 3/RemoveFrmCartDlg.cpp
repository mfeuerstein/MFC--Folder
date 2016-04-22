// RemoveFrmCartDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Project 3.h"
#include "RemoveFrmCartDlg.h"
#include "afxdialogex.h"
#include <iomanip>
#include <sstream>

// RemoveFrmCartDlg dialog

IMPLEMENT_DYNAMIC(RemoveFrmCartDlg, CDialogEx)

RemoveFrmCartDlg::RemoveFrmCartDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(RemoveFrmCartDlg::IDD, pParent)
{
	index = -1;
	itemQuant = -1;
}

RemoveFrmCartDlg::RemoveFrmCartDlg(const LinkList list, CWnd* pParent)
	: CDialogEx(RemoveFrmCartDlg::IDD, pParent)
{
	inventory = list;
}
RemoveFrmCartDlg::~RemoveFrmCartDlg()
{
}

void RemoveFrmCartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RFC_DESC, rmvDesc);
	DDX_Control(pDX, IDC_EDIT_RFC_PRICE, rmvPrice);
	DDX_Control(pDX, IDC_LIST_RFC_ITEMS, itemsCombo);
	DDX_Control(pDX, IDC_LIST_RFC_QUANT, quantsCombo);

	wchar_t *item;
	string itemString;

	for (int i = 0; i < 10; i++)
	{
		//if (inventory.getProductAt(i).quantity > 0){
			itemString = inventory.getProductAt(i).stockID;
			item = new wchar_t[itemString.length() + 1];
			copy(itemString.begin(), itemString.end(), item);
			item[itemString.length()] = 0;
			itemsCombo.AddString(item);
			delete[] item;
		
	}

	DDX_Control(pDX, IDD_REMOVE_ITEM_BTTN, okButton);
}


BEGIN_MESSAGE_MAP(RemoveFrmCartDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_LIST_RFC_ITEMS, &RemoveFrmCartDlg::OnSelchangeListRfcItems)
	ON_CBN_SELCHANGE(IDC_LIST_RFC_QUANT, &RemoveFrmCartDlg::OnSelchangeListRfcQuant)
	ON_BN_CLICKED(IDD_REMOVE_ITEM_BTTN, &RemoveFrmCartDlg::OnClickedIddRemoveItemBttn)
END_MESSAGE_MAP()



string RemoveFrmCartDlg::getStockID()
{
	return inventory.getProductAt(index).stockID;
}

int RemoveFrmCartDlg::getQuantity()
{
	return itemQuant;
}

int RemoveFrmCartDlg::getIndex()
{
	return index;
}

// RemoveFrmCartDlg message handlers
void RemoveFrmCartDlg::OnSelchangeListRfcItems()
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
	rmvDesc.SetWindowTextW(item);
	delete[] item;

	// Display price of selected stock number
	double price = inventory.getProductAt(index).price;
	stringstream out;
	out << setprecision(2) << showpoint << fixed << price;
	itemString = "$" + out.str();
	item = new wchar_t[itemString.length() + 1];
	copy(itemString.begin(), itemString.end(), item);
	item[itemString.length()] = 0;
	rmvPrice.SetWindowTextW(item);
	delete[] item;

	quantsCombo.ResetContent();

	if (inventory.getProductAt(index).quantity < 0)
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
}


void RemoveFrmCartDlg::OnSelchangeListRfcQuant()
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


void RemoveFrmCartDlg::OnClickedIddRemoveItemBttn()
{
	EndDialog(IDOK);
}
