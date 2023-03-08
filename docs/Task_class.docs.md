This file contains information about the `Task` class

--------------------------------------------------------------------------------

It is a simple data struct that can only hold two variables:
`description` of type const char\*
and
`data` of type uint32_t that holds binary data.


`description` is just a string, that describes the task.

`data` however, holds both priority and progress of the task.

NOTE: values of different priorities and progress are defined in enum in
`headers/Task.hpp`

Methods with which we are going to communicate with the object are simple:

`GetDescription()` returns pointer to the description of the task, that can be changed.

`GetProgress()` returns progress code that is defined in enum.
`GetPriority()` returns priority code that is defined in enum.

`SetPriority()` takes priority code and rewrites this field in the class.
`SetProgress()` takes progress code and rewrites this field in the class.

The overloaded comparation operators ( >, < ) compare priorities of the objects.

--------------------------------------------------------------------------------

Operator '=' has been overloaded. So copy ctor has.

Two new operations: WriteToFile(file ptr) and ctor that takes file as argument

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
WriteToFile(FILE\* data_file)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Puts data in the file. After that you can open this file in read mode and put it
in the ctor.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
File(FILE\* data_file);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

And it will read the data from file and write it into itself.
