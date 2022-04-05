#include <iostream>
#include <string>
#include <windows.h>
#include "menu.h"

void menu::add_option(std::string str) {
	items.push_back(str);
}

void menu::show() {
	int option = 0;
	for(std::vector<std::string>::iterator it = items.begin(); it != items.end();++it,++option) {
		std::cout << "  ";
		std::cout << *it << std::endl;
	}
}
/* 37 left
** 38 up
** 39 right
** 40 down
**/
short menu::move() {
	static short last_selected = -1;
	static mouse_rc mouse;
	mouse.L_btn = 0;
	mouse.Change = 0;
	static char key;
	key = '\0';
	
	event_handeler(&key,&mouse);
	if(mouse.Change) {
		if(mouse.Y < items.size()) _selected = mouse.Y;
	} else if(key == 38) {
		if(_selected != 0) --_selected;
	} else if(key == 40) {
		if(_selected != (items.size()-1)) ++_selected;
	} else if(key == 13 || mouse.L_btn) {
		return 0;
	}
	
	if(last_selected != _selected) {
		for(int i = 0; i != items.size(); ++i) {
			unhighlight(0,i,20);
		}
		highlight(0,_selected,20);
		last_selected = _selected;
	}
	return 1;
}

inline void menu::highlight(short x,short y,short len) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cords = {x,y};
	DWORD out;
	FillConsoleOutputAttribute(hout,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED,len,cords,&out);
}

inline void menu::unhighlight(short x,short y,short len) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cords = {x,y};
	DWORD out;
	FillConsoleOutputAttribute(hout,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED,len,cords,&out);
}

inline void menu::gotoXY(const short X,const short Y) {
	static HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	static COORD cursor;
	cursor.X = X;
	cursor.Y = Y;
	SetConsoleCursorPosition(hOutput,cursor);
}

inline void menu::event_handeler(char *key,menu::mouse_rc *mouse) {
	static HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	static DWORD events;
	static INPUT_RECORD eventbuffer;
	events = 0;
	PeekConsoleInput(handle,&eventbuffer,1,&events);
	if(events > 0) {
		ReadConsoleInput(handle,&eventbuffer,1,&events);
		switch(eventbuffer.EventType) {
			case KEY_EVENT:
					*key = keypress(eventbuffer.Event.KeyEvent); 
				break;
			case MOUSE_EVENT:
					mousemove(eventbuffer.Event.MouseEvent,mouse);
				break;
		}
	}
}

inline char menu::keypress(KEY_EVENT_RECORD event) {
		if(event.bKeyDown) {
			return event.wVirtualKeyCode;
		}
	return '\0';
}

inline void menu::mousemove(MOUSE_EVENT_RECORD event,menu::mouse_rc *ret) {
	if(event.dwEventFlags == MOUSE_MOVED) {
		ret -> Change = 1;
		ret -> X = event.dwMousePosition.X;
		ret -> Y = event.dwMousePosition.Y;
	}
	if(event.dwEventFlags == 0) {
		if(event.dwButtonState == 1) {
			ret -> L_btn = 1;
		}
	}
}

menu::menu():_selected(0),selected(_selected) {}