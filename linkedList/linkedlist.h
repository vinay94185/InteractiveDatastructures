#include <cstddef>
#include <iostream>

#ifndef _LINKLIST_H
#define _LINKLIST_H
class list {
		struct Node {
			int data;
			Node *next;
			Node *prev;
		};
		Node *head;
		Node *current;
		Node *last;
		int _curIndex;
		int _length;
		void _init(int);
	public:
		const int &curIndex;
		const int &length;
		
		friend std::ostream &operator<<(std::ostream &os, list const &m);
		int operator =(int val);
		int operator ++();
		
		void next();
		void prev();
		void push(int);
		void push_beg(int);
		void pop();
		void pop_beg();
		void reset();	
		bool jump_to(int);
	
	list();
	list(int);
};
#endif