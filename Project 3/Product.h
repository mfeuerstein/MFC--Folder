#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
using namespace std;

struct Product
{
//public:
	string stockID;
	int quantity;
	string description;
	double price;

	Product()
	{
		stockID = "";
		quantity = 0;
		description = "";
		price = 0;
	}

	Product(string stockID, int quantity, string description, double price)
	{
		Product::stockID = stockID;
		Product::quantity = quantity;
		Product::description = description;
		Product::price = price;
	}

	Product(const Product &prod)
	{
		stockID = prod.stockID;
		quantity = prod.quantity;
		description = prod.description;
		price = prod.price;
	}

	void copy(const Product &prod)
	{
		stockID = prod.stockID;
		quantity = prod.quantity;
		description = prod.description;
		price = prod.price;
	}

	void displayInfo()
	{
		cout << "\nStock ID: " + stockID
			 << "\nQuantity: " << quantity
			 << "\nDescription: " + description
			 << "\nPrice: " << price;
	}
};
#endif