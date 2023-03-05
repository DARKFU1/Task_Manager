#include "../headers/general.hpp"

inline int Sum(const int& a, const int& b)
{
	return a + b;
}

int main(int argc, char** argv)
{
	for(int i = 0; i < argc; ++i)
	{
		if(!strcmp(argv[i], "--test")) // if argv[i] == "--test"
		{
			printf("[Unit tests]\n\n");

			TEST("Example")
			{
				return Sum(2, 2) == 4;
			}ENDTEST()

			printf("\n[End of unit tests];\n\n");
		}// unit tests were here.
	}

	return 0;
}
