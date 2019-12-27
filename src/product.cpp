#include "product.h"

#ifndef PRODUCT_IMP___
#define PRODUCT_IMP___
#include <iostream>
#include <string>

using namespace std;

#define print(x) cout<<x
#define printn(x) cout<<x<<endl
#define input(x) cin>>x

int Product::count = 0;

Product::Product(){
	 id = ++count;
};

/*
* Set product's basic data
*/
Product::setProduct()
{
	print("Please enter product name: ");
	getline(cin, name);

	print("\n");
	print("Please enter product dosage form: ");
	getline(cin, dosageForm);

	print("\n");
	print("Please enter product active ingredient: ");
	getline(cin, activeIng);
	print("\n");
	print("Please enter product price: ");
	input(price);
	print("\n");
}

/*
* Return product by reference, in the main function 
*/
Product::getProduct(Product &prodObj)
{
	prodObj.name = name;
	prodObj.dosageForm = dosageForm;
	prodObj.activeIng = activeIng;
	prodObj.price = price;
}


/*
* Set data without outputting 
*/
Product::setData(string &pr_name, string &dosage_form, string &pr_activeIng, float &pr_price){
	name = pr_name;
	dosageForm = dosage_form;
	activeIng = pr_activeIng;
	price = pr_price;
}
/*
* Display product data
*/
Product::display()
{
	 printn("Product name: "<<name);
	 printn("Product dosage form: "<<dosageForm);
	 printn("Product active ingredient: "<<activeIng);
	 printn("Product price: "<<price);
}

void Product::getName(string &pr_name) const{
	pr_name = name;
};
void Product::getDosageForm(string &pr_dosageForm) const{
	pr_dosageForm = dosageForm;
};
void Product::getactiveIng(string &pr_activeIng) const{
	pr_activeIng = activeIng;
};

float Product::getPrice() const{
	return price;
};

#endif
