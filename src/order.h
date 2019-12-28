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
			double total;
		};
	
		int Orderid;
		int count;
		double total;
		bool delivered;
		static int orderidserial;
		LinkedList<int, Item> items;
		Item item;
		
	public:
		Order();
		insertNewItem(Product , int);
		bool removeItem(int);
//		void retrieve(int Order &) const;	
		void displayItems();
		void deleteItems();
};

#include "order.cpp"
#endif
