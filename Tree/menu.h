#include <iostream>
#include <vector>
#include <windows.h>

#ifndef _menu_
#define _menu_
class menu {
	std::vector<std::string> items;
	int _selected;
	struct mouse_rc {
		short X;
		short Y;
		bool L_btn;
		bool R_btn;
		bool Change;
	};
		void event_handeler(char*,mouse_rc *);
		char keypress(KEY_EVENT_RECORD);
		void mousemove(MOUSE_EVENT_RECORD,mouse_rc *);
		void gotoXY(const short,const short);
		void highlight(short,short,short);
		void unhighlight(short,short,short);
	public:
	const int &selected;
		void add_option(std::string);
		void show();
		short move();
	menu();
};
#endif