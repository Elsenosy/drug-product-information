#include "product.h"
#include <iostream>
#include <string>

using namespace std;

#define print(x) cout<<x
#define printn(x) cout<<x<<endl
#define input(x) cin>>x

int product::count = 0;

product::product()
{
	id = ++count;
}

product::setProduct()
{
	print("Please enter product name: ");
	input(name);
	print("\n");
	print("Please enter product dosage form: ");
	input(dosageForm);
	print("\n");
	print("Please enter product active ingredient: ");
	getline(cin, activeIng);
	print("\n");
	print("Please enter product price: ");
	input(price);
	print("\n");
}

product::getProduct()
{
	printn("Product name: "<<name);
	printn("Product dosage form: "<<dosageForm);
	printn("Product active ingredient: "<<activeIng);
	printn("Product price: "<<price);
}
