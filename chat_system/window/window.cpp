#include "window.h"
#include <string.h>
window::window()
{
	initscr();
	curs_set(0);
}

void window::drawHeader()
{
	int h = LINES/5;
	int w = COLS;
	int y = 0;
	int x = 0;
	header = newwin(h, w, y, x);
	box(header, '.', '.');
}

void window::drawOutput()
{
	int h = (LINES*3)/5;
	int w = (COLS*3)/4;
	int y = LINES/5;
	int x = 0;
	output = newwin(h, w, y, x);
	box(output, '*', '.');
}

void window::drawFlist()
{
	int h = (LINES*3)/5;
	int w = COLS/4;
	int y = LINES/5;
	int x = (COLS*3)/4;
	flist = newwin(h, w, y, x);
	box(flist, '.', '.');
}
void window::drawInput()
{
	int h = LINES/5;
	int w = COLS;
	int y = (LINES*4)/5;
	int x = 0;
	input = newwin(h, w, y, x);
	box(input, '.', '.');
}

void window::putStrToWin(WINDOW *w, int y, int x, std::string &str)
{
	mvwaddstr(w, y, x, str.c_str());
}

void window::getStrFromWin(WINDOW *w, std::string &outString)
{
	char buf[1024];
	wgetnstr(w, buf, sizeof(buf));
	outString = buf;
}

void window::clrWinNums(WINDOW *w, int begin, int nums)
{
	while(nums-- > 0){
		wmove(w, begin++, 0);
		wclrtoeol(w);
	}
}

window::~window()
{
	delwin(header);
	delwin(output);
	delwin(flist);
	delwin(input);
	endwin();
}

//int main()
//{
//	window w;
//
//
//
//	return 0;
//}










