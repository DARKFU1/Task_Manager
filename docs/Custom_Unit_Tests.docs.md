Cust_Unit_Tests.h ( located in .../headers/ ) Is header file for writing unit tests.

What it has to offer?

Well, first there are private variables that I would not reccomend to touch.
I'm talking about `__result` and `__name_of_test`.
They are needed for unit tests to function properly.

The way this works:

--------------------------------------------------------------------------------

We have some function that we want to test.
Let's imagine that's the Sum function.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int Sum(int a, int b)
{
	return a + b;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

We expect, that if this function works properly, output of 2 + 2 will be 4
so let's write the test.

Whe test begins with pre-defined "TEST(name)" macro, in which name is the
name of test to be displayed

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
TEST("Sum of 2 numbers")
{
	// we do the stuff here
	
	return Sum(2, 2) == 4;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

if the function works right, the function returns true, otherwise false.
But we are not done yet.

In order for test to even launch we need to write ENDTEST after the definiton

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TEST("Sum of 2 numbers")
{
	// we do the stuff here

	return Sum(2, 2) == 4;
}ENDTEST()

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Now we are done and the test is gonna launch if it is in the right branch of
our code.

--------------------------------------------------------------------------------

		HOW THIS WORKS ON THE SOURCE LEVEL?

TEST macro transfers code that will be written into lambda by replacing it
with "\[&]() -> bool"

ENDTEST macro calls this lambda funcion and prints the data to UI. The function
printf() is used for that, so <stdio.h> is needed.

In the end code above looks like this

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

__name_of_test = "Sum of 2 numbers"; __result = [&]() -> bool
{
	// we do the stuff here

	return Sum(2, 2) == 4;
}() PRINT_RESULT()

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
