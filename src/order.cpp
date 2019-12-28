#ifndef ORDER_IMP__CPP 
#define ORDER_IMP__CPP 

#include "order.h"
#include "product.h"
#include "linkedList.cpp"
#include <iostream>
#include <string>

using namespace std;

int Order::orderidserial = 0;

Order::Order(){
	// Set empty item
	items.makeListEmpty();
//	Orderid = ++orderidserial;
	total = 0.0; 
	count = 0;
	delivered = false;
}

//void Order::retrieve(int id, Order &order){
//		
//};
Order::insertNewItem(Product prod, int quant){
	// Make a new item 
	item.id = prod.getId();
	item.product = prod;
	item.quantity = quant;
	item.total = prod.getPrice() * quant; // Calculate item price
	items.insertFirst(item.id, item); // Insert the item in the linkedList
	total += item.total; // Calculate the total order
	count++;
}
// Display order item(s)
void Order::displayItems(){
	// Define an empty product
	Item item1; // Retrieve an item from the linkedList
	string name; // Get product name by reference
	float price = 0.0; // Get product price
	string status = (delivered == true )? "Delivered" : "Not Delevered";
	// Check if no products exists
	if(items.listIsEmpty()){
		cout << "No items exists"<<endl;
		return;	
	}
	
	items.toFirst(); // Go to the first of the list
	
	// Formate the output
//	cout << "Order ID: " << Orderid << ", Status: "<<  status << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "ID \t" << "Name" << "\t \t"<< "Price"<< "\t " << "Quantity"<< "\t" << "Total item price"<< endl;
	cout << "-----------------------------------------------------------------" << endl;
	// Loop through products
	while(!items.curIsEmpty()){
		items.retrieve(item1); // Retrieve the item by reference
		item1.product.getName(name); // Retrieve product name
		price = item1.product.getPrice(); // Retrieve product price
		cout << item1.id << " \t" << name << " \t \t " << price << " L.E \t"<< item1.quantity << "\t" << item1.total << " L.E"<<endl;
		items.advance();
	}
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Total items: " << items.listSize() << " \t \t \t \t Total: "<<total << " L.E"<< endl;
	cout << "-----------------------------------------------------------------" << endl;
}

bool Order::removeItem(const int itemId){
	bool removed = false;
	Item temp;
	items.makeListEmpty();
	items.search(itemId, temp);
	// Update total price 
	total -= temp.total;
	items.deleteNode();
	return removed;
}

void Order::deleteItems(){
	items.makeListEmpty();
	count = 0;;
}

#endif
