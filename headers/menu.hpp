#ifndef MENU_HPP
#define MENU_HPP

#include "general.hpp"
#define FOREVER() for(;;)

class menu
{
protected:
	int cursor_position;
	int count;
	char** options;

public:
	virtual int Start();
	menu(int count, ...);

	menu();
};

#endif
