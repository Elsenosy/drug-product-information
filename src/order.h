#ifndef ORDER_H
#define ORDER_H
#include <string>
#include "product.h"
#include "LinkedList.h"

using namespace std;

class Order{
	private:	
		int Orderid;
		int itemIndex;
		int count;
		double total;
		LinkedList<int, Product> products;
		static int orderidserial;
		
	public:
		Order();
		insertNewItem(Product &);
		getOrder();	
		void displayItems();
};

#include "order.cpp"
#endif
