#include "../headers/general.hpp"

inline int Sum(const int& a, const int& b)
{
	return a + b;
}

int main(int argc, char** argv)
{
	std::cout.flush();

	for(int i = 0; i < argc; ++i)
	{
		if(!strcmp(argv[i], "--test")) // if argv[i] == "--test"
		{
			TEST("List adding and getting element")
			{
				TList<int> tl(1);
				tl.Add(2);

				return tl[0] == 1 && tl[1] == 2;
			}ENDTEST();
			
			TEST("List removing element")
			{
				TList<int> tl;
				tl.Add(0);
				tl.Add(1);

				tl.Remove(0);
				return tl.Get(0) == 1;
			}ENDTEST();
		}// unit tests were here.
	}

	TList<int> a;
	a.Add(1);	

	return 0;
}
