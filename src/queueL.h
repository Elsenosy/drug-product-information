/**
* Queue based linkedList header file
* Name: Taha Elsenosy Mohamed <tahaelsenosy@gmail.com>
* Date: Dec, 16 2019
* Course: CS505
* File: queueL.h
*/
#ifndef QUEUE_H
#define QUEUE_H


template <class D>
class Queue
{
	typedef Queue* ptr;
	
	private:
		
		D data;
		ptr front;
		ptr rear;
		ptr next;
		int count;
		
	public:
		
		Queue();
		enqueue(const D &d);
		dequeue(D& d);
		bool queueIsEmpty() const;
		bool frontIsEmpty()const;
		D returnFront();
		int returnCount();
		D pop();
		Split(Queue h, Queue &h1, Queue &h2);
		atFirst(ptr &p);
		Advance(ptr &p);
		D returnCur(ptr &p);
		bool returnPtrNull(ptr &p);
		splitByValue(Queue h, Queue &h1, Queue &h2);
		
	protected:
};

#include "queueL.cpp"
#endif
