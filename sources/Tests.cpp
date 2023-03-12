#include "../headers/Tests.hpp"

void LaunchUnitTests()
{
	printf("-----------------------------------------------------------------\n");
	
	ADD_LAYER("Example");

			TEST("FINE state")
			{
				return true;
			}ENDTEST();

			TEST("FAIL state")
			{
				return false;
			}ENDTEST();
	
			TEST("Imitating time-consuming function")
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(6000));

				return true;
			}ENDTEST();

	END_LAYER();

	ADD_LAYER("Unit_Tests");

		ADD_LAYER("List");	

		TEST("Adding and getting element")
		{
			TList<int> tl;
			tl.Add(1);
			tl.Add(2);

			return tl[0] == 1 && tl[1] == 2;
		}ENDTEST();
	
		TEST("Removing element")
		{
			TList<int> tl;
			tl.Add(8);
			tl.Add(9);
	
			tl.Remove(0);
	
			return tl.Get(0) == 9;
		}ENDTEST();

		END_LAYER(); // List

		ADD_LAYER("Task");

		TEST("Creating")
		{
			Task t("Test task", TaskState::NOT_DONE | TaskState::MAX_PRIORITY);

			return t.GetProgress() == TaskState::NOT_DONE && t.GetPriority() == TaskState::MAX_PRIORITY;

		}ENDTEST();

		TEST("Changing values")
		{
			Task t("Test task", TaskState::NOT_DONE | TaskState::MAX_PRIORITY);
		
			t.SetPriority(TaskState::MEDIUM_PRIORITY);
			t.SetProgress(TaskState::IN_PROGRESS);

			bool is_priority_fine = t.GetPriority() == TaskState::MEDIUM_PRIORITY;
			bool is_progress_fine = t.GetProgress() == TaskState::IN_PROGRESS;

			return is_progress_fine;

		}ENDTEST();

		TEST("Comparing two tasks")
		{
			Task a("Test task", TaskState::MAX_PRIORITY);
			Task b("Test task", TaskState::MEDIUM_PRIORITY);
			Task c("Test tast", TaskState::LOW_PRIORITY);

			return a > b && b > c && a > c && b < a && !(a < c) && c < a;
		}ENDTEST();

		TEST("Filework")
		{
			Task a("Test task", TaskState::MAX_PRIORITY | TaskState::NOT_DONE);
			Task c("Some description", TaskState::MEDIUM_PRIORITY | TaskState::IN_PROGRESS);	
	
			FILE* data_file_w = fopen("data/test.txt", "w");

			a.WriteToFile(data_file_w);
			c.WriteToFile(data_file_w);

			fclose(data_file_w);

			FILE* data_file_r = fopen("data/test.txt", "r");
		
			Task d(data_file_r);
			Task b(data_file_r);

			fclose(data_file_r);

			return (a == d) && (c == b);

		}ENDTEST();

	END_LAYER(); // Task


	END_LAYER(); // Unit tests
}

void LaunchIntegrationTests()
{
	ADD_LAYER("Integration Tests");

	ADD_LAYER("List + task");

	TEST("[LIST + TASK] Getting from file")
	{
		TList<Task> list;
		list.Add(Task("TEST", TaskState::MAX_PRIORITY | TaskState::NOT_DONE));
		list.Add(Task("TEST2", TaskState::LOW_PRIORITY | TaskState::DONE));

		FILE* data_file_w = fopen("data/test.txt", "w");
	
		list[0].WriteToFile(data_file_w);
		list[1].WriteToFile(data_file_w);

		fclose(data_file_w);
	
		FILE* data_file_r = fopen("data/test.txt", "r");

		TList<Task> list2;
		list2.Add(Task(data_file_r));
		list2.Add(Task(data_file_r));

		return list[0] == list2[0] && list[1] == list2[1];

	}ENDTEST();

	END_LAYER(); // List + Task
 
	//---------------------------------------------
	// tests higher this line

	END_LAYER(); // Integration tests
}
