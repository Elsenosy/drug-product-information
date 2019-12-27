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
	products.makeListEmpty();
	Orderid = ++orderidserial;
	total = 0.0; 
	count = 0;
	itemIndex = -1;
}

Order::insertNewItem(Product &prod)
{
	itemIndex++;
	products.insertFirst(itemIndex, prod);
	total += prod.getPrice();
	count++;
}

Order::getOrder()
{
	cout<<"\t\t\tOrder Details"<<endl;
	cout<<"Order number: "<<Orderid<<endl;
	cout<<"\n";
	cout<<"--------------------------------------------------"<<endl;
	cout<<"Name"<<"\t"<<"Price"<<endl;
	for (int x = 0; x < count; x++)
	{
//		cout<<Pnames[x]<<"\t"<<prices[x]<<endl;
		cout<<"---------------"<<endl;
	}
	cout<<"-----------------------"<<endl;
	cout<<"Total: "<<total<<endl;
}

void Order::displayItems(){
	int prodNum = 1;
	// Define an empty product
	Product pr1;
	string name, dosageForm, activeIng;
	float price = 0.0;
	
	// Check if no products exists
	if(products.listIsEmpty()){
		cout << "No items exists"<<endl;
		return;	
	}
	
	// Go to the first of the list
	products.toFirst();
	cout << "\n--------------------------------------- " << endl;
	cout << "--------- Order details: " << " ----------" <<endl;
	cout << "# " << "Name \t " << "Dosage Form \t \t  " << "Active Ing. \t " << "Price" << endl;
	
	// Loop through products
	while(!products.curIsEmpty()){
		products.retrieve(pr1); // Retrieve by reference
		
		pr1.getName(name);
		pr1.getDosageForm(dosageForm);
		pr1.getactiveIng(activeIng);
		price = pr1.getPrice();
		cout << prodNum << " " << name << " \t " << dosageForm << " \t \t \t \t"<< activeIng << " \t " << price << endl;
		
		products.advance();
		prodNum++;
	}
	cout << "\n-----------------------------------" << endl;
	cout << "Items: " << products.listSize() << " \t \t \t Total: "<<total << endl;
}

#endif
