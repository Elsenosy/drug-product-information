#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class product
{
	private:
		
		int id;
		string name;
		string dosageForm;
		string activeIng;
		double price;
		static int count;
		
	public:
		
		product();
		setProduct();
		getProduct();
		
	protected:
};

#endif
