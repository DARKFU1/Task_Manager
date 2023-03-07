#include "../headers/general.hpp"

int main(int argc, char** argv)
{
	for(int i = 0; i < argc; ++i)
	{
		if(!strcmp(argv[i], "--test")) 
		{
			LaunchUnitTests();
		}

		if(!strcmp(argv[i], "-t"))
		{
			LaunchUnitTests();
		}
	}

	TList<int> a;
	a.Add(1);	

	return 0;
}
