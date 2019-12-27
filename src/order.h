#ifndef ORDER_H
#define ORDER_H
#include <string>

using namespace std;

class order
{
	typedef order* ptr;
	typedef string* stptr;
	typedef double* dptr;
	
	private:
		
		int Orderid;
		stptr Pnames;
		dptr prices;
		double total;
		int count;
		int itemIndex;
		static int orderidserial;
		
	public:
		
		order();
		insertNewItem(string name, double price);
		getOrder();
		
	protected:
		
};

#endif
