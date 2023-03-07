#include "../headers/general.hpp"
#include "../headers/Task.hpp"


// Static functions that do routine

static void log(const char* info)
{
#ifdef LOG
	printf(info);
#endif
}

static void log(int data)
{
#ifdef LOG
	printf("%i", data);
#endif
}

static void log(uint32_t data)
{
#ifdef LOG
	printf("%u", data);
#endif
}

static inline unsigned int GetPriorityMask()
{
	return TaskState::MAX_PRIORITY | TaskState::MEDIUM_PRIORITY |
		TaskState::LOW_PRIORITY;
}

static inline unsigned int GetProgressMask()
{
	return TaskState::NOT_DONE | TaskState::IN_PROGRESS |
		TaskState::DONE;
}
static void NullPriority(uint32_t& data)
{
	data = data and (not GetPriorityMask() );
}

static void NullProgress(uint32_t& data)
{
	data = data and (not GetProgressMask() );
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Class functions

Task::Task(const char* description, const uint32_t& data)
{
	this->description = new char[strlen(description)];
	strcpy(this->description, description);

	this->data = data;
}

Task::Task()
{
	this->description = nullptr;
	this->data = this->data | TaskState::NOT_DONE;
}

Task::~Task()
{
	delete[] this->description;
}

char* Task::GetDescription()
{
	return this->description;
}

uint32_t Task::GetPriority()
{
	return this->data & GetPriorityMask();
}	

uint32_t Task::GetProgress()
{
	return this->data & GetProgressMask();
}

void Task::SetProgress(uint32_t progress_code)
{
	NullProgress(this->data);

	progress_code = progress_code & GetProgressMask();

	this->data = this->data | progress_code;
}

void Task::SetPriority(uint32_t priority_code)
{
	NullPriority(this->data);

	priority_code = priority_code & GetPriorityMask();
	// just to make sure that we'll get ONLY priority with data
	
	this->data = this->data | priority_code;
}
