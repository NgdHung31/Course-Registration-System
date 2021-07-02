#include "Header.h"

int main()
{
	int type;
	cout << "Choose 1 if you are staff members\n";
	cout << "Choose 2 if you are student\n";
	cout << "Your choice: ";
	cin >> type;

	School_year* school = new School_year;
	int choice1;

	if (type == 1)
	{
		system("cls");
		cout << "----------Staff Member----------\n";
		cout << "1. Create a school year (2020-2021, for example)\n";
		cout << "2. Create several classes for 1st year students. For example: class 20APCS1, class 20APCS2, class 20CLC1..., class 20CLC11, class 20VP...\n";
		cout << "3. Add new 1st year students to 1st-year classes\n";
		cout << "4. He/she want to import a CSV file containing all students in a specific class to the system.\n";
		cout << "5. He/she want to see list student.\n";
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
			}
		} while (true);
	}
}