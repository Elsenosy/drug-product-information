#include <iostream>
#include "src/product.h"
#include "src/order.h"
#include "src/queueL.h"
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	string n0 ="z1";
	string n1 = "pr1", n2 = "pr2", n3= "pr3", n4= "pr4", n5= "pr5"; 
	
	float x1= 10.0, x2= 20.0, x3= 30.0, x4= 40.0, x5= 50.0;
	
	// Products 
	Product prods[5];
	
	prods[0].setData(n1 , n0 , n0 , x1);
	prods[1].setData(n2 , n0 , n0 , x2);
	prods[2].setData(n3 , n0 , n0 , x3);
	prods[3].setData(n4 , n0 , n0 , x4);
	prods[4].setData(n5 , n0 , n0 , x5);

	Order order1;
	
	order1.insertNewItem(prods[0], 5);
	order1.insertNewItem(prods[1], 3);
	order1.insertNewItem(prods[2], 2);
	order1.insertNewItem(prods[3], 1);
	
	order1.displayItems();
	// Remove an item	
	order1.removeItem(513);
	
	order1.displayItems();
	
	return 0;
}
