#include "order.h"
#include <iostream>
#include <string>

using namespace std;

int order::orderidserial = 0;

order::order()
{
	Orderid = ++orderidserial;
	Pnames = new string[100];
	prices = new double[100];
	total = 0.0; 
	itemIndex = -1;
}

order::insertNewItem(string name, double price)
{
	itemIndex++;
	Pnames[itemIndex] = name;
	prices[itemIndex] = price;
	total += price;
	count++;
}

order::getOrder()
{
	cout<<"\t\t\tOrder Details"<<endl;
	cout<<"Order number: "<<Orderid<<endl;
	cout<<"\n";
	cout<<"--------------------------------------------------"<<endl;
	cout<<"Name"<<"\t"<<"Price"<<endl;
	for (int x = 0; x < count; x++)
	{
		cout<<Pnames[x]<<"\t"<<prices[x]<<endl;
		cout<<"---------------"<<endl;
	}
}
