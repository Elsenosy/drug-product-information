#ifndef ORDER_H
#define ORDER_H
#include <string>
#include "product.h"
#include "LinkedList.h"

using namespace std;

class Order{
	private:	
		struct Item{
			int id;
			Product product;
			int quantity;
			float total;
		};
	
		int Orderid;
		int count;
		double total;
		static int orderidserial;
		LinkedList<int, Item> items;
		Item item;
		
	public:
		Order();
		insertNewItem(Product &, int);
		bool removeItem(int);
		getOrder();	
		void displayItems();
};

#include "order.cpp"
#endif
