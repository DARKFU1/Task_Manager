|| This file contains information about expected UI that will be debeloped    ||
|| with Ncurses library.						      ||

So, the UI will look like this:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			HIGH_PRIORITY (N)
[ PROGRESS ] Task example
...

			MEDIUM_PRIORITY(N)
[ PROGRESS ] Task example
...

			LOW_PRIORITY(N)
[ PROGRESS ] Task example
...

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

User can choose the line with task using wasd or "kjl;"(vim keys).
Chosen line will be highlighted with using white background and black text.

User can choose status selected of the task( DONE/IN_PROGRESS/NOT_DONE ) using 
'ad' or 'hl' ( keys that are responsible for side movement ).
Status will be changin like that: NOT_DONE -> IN_PROGRESS -> DONE -> DELETE?

`DELETE` status is temporary and asks user "Do you want to delete the task?" and 
if user presses space it will be deleted.

/* There is possibility that I'll do a feature that if user doesn't delete the 
task, it will have status "NOT_DONE" next day. */
