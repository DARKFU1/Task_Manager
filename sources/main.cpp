#include "../headers/general.hpp"

int Sum(const int& a, const int& b)
{
	return a + b;
}

int main(int argc, char** argv)
{
	TEST("Sum of two numbers")
	{
		return Sum(2, 2) == 4;
	}ENDTEST()

	return 0;
}
