#ifndef GENERAL_HPP
#define GENERAL_HPP


#include <stdio.h>
#include <string.h>
// C libs

#include <iostream>
#include <ncurses.h>
// C++ libs

#include "Cust_Unit_Tests.hpp"
#include "TList.hpp"
#include "Tests.hpp"
#include "Task.hpp"
#include "menu.hpp"

// Custom files

#define DEBUG

#ifdef DEBUG
	#define LOG
#endif

void UpdateFile(FILE* file, const char* path, const char* mode);

#endif
