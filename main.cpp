#include <iostream>
#include "src/product.h"
#include "src/order.h"
#include "src/queueL.h"
#include "src/stack.h"
#include <string>

void sysFunc();
void orderFunc();
void process(int &);
// Products
void initalData(LinkedList<int, Product>&);
void addProducts(int size, Stack<Product> &lastProducts, LinkedList<int, Product>&);
void viewProducts(LinkedList<int, Product>&);
void addOrder(LinkedList<int, Product>& ls,  Queue<Order> &orderq);

void lastProducts(Stack<Product>&lastProducts);
void lastOrders(Stack<Order>&lastOrders);

void deliverOrder(Queue<Order> &);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	LinkedList<int, Product> products;
	Order order;
	Queue<Order> notDeliveredOrders;
	
	Stack<Product> lastProducts;
	Stack<Order> lastOrders;
	
	int input = -1;


	// Set initial products
	initalData(products);
	while(input != 0){
		switch(input){
		case 1:
			int size;
			cout << "Enter size of products to add: "; cin>>size;
			addProducts(size, lastProducts, products);
		case 2:
			viewProducts(products);
		break;
		
		case 3:
			addOrder(products, notDeliveredOrders);
		break;
		
		case 4:
			deliverOrder(notDeliveredOrders);
		break;
		
//		case 5:
////			lastProducts(lastProducts);
//		break;
//		
//		case 6:
//			lastOrders(lastOrders);
//		break;
//		
//		case 7:
//		break;
		
		case 8:
		break;
		default:
			cout << "Unknown choice!" << endl;
		break;

	}
		process(input);
	}
	
	if(input == 0){
		cout << "Thanks for using Drug-Product-Information System :)"<<endl;
	}
		
	return 0;
}

void sysFunc(){
	cout << "------------------------------------------------- "<<endl;
	cout << " 1) Add new product" << endl;
	cout << " 2) View products" << endl;
	cout << " 3) Add new order" << endl;
	cout << " 4) Deliver an order" << endl;
	cout << " 5) View latest added products" << endl;
	cout << " 6) View latest delived orders" << endl;
}

//void orderFunc(){
//	cout << " 1) View items" << endl;
//	cout << " 2) Add new item" << endl;
//	cout << " 3) Remove an item" << endl;
//}

void process(int &input_t){
	int input;
	cout << "Enter a choice: , 0 to quit" << endl;
	sysFunc();
	cout<< " Choice: "; cin>>input;
	input_t = input;
}

// Functions
void initalData(LinkedList<int, Product>& products){
	
	Product pr1;
	// Define set of products
	string name1 = "Panadol" ,      name2 ="Panadol exra",       name3 ="Nifedipine",       name4 ="Nystaform",       name5 ="Nexicure";
	string name6 ="No gravida" ,      name7 ="Napizole",       name8 ="Memoral", name9="Norflex";
	
	string dosageForm1 ="Tablet", dosageForm2 ="Tablet", dosageForm3 ="Capsule", dosageForm4 ="Ointment", dosageForm5 ="Tablet";
	string dosageForm6 ="Vial", dosageForm7 ="Tablet", dosageForm8 ="Vaginal", dosageForm9 ="Ampoules";
	
	string activeIng1 ="Acetaminophen",       activeIng2 ="Acetaminophen",  activeIng3 ="Nifedipine",  activeIng4 ="Clioquinol",  activeIng5 ="Esoprazole";
	string activeIng6 ="Ampicillin",       activeIng7 ="Orphenadrin",  activeIng8 ="Nonoxynol",  activeIng9 ="Omeprazole";
	float  p1= 13.00,               p2= 25.25,          p3= 10.00,          p4= 4.10, p5= 52.66, p6= 12.00, p7= 6.25, p8= 21.75, p9= 41.50;
	
	pr1.setData(name1 , dosageForm1 , activeIng1 , p1);
	pr1.setID(1);
	products.insertEnd(pr1.getId(), pr1);

	
	pr1.setData(name2 , dosageForm2 , activeIng2 , p2);
	pr1.setID(2);
	products.insertEnd(pr1.getId(), pr1);
	
	pr1.setData(name3 , dosageForm3 , activeIng3 , p3);
	pr1.setID(3);
	products.insertEnd(pr1.getId() , pr1);
	
	pr1.setData(name4 , dosageForm4 , activeIng4 , p4);
	pr1.setID(4);
	products.insertEnd(pr1.getId(), pr1);
	
	pr1.setData(name5 , dosageForm5 , activeIng5 , p5);
	pr1.setID(5);
	products.insertEnd(pr1.getId(), pr1);
	
	pr1.setData(name6 , dosageForm6 , activeIng6 , p6);
	pr1.setID(6);
	products.insertEnd(pr1.getId(), pr1);

	pr1.setData(name7 , dosageForm7 , activeIng7 , p7);
	pr1.setID(7);
	products.insertEnd(pr1.getId(), pr1);
	
	pr1.setData(name9 , dosageForm9 , activeIng9 , p9);
	pr1.setID(8);
	products.insertEnd(pr1.getId(), pr1);
		
}

