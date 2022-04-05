#include <iostream>
#include "linkedlist.h"

/* Functions */
bool list::jump_to(int pos) {
	try {
		if(length == 0 || pos >= length) {
			throw 1;
		} else {
			if(pos < _curIndex) {
				for(pos;pos!=_curIndex;--_curIndex) prev();
			} else if(pos > _curIndex) {
				for(pos;pos!=_curIndex;++_curIndex) next();
			}
		}
	return true;
	} catch(int error) {
		std::cout << "Error: index not found" << std::endl;
		return false;
	}	
}

inline void list::next() {
	if(current -> next != NULL) {
		current = current -> next;
		++_curIndex;
	}
}

inline void list::prev() {
	if(current -> prev != NULL) {
		current = current -> prev;
		--_curIndex;
	}
}

void list::push(int x) {
	if(head) {
		Node *temp = new Node;
		temp -> next = NULL;
		temp -> prev = last;
		temp -> data = x;
		last -> next = temp;
		last = last -> next;
		++_length;
	} else {
		_init(x);
	}
}

void list::push_beg(int x) {
	if(head) {
		Node *temp = new Node;
		temp -> next = head;
		temp -> prev = NULL;
		temp -> data = x;
		head -> prev = temp;
		head = temp;
		++_curIndex;
		++_length;
	} else {
		_init(x);
	}
}

void list::pop() {
	if(last != NULL) {
		last = last -> prev;
		delete last -> next;
		last -> next = NULL;
		--_length;
	}
}

void list::pop_beg() {
	if(head) {
	if(current == head) current = current -> next;
	Node *temp = head -> next;
	delete head;
	head = temp;
	head -> prev = NULL;
	--_length;
	}
}

void list::reset() {
	current = head;
	_curIndex = 0;
}

/* initilizer */
void list::_init(int x) {
	head = new Node;
	head -> data = x;
	head -> next = NULL;
	head -> prev = NULL;
	last = current = head;
	_curIndex = 0;
	_length = 1;
}

/* Constructors */
list::list():curIndex(_curIndex),length(_length) {
	head = NULL;
	last = current = head;
	_curIndex = -1;
	_length = 0;
}

list::list(int x = 9):curIndex(_curIndex),length(_length) {
	_init(x);
}

/* operators */
std::ostream &operator<<(std::ostream &os, list const &m) { 
	if(m.current != NULL)
		return os << m.current -> data;
	else 
		return os;
}

int list::operator =(int val) {		
	return current -> data = val;
}

list::operator ++() {
	if(current -> next != NULL) {
		current = current -> next; 
		++_curIndex;
	}
}