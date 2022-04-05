#include <iostream>
#include <windows.h>
#include "tree.h"
#include "menu.h"

using namespace std;

inline void input_wait() {
	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD events;
	INPUT_RECORD eventbuffer;
	SetConsoleMode(handle, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while(1) {
		PeekConsoleInput(handle,&eventbuffer,1,&events);
		if(events > 0) {
			ReadConsoleInput(handle,&eventbuffer,1,&events);
			switch(eventbuffer.EventType) {
				case KEY_EVENT:
						if(eventbuffer.Event.KeyEvent.bKeyDown) return; 
					break;
				case MOUSE_EVENT:
						if(eventbuffer.Event.MouseEvent.dwButtonState) return;
					break;
			}
		}
	}
}

void cursor_on(bool visibility) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 10;
    info.bVisible = visibility;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void enter_elements(tree *obj) {
	system("cls");
	cursor_on(true);
	short max;
	int num;
	cout << "Enter No of Elements" << endl;
	cin >> max;
	cout << "Enter Elements : " << endl;
	for(int i =0; i< max; ++i) {
		cin >> num;
		obj -> push(num);
	}
	cout << "All Elements Entred Sucessfully" << endl;
	input_wait();
}

void print_elements(tree *obj) {
	system("cls");
	cursor_on(true);
	cout << "Result : " << endl;
	cout << "\nPreOrder : " << endl;
	obj -> print(obj -> pre);
	cout << "\nInOrder : " << endl;
	obj -> print(obj -> in);
	cout << "\nPostOrder : " << endl;
	obj -> print(obj -> post);
	input_wait();
}

void search_element(tree *obj) {
	system("cls");
	cursor_on(true);
	int num;
	tree::holder *holder;
	cout << "Enter a Number" << endl;
	cin >> num;
	holder = obj -> search(num);
	if(holder != NULL) cout << "found " << holder -> data << endl;
	else cout << "Value not found " << endl;
	input_wait();
}

void delete_element(tree *obj) {
	system("cls");
	cursor_on(true);
	int num;
	cout << "Enter a number to delete" << endl;
	cin >> num;
	obj -> pop(num);
	cout << "Element Deleted Sucessfully" << endl;
	input_wait();
}

void delete_all(tree *obj) {
	system("cls");
	cursor_on(true);
	obj -> reset();
	cout << "All Elements Deleted" << endl;
	input_wait();
}

void tree_info(tree *obj) {
	system("cls");
	cursor_on(true);
	cout << "Height of the tree is " << obj -> getheight() << endl;
	obj -> show_whole(2);
	input_wait();
}

int main() {
	tree obj;
	menu menu;
	int max = 0,num = 0;
	DWORD oldmode;
	HANDLE inphandle = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(inphandle, &oldmode);
	
	SetConsoleTitle("Tree Manipulation");
	
	menu.add_option("Enter Elements");
	menu.add_option("Print Elemets");
	menu.add_option("Search Element");
	menu.add_option("Delete Element");
	menu.add_option("Delete All");
	menu.add_option("Tree Info");
	menu.add_option("Exit");
	do {
		cursor_on(false);
		system("cls");
		SetConsoleMode(inphandle, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | GENERIC_WRITE);
		menu.show();
		while(menu.move());
		if(menu.selected == 0) enter_elements(&obj);
		if(menu.selected == 1) print_elements(&obj);
		if(menu.selected == 2) search_element(&obj);
		if(menu.selected == 3) delete_element(&obj);
		if(menu.selected == 4) delete_all(&obj);
		if(menu.selected == 5) tree_info(&obj);
		if(menu.selected == 6) break;
	} while(1);
	SetConsoleMode(inphandle,oldmode);
	return 0;
}