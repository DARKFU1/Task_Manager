#ifndef MENU_HPP
#define MENU_HPP

#include "general.hpp"
#define FOREVER() for(;;)

class menu
{
	int cursor_position;
	int count;
	char** options;

public:
	menu(int count, ...);
	int Start();
};

#endif
