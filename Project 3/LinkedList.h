#include "Product.h"
#include <fstream>

using namespace std;
/////////////
struct Link
{
//public:
	Product product;   //make product
	Link *pNext;

	Link(Product prod){
		product.copy(prod);
		pNext = NULL;
	}

	void displayLink(){
		product.displayInfo();
	}
};

struct LinkList
{
	Link *pFirst;

//public:

	LinkList(){
		pFirst = NULL;
	}

	bool isEmpty(){
		return pFirst == NULL;
	}

	void insertFirst(Product prod){
		Link *pNewLink = new Link(prod);
		pNewLink->pNext = pFirst;
		pFirst = pNewLink;
	}

	void insert(Product *prod)
	{
		Link* pPrevious = NULL;
		Link* pCurrent = pFirst;
		Link* newLink = new Link(*prod);

		if (isEmpty()){
			pFirst = newLink;
			newLink->pNext = NULL;
		}

		else{

			while (pCurrent->pNext != NULL){
				if (newLink->product.stockID <= pCurrent->product.stockID)
					break;
				pPrevious = pCurrent;
				pCurrent = pCurrent->pNext;
			}

			if (newLink->product.stockID < pFirst->product.stockID){
				cout << "\nCHeck 1";
				newLink->pNext = pFirst;
				pFirst = newLink;
			}

			else if (newLink->product.stockID < pCurrent->product.stockID){
				cout << "\nCHeck 1";
				pPrevious->pNext = newLink;
				newLink->pNext = pCurrent;
			}

			else if (pCurrent->pNext == NULL && newLink->product.stockID != pCurrent->product.stockID){
				cout << "\nCHeck 1";
				pCurrent->pNext = newLink;
			}
		}
	}

	void saveList(const char *file)
	{
		Product prod;
		try{
			ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);

			for (int i = 0; i < 10; i++)
			{
				prod.copy(getProductAt(i));
				fout.write((char *)&prod, sizeof prod);
			}

			fout.close();
		}
		catch (exception){};
	}
	

	void loadList(const char *file)
	{
		Product prod;
		try{
			ifstream fIn(file, ios_base::in | ios_base::binary);

			for (int i = 0; i < 10; i++)
			{
				fIn.read((char *)&prod, sizeof prod);
				insert(prod);
			}

			fIn.close();
		}
		catch (exception){ cout << "WE FUCKED UP"; };
	}
	void insert(Product prod)
	{
		Link* pPrevious = NULL;
		Link* pCurrent = pFirst;
		Link* newLink = new Link(prod);

		if (isEmpty()){
			pFirst = newLink;
			newLink->pNext = NULL;
		}

		else{

			while (pCurrent->pNext != NULL){
				if (newLink->product.stockID <= pCurrent->product.stockID)
					break;
				pPrevious = pCurrent;
				pCurrent = pCurrent->pNext;
			}

			if (newLink->product.stockID < pFirst->product.stockID){
				//cout << "\nCHeck 1";
				newLink->pNext = pFirst;
				pFirst = newLink;
			}

			else if (newLink->product.stockID < pCurrent->product.stockID){
				//cout << "\nCHeck 1";
				pPrevious->pNext = newLink;
				newLink->pNext = pCurrent;
			}

			else if (pCurrent->pNext == NULL && newLink->product.stockID != pCurrent->product.stockID){
				cout << "\nCHeck 1";
				pCurrent->pNext = newLink;
			}
		}
	}

	Product getFirst(){
		return pFirst->product;
	}

	void removeFirst(){
		Link* pTemp = pFirst;
		pFirst = pFirst->pNext;
		delete pTemp;
	}

	Product getProductAt(int index){

		Link* pCurrent = pFirst;

		if (isEmpty()){
			return *(new Product());
		}

		else{

			for (int pos = 0; pos < index; pos++){
				if (pCurrent->pNext == NULL)
					return *(new Product());
				pCurrent = pCurrent->pNext;
			}
			return pCurrent->product;
		}
	}

	void setQuantity(int index, int quant)
	{
		Link* pCurrent = pFirst;

		if (!isEmpty()){

			for (int pos = 0; pos < index; pos++){
				if (pCurrent->pNext == NULL)
					return;
				pCurrent = pCurrent->pNext;
			}
			pCurrent->product.quantity = quant;
		}
	}

	void setQuantity(string stockNum, int quant)
	{
		Link* pCurrent = pFirst;

		if (!isEmpty()){
			
			while (pCurrent->pNext != NULL){
				if (pCurrent->product.stockID == stockNum)
				{
					pCurrent->product.quantity = quant;
					break;
				}
				pCurrent = pCurrent->pNext;
			}
		}
	}

	void displayList(){
		cout << "\n\nList (first --> last): ";
		Link *pCurrent = pFirst;
		while (pCurrent != NULL){
			pCurrent->displayLink();
			pCurrent = pCurrent->pNext;
		}
		cout << endl;
	}
};

