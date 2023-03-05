#ifndef CUSTOM_UNIT_TESTS
#define CUSTOM_UNIT_TESTS
// simple preventation from multiple includin

#include "color_codes.h"
// For painting output in beautiful green "OK" and red "FAIL"

bool __result;
uint8_t __count_of_tabs;
const char* __name_of_test;

#define __PRINT_RESULT(result) if(result) { printf("[  %sOK%s  ] ", GRN, WHT); } else { printf("[ %sFAIL%s ] ", RED, WHT); } printf("%s\n", __name_of_test);
#define PRINT_RESULT() __PRINT_RESULT(__result);

#define TEST(name) __name_of_test = name; __result = [&]() -> bool
#define ENDTEST() (); PRINT_RESULT()

#endif
