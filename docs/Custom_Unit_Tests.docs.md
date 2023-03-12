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
}(); PRINT_RESULT()

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--------------------------------------------------------------------------------
NOTE:
	Right now there's a function that calls all unit tests declared in
	`headers/Tests.hpp` file and defined in 'sources/Tests.cpp"

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// headers/Tests.hpp
	
void LaunchUnitTests();
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--------------------------------------------------------------------------------

NOTE(1):
	Recently function for integration tests has been added.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// headers/Tests.hpp

void LaunchIntegrationTests();
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

It also calls automaticly.
	
--------------------------------------------------------------------------------

UPDATE:

* Added Layers functionality.

If you use `ADD_LAYER(name)` and `END_LAYER()` macros:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ADD_LAYER("Unit Tests")
	ADD_LAYER("Example")
		TEST("EXAMPLE TEST") { return true; }ENDTEST();
	END_LAYER();
END_LAYER();
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

You'll have a beautiful UI like that:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Unit Tests
	Example
		[  OK  ] EXAMPLE TEST				| time: time us
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

By the way, you've just seen the new feature: time.
It is done with `std::chrono`, so it's not 100% accurate, but I guess that'll work
NODE: us = microseconds.

Another feature is animation when function takes a lot of time to execute, you'll
see that when you're gonna need that.
