/**
* Queue based linkedList implementation file
* Name: Taha Elsenosy Mohamed <tahaelsenosy@gmail.com>
* Date: Dec, 16 2019
* Course: CS505
* File: queueL.cpp
*/
#ifndef QUEUE_IMP 
#define QUEUE_IMP
#include "queueL.h"
#include <iostream>
#include <string>

using namespace std;

#define print(x) cout<<x
#define printn(x) cout<<x<<endl;

template <class D>
Queue<D>::Queue()
{
	front = NULL;
	rear = NULL;
	count = 0;
}

template <class D>
Queue<D>::enqueue(const D &d)
{
	ptr temp = new Queue();
	temp->data = d;
	if (queueIsEmpty())
	{
		front = temp;
		rear = temp;
		front->next = NULL;
	}
	else if (!queueIsEmpty())
	{
		rear->next = temp;
		rear = temp;
		rear->next == NULL;
	}
	count++;
}

template <class D>
bool Queue<D>::queueIsEmpty() const
{
	return (count == 0);
}

template <class D>
bool Queue<D>::frontIsEmpty() const
{
	return (front == NULL);
}

template <class D>
D Queue<D>::returnFront()
{
	return front->data;
}

template <class D>
Queue<D>::dequeue(D& d)
{
	if (queueIsEmpty())
	{
		printn("The queue is empty!")
		
	}
	else if (!queueIsEmpty())
	{
		ptr temp;
		temp = front;
		d = temp->data;
		front = front->next;
		delete temp;
	}
	
	count--;
}

template <class D>
int Queue<D>::returnCount()
{
	return count;
}

template <class D>
D Queue<D>::pop()
{
	D xt;
	ptr temp;
	temp = front;
	if (queueIsEmpty())
	{
		print("\n\n");
		printn("Queue is Empty!");
	}
	else
	{
		while (temp->next != rear && temp->next != NULL)
		{
			temp = temp->next;
		}
	
		xt = rear->data;
		rear = temp;
		temp = temp->next;
		rear->next = NULL;
		delete temp;
		count--;
		return xt;
	}
	
}

template<class D>
Queue<D>::Split(Queue h, Queue &h1, Queue &h2)
{
	ptr temp;
	h.atFirst(temp);
	
	while(!h.returnPtrNull(temp))
	{
		if (h.returnCur(temp) % 2 != 0)
		{	
			h1.enqueue(h.returnCur(temp));	
		}
		
		else
		{
			h2.enqueue(h.returnCur(temp));
		}

		h.Advance(temp);
	}

}

template<class D>
Queue<D>::atFirst(ptr &p)
{
	p = front;
}

template<class D>
Queue<D>::Advance(ptr &p)
{
	p = p->next;
}

template<class D>
D Queue<D>::returnCur(ptr &p)
{
	return p->data;
}

template<class D>
bool Queue<D>::returnPtrNull(ptr &p)
{
	return (p == NULL);
}

template <class D>
Queue<D>::splitByValue(Queue h, Queue &h1, Queue &h2)
{
	D xr;
	while (!h.queueIsEmpty())
	{
		h.dequeue(xr);
		if (xr % 2 != 0) 
		{
			h1.enqueue(xr);
		}
		else 
		{
			h2.enqueue(xr);
		}
	}
}
#endif

