#include "Header.h"

void registerAAcoount()
{
	string username, password;

	cout << "Sign up a username - (username should be a ID Student Number) : ";
	cin >> username;
	cout << "Sign up a password: ";
	cin >> password;

	ofstream f;
	f.open("D:\\" + username + ".txt");
	f << username << endl << password;
	f.close();
}

bool checkLoggin(string username, string password)
{
	string ckuser, ckpassword;

	ifstream f("D:\\" + username + ".txt");
	getline(f, ckuser);
	getline(f, ckpassword);

	if ((ckuser == username) && (ckpassword == password))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void changePassword()
{

	string username, password, ckuser, ckpassword, chpassword, chpassword1;

	cout << "Input username: ";
	cin >> username;
	cout << "Input the old password: ";
	cin >> password;

	ifstream f("D:\\" + username + ".txt");
	getline(f, ckuser);
	getline(f, ckpassword);

	if ((ckuser == username) && (ckpassword == password))
	{
		cout << "Input the password which you want to change: ";
		cin >> chpassword;
		cout << endl << "Input the password which you want to change again: ";
		cin >> chpassword1;
		if (chpassword == chpassword1)
		{
			ofstream f1;
			f1.open("D:\\" + username + ".txt");
			f1 << username << endl << chpassword;
			f1.close();
		}
	}
	else
	{
		cout << "Wrong username or password. Please try again!";
	}
}


//CAC HAM KIEM TRA CHUYEN DOI
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

bool checkName(char* name1, char* name2)
{
	char temp1[20], temp2[20];
	int i = 0, flag = 1;
	strcpy(temp1, name1);
	strcpy(temp2, name2);
	while (temp1[i] != '\0') {
		if (temp1[i] != temp2[i]) {
			flag = 0;
			break;
		}
		i++;
	}
	if (flag == 1)
		return true;
	else
		return false;
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

void addStudentToClass(Class*& cl, Student* st)
{
	Node* node = createNode(st);
	if (cl->head == NULL)
	{
		cl->head = node;
	}
	else {
		Node* temp1 = cl->head;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = node;
	}
}

void inputClass(School_year*& sy)
{
	Class* classes = new Class;
	createClass(sy, classes);
	addClassToSchoolYear(sy, classes);
}

void readToFile(char* file_name, School_year*& sy, char* name)
{
	ifstream file(file_name);
	Student* st = new Student[10];
	if (!file.is_open())
	{
		cout << "Cannot read file!";
	}
	else
	{
		for (Node_class* temp = sy->head; temp != NULL; temp = temp->next)
		{
			if (checkName(temp->data->class_name, name)) {
				int i = 0;
				while (file.good())
				{
					getline(file, (st + i)->no, ',');

					getline(file, (st + i)->student_id, ',');


					getline(file, (st + i)->first_name, ',');
					getline(file, (st + i)->last_name, ',');

					getline(file, (st + i)->gender, ',');

					getline(file, (st + i)->day_of_birth, ',');
					getline(file, (st + i)->month_of_birth, ',');
					getline(file, (st + i)->year_of_birth, ',');

					getline(file, (st + i)->social_id, '\n');

					addStudentToClass(temp->data, (st + i));
					i++;
				}
				cout << "A large number of students have joined the class\n";
			}
		}
	}
	file.close();
}

void inputStudentToClass(School_year*& school)
{
	char* name;
	enterTheNameOfClass(name);
	Node_class* temp = school->head;
	int k = 0;
	while (temp != NULL)
	{
		if (checkName(temp->data->class_name, name))
		{
			k = 1;
			Student* st = infoStudent();
			addStudentToClass(temp->data, st);
			cout << "The student has become a part of the class.\n";
		}
		temp = temp->next;
	}
	if (k == 0)
		cout << "Students cannot be added to the class. Classroom does not exist! \n";
}

void ouputinfostudent(Student* st)//***************
{
	cout << "\t\tNO: " << st->no << endl;
	cout << "\t\tStudent ID: " << st->student_id << endl;
	cout << "\t\tThe student name: " << st->first_name << " " << st->last_name << endl;
	cout << "\t\tGender: " << st->gender << endl;
	cout << "\t\tDate of birth: " << st->day_of_birth << "/" << st->month_of_birth << "/" << st->year_of_birth << endl;
	cout << "\t\tSocial ID: " << st->social_id;
}

void outputInfoClass(Class* cl)
{
	cout << "\tThe name class: " << cl->class_name;
	Node* temp = cl->head;
	int i = 1;
	while (temp != NULL)
	{
		if (temp->next != NULL)
		{
			const char* ch = checkOrder(i);
			cout << "\n\t" << i << ch << " student" << endl;
			ouputInfoStudent(temp->data);
			temp = temp->next;
			cout << endl;
			i++;
		}
	}
}

// 6-11
NODE* createNodeCourse(course* data)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "CANNOT ALLOCATE!";
		return NULL;
	}
	p->data = data;
	p->pNext = NULL;

	return p;
}

