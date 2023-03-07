#ifndef CUSTOM_UNIT_TESTS
#define CUSTOM_UNIT_TESTS
// simple preventation from multiple includin

#include "color_codes.h"
// For painting output in beautiful green "OK" and red "FAIL"

static bool __result = false;
static char* __name_of_test = new char[256];

#define __PRINT_RESULT(result) if(result) { printf("[  %sOK%s  ] ", GRN, WHT); } else { printf("[ %sFAIL%s ] ", RED, WHT); } printf("%s\n", __name_of_test);
#define PRINT_RESULT() __PRINT_RESULT(__result);

#define TEST(name) strcpy(__name_of_test, name); __result = [&]() -> bool
#define ENDTEST() (); PRINT_RESULT();

#endif
