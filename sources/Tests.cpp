#include "../headers/Tests.hpp"

void LaunchUnitTests()
{
	printf("--------------------------------\n");
	printf("	Unit Tests		\n");
	printf("--------------------------------\n\n");

	/// tests under that line.
	//
	TEST("List adding and getting element")
	{
		TList<int> tl;
		tl.Add(1);
		tl.Add(2);

		return tl[0] == 1 && tl[1] == 2;
	}ENDTEST();
	
	TEST("List removing element")
	{
		TList<int> tl;
		tl.Add(8);
		tl.Add(9);

		tl.Remove(0);

		return tl.Get(0) == 9;
	}ENDTEST();

	/// tests higher this line.
	
	printf("\n--------------------------------\n");
	printf("      Unit Tests Are Done!	\n");
	printf("--------------------------------\n\n");
}
