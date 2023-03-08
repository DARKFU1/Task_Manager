#include "../headers/general.hpp"

int main(int argc, char** argv)
{
	for(int i = 0; i < argc; ++i)
	{
		if(!strcmp(argv[i], "--test")) 
		{
			LaunchUnitTests();
			LaunchIntegrationTests();
		}

		if(!strcmp(argv[i], "-t"))
		{
			LaunchUnitTests();
			LaunchIntegrationTests();
		}
	}

	return 0;
}
