#ifndef CUSTOM_UNIT_TESTS
#define CUSTOM_UNIT_TESTS
// simple preventation from multiple includin

#include "color_codes.h"
// For painting output in beautiful green "OK" and red "FAIL"

#include "general.hpp"

static auto start = std::chrono::high_resolution_clock::now();
static auto finish = std::chrono::high_resolution_clock::now();

static int __tabs_count = 0;
static bool __result = false;
static char* __name_of_test = nullptr;
static bool __is_done = true;

void PrintLoadingAnimation(int tabs_count, bool* is_done, char** name);


#define __START_TIME() start = std::chrono::high_resolution_clock::now();
#define __FINISH_TIME() finish = std::chrono::high_resolution_clock::now();
#define __PRINT_TIME() __PRINT_TABS_UNTIL_END_OF_SCREEN(); printf("| time: %d us", std::chrono::duration_cast<std::chrono::microseconds>(finish - start))

#define __PRINT_TABS() for(int i = 0; i < __tabs_count; ++i) { printf("   "); }
#define __CALCULATE_TABS_UNTIL_END_OF_SCREEN(name) (80 - 4 * __tabs_count - strlen(name)) / 8
#define __PRINT_TABS_UNTIL_END_OF_SCREEN() for(int i = 0; i < __CALCULATE_TABS_UNTIL_END_OF_SCREEN(__name_of_test) - 3; ++i) { printf("\t"); }

#define ADD_LAYER(name) printf("\n"); __PRINT_TABS(); printf("%s\n", name); __tabs_count += 1;
#define END_LAYER() printf(""); __tabs_count -= 1;

#define __PRINT_LOADING_ANIMATION() PrintLoadingAnimation(__tabs_count, &__is_done, &__name_of_test);
#define __PRINT_RESULT(result) if(result) { printf("[  %sOK%s  ] ", GRN, WHT); } else { printf("[ %sFAIL%s ] ", RED, WHT); } printf("%s\t", __name_of_test); __PRINT_TIME(); printf("\n");
#define PRINT_RESULT() __PRINT_TABS(); __PRINT_RESULT(__result);

#define TEST(name) __is_done = false; __name_of_test = name; __PRINT_LOADING_ANIMATION(); __START_TIME() __result = [&]() -> bool
#define ENDTEST() ();__FINISH_TIME(); __is_done = true;  PRINT_RESULT();

#endif
