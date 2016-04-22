#pragma once



// CartView form view

class CartView : public CFormView
{
	DECLARE_DYNCREATE(CartView)

protected:
	CartView();           // protected constructor used by dynamic creation
	virtual ~CartView();

public:
	enum { IDD = IDD_VIEW_CART };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};


