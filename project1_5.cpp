#include "Header1_5.h"

int main()
{
	int type;
	cout << "Choose 1 if you are staff members\n";
	cout << "Choose 2 if you are student\n";
	cout << "Your choice: ";
	cin >> type;

	School_year* school = new School_year;


	if (type == 1)
	{
		system("cls");
		cout << "----------Staff Member----------\n";
		cout << "1. Create a school year (2020-2021, for example)\n";
		cout << "2. Create several classes for 1st year students. For example: class 20APCS1, class 20APCS2, class 20CLC1..., class 20CLC11, class 20VP...\n";
		cout << "3. Add new 1st year students to 1st-year classes\n";
		cout << "4. He/she want to import a CSV file containing all students in a specific class to the system.\n";
		cout << "5. he/she want to see list student.\n";
		cout << "6. Remove the student.\n";

		int choice1;
		do
		{
			cout << "\nYour choice: ";
			cin >> choice1;

			switch (choice1)
			{

			case 1:
				create_school_year(school);
				break;
			case 2:
				Input_class(school);
				break;
			case 3:
				Input_student_to_class(school);
				break;
			case 4:
				char* name1;
				Enter_the_name(name1);
				read_to_file((char*)"Data.csv", school, name1);
				break;
			 case 5:
				char* name2;
				Enter_the_name(name2);
				print_info_1_class(school, name2);
				break;
			 case 6:
				 print_all_class(school);
				 break;
			 case 7:
				 remove_class(school);
				 break;
			 case 8: 
				 remove_student(school);
				break;
			}
		} while (choice1 > 0 || choice1 < 9);
	}

	if (type == 2)
	{
		int choice2;
		while (true)
		{
			system("cls");
			cout << "----------Student----------\n";
			cout << "1. Register\n";
			cout << "2. Log in\n";
			cout << "3. Change password\n";
			cout << "4. Logout\n";
			cout << "Your choice: ";
			cin >> choice2;

			if (choice2 == 1)
			{
				register_a_account();
			}
			if (choice2 == 2)
			{
				string username, password;
				cout << "Enter the username: ";
				cin >> username;
				cout << "Enter the password: ";
				cin >> password;
				bool check = check_loggin(username, password);

				if (check)
				{
					cout << "Successfully log in!";
				}
				else
				{
					cout << "Try again! ";
					system("pause");
				}
			}
			if (choice2 == 3)
			{
				change_password();
			}
			if (choice2 == 4)
			{
				main();
			}
		}
	}
}