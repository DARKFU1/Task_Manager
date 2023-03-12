#include "../headers/Cust_Unit_Tests.hpp"

void PrintLoadingAnimation(int tabs_count, bool* is_test_done, char** name)
{
	std::thread loading_animation([](int tabs_count, bool* is_test_done, char** name)
	{

		uint8_t tick = 0x00;

		const char* buffer = *name;
		
		while(!(*is_test_done))
		{
			++tick;

			for(int i = 0; i < tabs_count; ++i) { printf("    "); }

			if(tick % 4 == 1) { printf("/"); }
			if(tick % 4 == 2) { printf("-"); }
			if(tick % 4 == 3) { printf("\\"); }
			if(tick % 4 == 0) { printf("|"); }

			printf("  %s\r", *name);

			std::cout.flush();

			std::this_thread::sleep_for(std::chrono::milliseconds(125));

			if(buffer != *name) { break; }
		}
	}, tabs_count, is_test_done, name);

	loading_animation.detach();

	return;
}
