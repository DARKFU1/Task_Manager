#include "../headers/general.hpp"

#define UPDATE_FILE(file, path, mode) fclose(path); file = fopen(path, mode);

int main(int argc, char** argv)
{
	for(int i = 0; i < argc; ++i)
	{
		if(!strcmp(argv[i], "--test")) 
		{
			LaunchUnitTests();
			LaunchIntegrationTests();

			return 0;
		}

		if(!strcmp(argv[i], "-t"))
		{
			LaunchUnitTests();
			LaunchIntegrationTests();

			return 0;
		}
	}

	initscr();

	start_color();

	menu UI(1, "Exit.");
	
	int result = UI.Start();

	endwin();

	return 0;
}
