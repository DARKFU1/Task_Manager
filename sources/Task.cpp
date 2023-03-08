#include "../headers/general.hpp"
#include "../headers/Task.hpp"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Static functions that do routine

static inline unsigned int GetPriorityMask()
{
	return TaskState::MAX_PRIORITY | TaskState::MEDIUM_PRIORITY |
		TaskState::LOW_PRIORITY;
}

static inline unsigned int GetProgressMask()
{
	return TaskState::NOT_DONE | TaskState::IN_PROGRESS |
		TaskState::DONE | TaskState::DELETE_Q;
}
static void NullPriority(uint32_t& data)
{
	data = data and (not GetPriorityMask() );
}

static void NullProgress(uint32_t& data)
{
	data = data and (not GetProgressMask() );
}

static void FileReadDescription(char* buffer,FILE* data_file)
{
	int symbol_id = 0;
	bool quotes_open = false;
	
	while(true)
	{
		buffer[symbol_id] = getc(data_file);

		if(quotes_open && buffer[symbol_id] == '~') // if end
		{
			buffer[++symbol_id] = '\0';
			break;
		}

		if(!quotes_open && buffer[symbol_id] == '~') // if start
		{
			quotes_open = true;
			continue;
		}

		// else
		++symbol_id;
	}

	return;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Class functions

void Task::WriteToFile(FILE* data_file)
{
	fprintf(data_file, "&data& %u ", this->data);
	fprintf(data_file, "&description& ~%s~\n", this->description);

	// data is presented like that:
	// &data& 65 &desctiption& ~description~
}

Task& Task::operator=(const Task& other)
{
	this->data = other.data;

	this->description = new char[strlen(other.description)];
	strcpy(this->description, other.description);

	return *this;
}

Task::Task(const Task& other)
{
	this->data = other.data;
	
	this->description = new char[strlen(other.description)];
	strcpy(this->description, other.description);
}

Task::Task(FILE* data_file)
{
	this->description = new char[512];

	char buffer[512];

	fscanf(data_file, "%s", buffer);
	if(!strcmp(buffer, "&data&"))
	{
		fscanf(data_file, "%u", &this->data);
		// scan data.
	}

	fscanf(data_file, "%s", buffer);
	if(!strcmp(buffer, "&description&"))
	{
		FileReadDescription(this->description, data_file);
	}
}

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

// compares ONLY priorities
bool Task::operator==(Task& other)
{
	return this->GetPriority() == other.GetPriority();
}

// compares ONLY priorities
bool Task::operator>(Task& other)
{
	return this->GetPriority() < other.GetPriority();
	// quick explanation: the less the number returned by that function, the
	// bigger the priority ( you can watch the enum in ../headers/Task.hpp
}

// compares ONLY priorities
bool Task::operator<(Task& other)
{
	return !( *this > other); // already have the '>' operator, so no need
				  // to write code again
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
