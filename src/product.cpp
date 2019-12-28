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
	cout<<endl;
	print("Please enter product name: ");
	getline(cin, name);
	cout << endl;
	print("Please enter product dosage form: ");
	getline(cin, dosageForm);
	cout << endl;
	print("Please enter product active ingredient: ");
	getline(cin, activeIng);
	cout << endl;
	print("Please enter product price: ");
	input(price);
	
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

Product::setID(const int pr_id){
	id = pr_id;
};

/*
* Display product data
*/
Product::display(){
	cout << id << " " << name << " \t\t " << dosageForm << "\t\t" << activeIng << "\t\t" << price << " L.E" << endl;
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

int Product::getId() const{
	return id;
};

float Product::getPrice() const{
	return price;
};

#endif
