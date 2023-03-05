About TList.

This is my realisation of simple forward-list.

It supports such operations as:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* deletion
* adding element
* getting element

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Yeah, not very much.

-------------------------------------------------------------------------------
Remove function has some specific checks for condition that are exceptional, but
usually it works like that:

1. Find previous node
2. Get next node( next after the one that will be deleted )
3. delete the node
4. Assign to previous-\>pNext value of next

--------------------------------------------------------------------------------

Adding function is even more simple:

1. Find the last element
2. Assign last\_element-\>pNext new value.

--------------------------------------------------------------------------------

Getting is EVEN MORE Simple

1. Find the element.
2. Return It's value.

--------------------------------------------------------------------------------

I can't say anything special about constructors or destructors. They just work.
