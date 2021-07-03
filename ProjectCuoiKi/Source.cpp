#include "Header.h"

bool checkDate(string day, string month, string year)
{
	if ((stoi(year) % 4 == 0 && stoi(year) % 100 != 0) || stoi(year) % 400 == 0) // nam nhuan
	{
		if ((stoi(month) == 1 || stoi(month) == 3 || stoi(month) == 5 || stoi(month) == 7 || stoi(month) == 8 || stoi(month) == 10 || stoi(month) == 12) && (stoi(day) > 0 && stoi(day) < 31))
		{
			return true;
		}
		if ((stoi(month) == 4 || stoi(month) == 6 || stoi(month) == 9 || stoi(month) == 11) && (stoi(day) > 0 && stoi(day) < 30))
		{
			return true;
		}
		if (stoi(month) == 2 && (stoi(day) > 0 || stoi(day) < 29))
		{
			return true;
		}
		return false;
	}
	else // khong phai nam nhuan
	{
		if ((stoi(month) == 1 || stoi(month) == 3 || stoi(month) == 5 || stoi(month) == 7 || stoi(month) == 8 || stoi(month) == 10 || stoi(month) == 12) && (stoi(day) > 0 && stoi(day) < 32))
		{
			return true;
		}
		if ((stoi(month) == 4 || stoi(month) == 6 || stoi(month) == 9 || stoi(month) == 11) && (stoi(day) > 0 && stoi(day) < 31))
		{
			return true;
		}
		if (stoi(month) == 2 && (stoi(day) > 0 && stoi(day) < 30))
		{
			return true;
		}
		return false;
	}
}

//1-5
void enterTheName(char*& name)
{
	cin.ignore();
	cout << "Enter the name: ";
	char temp_name[20];
	cin.getline(temp_name, 20, '\n');
	name = new char[strlen(temp_name) + 1];
	strcpy(name, temp_name);
}

void enterTheNameOfClass(char*& name)
{
	cin.ignore();
	cout << "Enter the name of class, ex: 20KDL1 ";
	char temp_name[20];
	cin.getline(temp_name, 20, '\n');
	name = new char[strlen(temp_name) + 1];
	strcpy(name, temp_name);
}

Student* infoStudent()
{
	Student* st = new Student;
	cout << "\tEnter the NO: ";
	cin >> st->no;

	cout << "\tEnter the student ID: ";
	cin >> st->student_id;

	cin.ignore();
	cout << "\tEnter the first name: ";
	getline(cin, st->first_name);

	cout << "\tEnter the last name: ";
	getline(cin, st->last_name);

	cout << "\tEnter the gender: ";
	getline(cin, st->gender);

	do {
		cout << "\tEnter the date of birth:\n";
		cout << "\t\tDay: ";
		getline(cin, st->day_of_birth);
		cout << "\t\tMonth: ";
		getline(cin, st->month_of_birth);
		cout << "\t\tYear: ";
		getline(cin, st->year_of_birth);
		if ((checkDate(st->day_of_birth, st->month_of_birth, st->year_of_birth) == false))
		{
			cout << "Fault! Please re-enter!";
		}
	} while ((checkDate(st->day_of_birth, st->month_of_birth, st->year_of_birth) == false));

	cout << "\tEnter the social ID: ";
	getline(cin, st->social_id);
	return st;
}

Node* createNode(Student* data)
{
	Node* node = new Node;
	if (node == NULL)
	{
		cout << "Cannot allocate!";
		return NULL;
	}
	node->data = data;
	node->next = NULL;

	return node;
}

Node_class* createNodeClass(Class* data)
{
	Node_class* node_class = new Node_class;

	node_class->data = data;
	node_class->next = NULL;

	return node_class;
}

void createSchoolYear(School_year*& sy)
{
	sy->head = sy->tail = NULL;

	cout << "Create a school year (2020-2021, for example): \n";
	do
	{
		cout << "\tThe beginning of the school year: ";
		cin >> sy->the_beginning_year;
		cout << "\tThe end of the school year: ";
		cin >> sy->the_end_year;
		if (sy->the_beginning_year < 2000 || sy->the_end_year < 2000 || sy->the_beginning_year == sy->the_end_year)
		{
			cout << "Fault!Please re-enter" << endl;
		}
	} while (sy->the_beginning_year < 2000 || sy->the_end_year < 2000 || sy->the_beginning_year == sy->the_end_year);
}

void createClass(School_year*& school, Class*& classes)
{
	classes->head = classes->tail = NULL;

	cin.ignore();
	cout << "Create several classes for 1st year students: ";
	char temp[20];
	cin.getline(temp, 20, '\n');
	classes->class_name = new char[strlen(temp) + 1];
	strcpy(classes->class_name, temp);
}

void addClassToSchoolYear(School_year*& sy, Class* cl)
{
	Node_class* node_class = createNodeClass(cl);
	if (sy->head == NULL)
	{
		sy->head = node_class;
	}
	else {
		Node_class* temp = sy->head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node_class;
	}
}

void inputClass(School_year*& sy)
{
	Class* classes = new Class;
	createClass(sy, classes);
	addClassToSchoolYear(sy, classes);
}
//*****
void Input_student_to_class(School_year*& school)
{
	char* name;
	Enter_the_name(name);
	Node_class* temp = school->head;
	int k = 0;
	while (temp != NULL)
	{
		if (check_name(temp->data->class_name, name))
		{
			k = 1;
			Student* st = info_student();
			Add_student_to_class(temp->data, st);
			cout << "The student has become a part of the class.\n";
		}
		temp = temp->next;
	}
	if (k == 0)
		cout << "Students cannot be added to the class. Classroom does not exist! \n";
}

// 6-11