#include "../headers/general.hpp"
#include "../headers/menu.hpp"

menu::menu(int count, ...)
{
	this->count = count;

	this->cursor_position = 0;

	this->options = new char*[count];

	va_list args;

	va_start(args, count);

	for(int i = 0; i < count; ++i)
	{
		this->options[i] = new char[128];
		strcpy(this->options[i], va_arg (args, const char*));
	}

	va_end(args);
}

constexpr int highlighted_color = 1;
constexpr int default_color = 0;

int menu::Start()
{
	char input;

	int y_max, x_max;
	getmaxyx(stdscr, y_max, x_max);

	cbreak();
	noecho(); // no symbols echo

	start_color();

	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	// pairs for un- and selected strings

	FOREVER()
	{	
		clear();

		for(int i = 0; i < count; ++i)
		{
			move(y_max - 2 - count + i, 0); // in the end of screen

			if(i == cursor_position)
			{
				attron(COLOR_PAIR(1));

				printw("%s\n", options[i]);
			
				attroff(COLOR_PAIR(1));

				move(0,0);
				continue;
			}

			printw("%s\n", options[i]);
			move(0, 0);
		}

		refresh();
		
		input = getch();

		if(input == '\n' || input == '\r') 
		{
			break;
		}

		if(input == 'a' || input == 'h') {}
		if(input == 'd' || input == 'l') {}
		if(input == 'w' || input == 'k')
	       	{
			if(cursor_position > 0) --cursor_position;
		}
		
		if(input == 's' || input == 'j')
	       	{
			if(cursor_position < count - 1) ++cursor_position;
		}
	}

	echo();
	nocbreak();

	clear();

	return count;
}

menu::menu() // default ctor
{
	this->options = nullptr;
	this->cursor_position = 0;
	this->count = 0;
}	
