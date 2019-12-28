//This is written by Mustafa Hesham Mohamed.
//My code at FSSR is 20180378.
//This is the stack.h file.

#ifndef STACK_H
#define STACK_H

template <class D>
class Stack
{
	typedef Stack* sptr;
	
	private:
		
		D data;
		sptr top;
		sptr next;
		
	public:
		
		Stack();
		push(D d);
		pop();
		retrieveTop(D &);
		advance();
		bool isEmpty() const;
		bool topIsNull() const;
		
	protected:
};
#include "stack.cpp"
#endif
