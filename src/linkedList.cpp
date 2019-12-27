/**
    CS505 sheet
    linkedList.cpp
    Purpose: Linked list implementation

    @author Taha Elseosy <tahaelseosy@gmail.com>
*/
#ifndef LINKEDLIST_IMP____
#define LINKEDLIST_IMP____
#include "linkedList.h"
#include <iostream>
using namespace std;

// Constructor
template <class keyType, class dataType> LinkedList<keyType, dataType>::LinkedList(){
	head = NULL; cursor = NULL; prev = NULL;	
}

// Check if list is empty!
template <class keyType, class dataType> bool LinkedList<keyType, dataType>::listIsEmpty() const{
	return head == NULL ? true : false;
}

// Insert at the first
template <class keyType, class dataType> void LinkedList<keyType, dataType>::insertFirst(const keyType &key, const dataType &data){
	Node *node = new Node;
	node->key = key;
	node->data = data;
	node->next = head;
	
	head = node;
	cursor = head;
	prev = NULL;
}
// Insert before a node
template <class keyType, class dataType> void LinkedList<keyType, dataType>::insertAfter(const keyType &key, const dataType &data){
	toFirst();
	Node *q = new Node;
	Node *tmp = new Node;
	if(!listIsEmpty()){
		while(cursor != NULL){
			if(cursor->key == key){
				q->key = cursor->key;
				q->data = data;

				prev = cursor;
				q->next = cursor->next;
				cursor->next = q;
				cursor = q;
				break;
			}
			advance();
		}
	}
}

template <class keyType, class dataType> void LinkedList<keyType, dataType>::insertEnd(const keyType &key, const dataType &data){
	NodePointer p = new Node;
	
	toFirst();
	while(!curIsEmpty()){
		if(cursor->next == NULL){
			p->key = key;
			p->data = data;
			
			cursor->next = p;
			p->next = NULL;
			prev = cursor;
			cursor = p;
			break;
		}
		advance();
	}
}

// Retrieve node
template <class keyType, class dataType> void LinkedList<keyType, dataType>::retrieve(dataType &pr) const{
	pr = cursor->data;
}

// Check if list is empty or not
template <class keyType, class dataType> bool LinkedList<keyType, dataType>::curIsEmpty() const{
	return cursor == NULL ? true : false;
}
// Move the cursor to the front of the list
template <class keyType, class dataType> void LinkedList<keyType, dataType>::toFirst(){
	cursor = head; prev = NULL;
}

// Check if the cursro at the first
template <class keyType, class dataType> bool LinkedList<keyType, dataType>::atFirst() const{
	return cursor == head ? true : false;
}

// Move the cursor one move forward
template <class keyType, class dataType> void LinkedList<keyType, dataType>::advance(){
	prev = cursor; cursor = cursor->next;
}

// Move the cursor to the last element in the list
template <class keyType, class dataType> void LinkedList<keyType, dataType>::toEnd(){
	toFirst();
	if(!listIsEmpty()){
		while(!curIsEmpty())
			advance();
	}
}

template <class keyType, class dataType> void LinkedList<keyType, dataType>::displayAllInt(){
	toFirst();
	while(!curIsEmpty()){
		cout << "key: "<< cursor->key<<endl;
		cout << "Data: "<< cursor->data << endl;
		cout << " --- "<<endl;
		advance();
	}
}

// Check if the cursor at the last element or not
template <class keyType, class dataType> bool LinkedList<keyType, dataType>::atEnd() const{
	return cursor->next == NULL ? true : false;
}

// Return the list size
template <class keyType, class dataType> int LinkedList<keyType, dataType>::listSize() const{
	int counter = 0;
	Node *p = new Node;
	p = head;
		while(p != NULL){
			counter++;
			p = p->next;	
		}
	
	return counter;
}

// Delete the cursor node
template <class keyType, class dataType> void LinkedList<keyType, dataType>::deleteNode(){
	Node *q = new Node;
	
	if(!curIsEmpty()){
		q = cursor->next;
		delete cursor;
		cursor = q;
	}
	
}

// Empty the whole list
template <class keyType, class dataType> void LinkedList<keyType, dataType>::makeListEmpty(){
	if(!listIsEmpty()){
		while(cursor != NULL){
			delete cursor;
			advance();
		}
	}
}

template <class keyType, class dataType> LinkedList<keyType, dataType>::~LinkedList(){
	makeListEmpty();
}
#endif

