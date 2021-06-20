#include "Header6_11.h"

int main()
{
	semester* se = new semester;
	se = createSemester();
	int choice0;
	do
	{
		cout << "------------------------------------------------------MENU-------------------------------------------------------------";
		cout << "\n7. Create a course registration session.";
		cout << "\n8. Add a course to this semester.";
		cout << "\n9. View list of courses.";
		cout << "\n10. Update course information.";
		cout << "\n11. Delete a course.";
		cout << "\n0. Exit! " << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "ENTER YOUR CHOICE: " << endl;
		cin >> choice0;

		switch (choice0)
		{
		case 7:
		{
			course* c = new course;
			c = registrationSession(se, se->schoolYear);
			break;
		}
		case 8:
		{
			course* c = new course;
			c = createCourse();
			addTail(c, se->listCourses);
			break;
		}
		case 9:
		{
			printList(se->listCourses);
			break;
		}
		case 10:
		{
			cout << "--------------------------------------------------UPDATE YOUR COURSE:---------------------------------------------------";
			int x;
			cout << "\nEnter the ID of course needed to update: ";
			cin >> x;

			course* c = new course;
			c = createCourse();
			NODE* p = createNODE(c);
			addNode_p_AfterNode_q(c, se->listCourses, x, p);

			//deleteCourse(se->listCourses, x);
			break;
		}
		case 11:
		{
			int x;
			cout << "\nEnter the ID of course needed to delete: ";
			cin >> x;

			deleteCourse(se->listCourses, x);
			break;
		}
		}
	} while (choice0 != 0);
}