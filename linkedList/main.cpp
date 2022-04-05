#include <iostream>
#include "linkedlist.h"

void printAll(list &mylist) {
	mylist.reset();
	do {
		++mylist;
		std::cout << "Element : " << mylist << std::endl;
	} while(mylist.curIndex < mylist.length-1);
}

int main() {
	list mylist;
	std::cout << "Value of mylist is : " << mylist << std::endl;
	mylist.push(1);
	mylist.push(2);
	mylist.push_beg(0);
	std::cout << "Total Element's are : " << mylist.length << std::endl;
	std::cout << "Element's of current linked list : " << std::endl;
	printAll(mylist);
	mylist.reset();
	mylist.jump_to(3);
	std::cout << "current item : " << mylist << std::endl;
	std::cout << "current item no : " << mylist.curIndex << std::endl;
	std::cin.ignore();
	return 0;
}
