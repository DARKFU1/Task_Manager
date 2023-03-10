#ifndef GENERAL_HPP
#define GENERAL_HPP


#include <stdio.h>
#include <string.h>
// C libs

#include <iostream>
// C++ libs

#include "Cust_Unit_Tests.hpp"
#include "TList.hpp"
#include "Tests.hpp"
#include "Task.hpp"
// Custom files

#define DEBUG

#ifdef DEBUG
	#define LOG
#endif

void UpdateFile(FILE* file, const char* path, const char* mode);

#endif
