#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <iostream>
#include <ncurses.h>

class window{
	public:
		window();
		void drawHeader();
		void drawOutput();
		void drawFlist();
		void drawInput();
		void putStrToWin(WINDOW *w, int y, int x, std::string &str);
		void getStrFromWin(WINDOW *w, std::string &outString);
		void clrWinNums(WINDOW *w, int begin, int nums);
		~window();
	public:
		WINDOW *header;
		WINDOW *output;
		WINDOW *flist;
		WINDOW *input;
};

#endif
