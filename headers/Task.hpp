// A simple data struct that holds data of the task.

#ifndef TASK_HPP
#define TASK_HPP

#include "general.hpp"

// enum of state that Task.data can hold
enum TaskState
{
	MAX_PRIORITY = 1,	// 1b ( in binary-number)
	MEDIUM_PRIORITY = 2,	// 10b
	LOW_PRIORITY = 4, 	// ...	
				// 1000b - 10000b reserved
	DONE = 64,
	IN_PROGRESS = 128,
	NOT_DONE = 256,
};



class Task
{
	char* description;
	uint32_t data;
public:
	Task(const char* description, const uint32_t& data); // allocates memory

	char* GetDescription();	// returns pointer, value can be changed
	uint32_t GetPriority();	// returns one of priority codes ( pre-defined )
	uint32_t GetProgress(); // returns one of state codes ( pre-defined )

	void SetProgress(uint32_t progress_code); // codes are pre-defined 
	void SetPriority(uint32_t priority_code); // codes are pre-defined
	
	~Task();// clears memory allocated by description
	Task();	// default constructor, data has to be changed by coder's hands 

};

#endif
