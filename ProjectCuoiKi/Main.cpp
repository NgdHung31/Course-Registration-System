#include "Header.h"

int main()
{
	int type;
	cout << "Choose 1 if you are staff members\n";
	cout << "Choose 2 if you are student\n";
	cout << "Your choice: ";
	cin >> type;

	School_year* school = new School_year;
	Semester* se = new Semester;
	course* c = new course;
	Student* st = new Student;
	listStudent ls;
	listCourse lc;
	initListCourse(lc);
	initListStudent(ls);

	int choice1, choice2;
	if (type == 1)
	{
		system("cls");
		cout << "----------Staff Member----------\n";
		cout << "1. Create a school year (2020-2021, for example)\n";
		cout << "2. Create several classes for 1st year students. For example: class 20APCS1, class 20APCS2, class 20CLC1..., class 20CLC11, class 20VP...\n";
		cout << "3. Add new 1st year students to 1st-year classes\n";
		cout << "4. He/she want to import a CSV file containing all students in a specific class to the system.\n";
		cout << "5. He/she want to see list student.\n";
		cout << "6. Create a semester.\n";
		cout << "7. Create a course registration session.\n";
		cout << "8. Add a course to this semester.\n";
		cout << "9. View list of courses.\n";
		cout << "10. Update course information.\n";
		cout << "11. Delete a course.\n";
		cout << "0. Log out.\n";

		do
		{
			cout << "\nYour choice: ";
			cin >> choice1;

			switch (choice1)
			{
			case 1:
			{
				createSchoolYear(school);
				break;
			}
			case 2:
			{
				inputClass(school);
				break;
			}
			case 3:
			{
				inputStudentToClass(school);
				break;
			}
			case 4:
			{
				char* name1;
				enterTheNameOfClass(name1);
				readToFile((char*)"Data.csv", school, name1);
				break;
			}
			case 5:
			{
				char* name2;
				enterTheNameOfClass(name2);
				printInfo1Class(school, name2);
				break;
			}
			case 51:
			{
				printAllClass(school);
				break;
			}
			case 6:
			{
				createSemester(se);
				break;
			}
			case 7:
			{
				//Trong phien dang ki nay se bao gom cac khoa trong cau 8 ma minh se nhap vao, tuc la trong mot hoc ky thi thuong chi co 1 phien dang ki, neu muon tao phien dang ki khac thi nhap lai lenh nay
				c = createACourseRegistrationSession(se, c);
				break;
			}
			case 8:
			{
				//Co the them nhieu khoa hoc trong mot phien dang ky, neu muon them khoa hoc o phien dang ki khac thi qua lay cau 7 de tao mot phien dang ky moi
				addACourseToThisSemester(se, c);
				break;
			}
			case 9:
			{

				break;
			}
			case 10:
			{

				break;
			}
			case 11:
			{

				break;
			}
			case 0:
			{
				break;
			}
			}
		} while (choice1 != 0);
	}

	if (type == 2)
	{
		system("cls");
		cout << "----------Student----------\n";
		cout << "1. Register\n";
		cout << "2. Log in\n";
		cout << "3. Change password\n";
		cout << "4. Logout\n";
		cout << "13. Enroll in a course.\n";
		cout << "14. View list of enrolled courses.\n";
		cout << "15. Remove a course from the enrolled list.\n";
		cout << "16. View list of his/her courses. He/she will study these courses in this semester.\n";
		cout << "17. View list of classes.\n";
		cout << "18. View list of students in a class (for example, 20APCS1...)\n";
		cout << "19. View list of courses.\n";
		cout << "20. View list of students in a course.";

		do
		{
			cout << "\nYour choice: ";
			cin >> choice2;

			switch (choice2)
			{
			case 1:
			{
				registerAAcoount();
				break;
			}
			case 2:
			{
				string username, password;
				cout << "Enter the username: ";
				cin >> username;
				cout << "Enter the password: ";
				cin >> password;
				bool check = checkLoggin(username, password);

				if (check)
				{
					cout << "Successfully log in!";
					cout << endl;
					st = infoStudent();
				}
				else
				{
					cout << "Try again! ";
					system("pause");
				}
				break;
			}
			case 3:
			{
				changePassword();
				break;
			}
			case 4:
			{

				break;
			}
			case 13:
			{
				enrollACourse(se, st, ls, lc);
				break;
			}
			case 14:
			{
				outputListOfEnrolledCourse(lc);
				break;
			}
			case 15:
			{
				removeACourseFromEnrolledList(lc);
				break;
			}
			case 16:
			{
				outputListOfYourCourse(lc);
				break;
			}
			case 17:
			{
				outputListOfClasses(school);
				break;
			}
			case 18:
			{
				char* name;
				enterTheNameOfClass(name);
				outputListOfStudentInAClass(school, name);
				break;
			}
			case 19:
			{
				outputListOfCourses(se);
				break;
			}
			case 20:
			{
				outputListOfStudentsInACourse(ls);
				break;
			}
			}
		} while (choice2 != 4);
	}

}


