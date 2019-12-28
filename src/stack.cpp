//This is written by Mustafa Hesham Mohamed.
//My code at FSSR is 20180378.
//This is the stack.cpp file.

#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

template <class D>
Stack<D>::Stack()
{
	top = NULL;
}


template <class D>
bool Stack<D>::topIsNull() const
{
	return (top == NULL);
}
	
template <class D>
bool Stack<D>::isEmpty() const
{
	return topIsNull();
}


template <class D>
Stack<D>::push(D d)
{
	sptr temp = new Stack<D>();
	temp->data = d;
	temp->next = top;
	top = temp;
}

template <class D> 
Stack<D>::retrieveTop(D &d){
	if(!isEmpty()){
		d = top->data;
	}
}

template <class D> 
Stack<D>::advance(){
	sptr temp = top;
	while(!isEmpty()){
		temp = temp->next;
	}
}


template <class D>
Stack<D>::pop()
{
	D xt;
	sptr temp;
	if (isEmpty()) cout<<"Stack is empty!"<<endl;
	else
	{
		xt = top->data;
		temp = top;
		top = top->next;
		delete temp;
		cout<<xt;
	}
}