void addProducts(int size, Stack<Product> &lastProducts, LinkedList<int, Product>& ls){
	Product temp;
	float  p1= 0.0;
	cout << "--- Adding: "<< size << " products" << " ............" << endl;
	for(int i=0; i<size; i++){
		temp.setProduct();
		ls.insertEnd(i+1, temp);
		temp.display();
		lastProducts.push(temp);
	}
	
}

void viewProducts(LinkedList<int, Product>& ls){
	Product temp;
	if(ls.listIsEmpty()){
		cout << "No products to show!" << endl;
		return;
	}
	
	cout<<endl;
	cout << " View products ......."<< endl;
	cout << " ID  " << "Name" << "\t \t \t"<< "Dosage form"<< "\t \t" << "Active Ing"<< "\t" << "Price"<< endl;
	cout << " ---------------------------------------------------------------------------"<< endl;
	ls.toFirst();
	for(int i = 0; i < ls.listSize(); i++){
		ls.retrieve(temp);
		temp.display();
		ls.advance();
	}
}

void addOrder(LinkedList<int, Product>& ls, Queue<Order> &orderq){
	Order order;
	Product temp;
	int productId;
	int itemSize;
	int quant;
	
	cout << " Add new order ......."<< endl;
	cout<< "---------------------------------" << endl;
	viewProducts(ls);
	cout << "Enter no. of Items: "; cin>>itemSize;
	for(int i=0; i<itemSize; i++){
		cout << "Item no." << i+1<<":"; cin>>productId;
		cout << "Quantity of no." << i+1<<":"; cin>>quant;
		if(ls.search(productId, temp)){
			order.insertNewItem(temp, quant);	
		}else{
			cout << "Item not found!" << endl;
		}
	}
	orderq.enqueue(order);
	cout << "Items has been added...... " <<endl;
	cout << "Total orders " << orderq.returnCount() << endl;
	cout<< "---------------------------------" << endl;
	cout << " Final Order" <<endl;
	order.displayItems();
	
}

void lastProducts(Stack<Product> &lastProducts){
	Product temp; 
	
	while(!lastProducts.topIsNull()){
		lastProducts.retrieveTop(temp);
		temp.display();
		lastProducts.advance();
	}
}

void lastOrders(Stack<Order> &lastOrders){
	Order order; 
	
	while(!lastOrders.topIsNull()){
		lastOrders.retrieveTop(order);
		order.displayItems();
		lastOrders.advance();
	}
}

void deliverOrder(Queue<Order> &notDeliveredOrders){
	Order order;
	cout << " ------ Deliver an order ------- " << endl;
	if(notDeliveredOrders.queueIsEmpty()){
		cout << " ------! No ordered! ------- " << endl;
		cout << " --------------------------------- " << endl;
		return;
	}
	if(!notDeliveredOrders.queueIsEmpty()){
		notDeliveredOrders.dequeue(order);
	}
	
	cout << "Order delivered successfully, order details are below: "<< endl;
	order.displayItems();
}

