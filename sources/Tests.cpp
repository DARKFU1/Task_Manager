#include "../headers/Tests.hpp"

void LaunchUnitTests()
{
	printf("--------------------------------\n");
	printf("	Unit Tests		\n");
	printf("--------------------------------\n\n");

	/// tests under that line.

	//Tlist;	
	TEST("[List] Adding and getting element")
	{
		TList<int> tl;
		tl.Add(1);
		tl.Add(2);

		return tl[0] == 1 && tl[1] == 2;
	}ENDTEST();
	
	TEST("[List] Removing element")
	{
		TList<int> tl;
		tl.Add(8);
		tl.Add(9);

		tl.Remove(0);

		return tl.Get(0) == 9;
	}ENDTEST();
	// TList;

	// Task
	TEST("[Task] Creating")
	{
		Task t("Test task", TaskState::NOT_DONE | TaskState::MAX_PRIORITY);

		return t.GetProgress() == TaskState::NOT_DONE && t.GetPriority() == TaskState::MAX_PRIORITY;

	}ENDTEST();

	TEST("[Task] Changing values")
	{
		Task t("Test task", TaskState::NOT_DONE | TaskState::MAX_PRIORITY);
		
		t.SetPriority(TaskState::MEDIUM_PRIORITY);
		t.SetProgress(TaskState::IN_PROGRESS);

		bool is_priority_fine = t.GetPriority() == TaskState::MEDIUM_PRIORITY;
		bool is_progress_fine = t.GetProgress() == TaskState::IN_PROGRESS;

		return is_progress_fine;

	}ENDTEST();
	

	/// tests higher this line.
	printf("\n--------------------------------\n");
	printf("      Unit Tests Are Done!	\n");
	printf("--------------------------------\n\n");
}