void createASemester(Semester*& se)
{
	se->pHead = se->pTail = NULL;
}

void createSemester(Semester*& se)
{
	cout << "------------------------------------------------CREATE YOUR SEMESTER:---------------------------------------------------" << endl;
	cout << "Let's create a semester: 1, 2, or 3: ";
	cin >> se->createASemester;

	if (1 <= se->createASemester && se->createASemester <= 3)
	{
		cout << "\nNow, your semester is " << se->createASemester << ".";
		do
		{
			cout << "\nEnter the school year: ";
			cin >> se->schoolYear;
			if (se->schoolYear < 2021)
			{
				cout << "FAULT!!! PLEASE RE-ENTER." << endl;
			}
		} while (se->schoolYear < 2021);

		cout << "Enter the start date semester: " << endl;
		do
		{
			cout << '\t' << "Day: ";
			cin >> se->startDay;
			cout << '\t' << "Month: ";
			cin >> se->startMonth;
			if (checkDate(to_string(se->startDay), to_string(se->startMonth), to_string(se->schoolYear)) == false)
			{
				cout << "FAULT!!! PLEASE RE-ENTER." << endl;
			}
		} while (checkDate(to_string(se->startDay), to_string(se->startMonth), to_string(se->schoolYear)) == false);

		cout << "Enter the end date semester: " << endl;
		do
		{
			cout << '\t' << "Day: ";
			cin >> se->endDay;
			cout << '\t' << "Month: ";
			cin >> se->endMonth;
			if (checkDate(to_string(se->endDay), to_string(se->endMonth), to_string(se->schoolYear)) == false)
			{
				cout << "FAULT!!! PLEASE RE-ENTER." << endl;
			}
		} while (checkDate(to_string(se->endDay), to_string(se->endMonth), to_string(se->schoolYear)) == false);
	}
	else
	{
		cout << "FAULT! PLEASE RE-ENTER: ";
		cin >> se->createASemester;
	}

	createASemester(se);
}

void addTail(Semester*& se, course* c)
{
	NODE* newnode = createNodeCourse(c);
	if (se->pHead == NULL)
		se->pHead = se->pTail = newnode;
	else
	{
		NODE* temp = se->pHead;
		while (temp->pNext != NULL)
		{
			temp = temp->pNext;
		}
		temp->pNext = newnode;
	}
}

//**
session* registrationSession()
{
	cout << "-------------------------------------------COURSE REGISTRATION DEADLINE:-----------------------------------------------" << endl;
	session* rs = new session;
	cout << "Let's create a course registration session." << endl;

	cout << "Enter the start date course registration session: " << endl;
	do
	{
		cout << '\t' << "Day: ";
		cin >> rs->startDay0;
		cout << '\t' << "Month: ";
		cin >> rs->startMonth0;
		if (checkDate(rs->startDay0, rs->startMonth0, rs->startYear0) == false)
		{
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
	} while (checkDate(rs->startDay0, rs->startMonth0, rs->startYear0) == false);

	cout << "Enter the end date course registration session: " << endl;
	do
	{
		cout << '\t' << "Day: ";
		cin >> rs->endDay0;
		cout << '\t' << "Month: ";
		cin >> rs->endMonth0;
		if (checkDate(rs->endDay0, rs->endMonth0, rs->endYear0) == false)
		{
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
	} while (checkDate(rs->endDay0, rs->endMonth0, rs->endYear0) == false);

	return rs;
}