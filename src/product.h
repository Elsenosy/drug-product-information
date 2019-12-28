#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class Product{
	private:
		int id;
		string name;
		string dosageForm;
		string activeIng;
		double price;
		static int count;
		
	public:
		Product();
		setProduct();
		setID(const int);
		setData(string &pr_name, string &dosage_form, string &pr_activeIng, float &pr_price);
		display();
		
		// Getters
		getProduct(Product &);
		int getId() const;
		void getName(string &) const;
		void getDosageForm(string &) const;
		void getactiveIng(string &) const;
		float getPrice() const;
};

#include "product.cpp"
#endif
