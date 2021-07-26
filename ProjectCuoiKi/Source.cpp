﻿#include "Header.h"

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


//Check & convert
bool checkDate(string day, string month, string year)
{
	if ((stoi(year) % 4 == 0 && stoi(year) % 100 != 0) || stoi(year) % 400 == 0)
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
	else
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

const char* checkOrder(int n)
{
	if (n == 1)
	{
		return "st";
	}
	else if (n == 2)
	{
		return "nd";
	}
	else if (n == 3)
	{
		return "rd";
	}
	else
	{
		return "th";
	}
}

const char* convertDay(int day)
{
	switch (day)
	{
	case 2:
		return "MONDAY";
		break;
	case 3:
		return "TUESDAY";
		break;
	case 4:
		return "WEDNESDAY";
		break;
	case 5:
		return "THURSDAY";
		break;
	case 6:
		return "FRIDAY";
		break;
	case 7:
		return "SATURDAY";
		break;
	}
}

const char* convertSession(int session)
{
	switch (session)
	{
	case 1:
		return "07:30";
		break;
	case 2:
		return "09:30";
		break;
	case 3:
		return "13:30";
		break;
	case 4:
		return "15:30";
		break;
	}
}

bool checkStartDateToRegistrationSession(string day_course, string month_course, string day_semester, string month_semester)
{
	if (stoi(month_course) < stoi(month_semester))
	{
		return true;
	}
	else if (stoi(month_course) == stoi(month_semester) && stoi(day_course) <= stoi(day_semester))
	{
		return true;
	}
	return false;
}

bool checkEndDateToRegistrationSession(string day_courseS, string month_courseS, string day_courseE, string month_courseE, string day_semester, string month_semester)
{
	if (stoi(month_courseS) <= stoi(month_courseE) && stoi(month_courseE) <= stoi(month_semester))
	{
		if (stoi(month_courseS) == stoi(month_courseE) && stoi(day_courseS) <= stoi(day_courseE))
		{
			return true;
		}
		else if (stoi(month_courseE) == stoi(month_semester) && stoi(day_courseE) <= stoi(day_semester))
		{
			return true;
		}
	}
	return false;
}

//1 - 5
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
		cin >> sy->theBeginningYear;
		cout << "\tThe end of the school year: ";
		cin >> sy->theEndYear;
		if (sy->theBeginningYear < 2000 || sy->theEndYear < 2000 || sy->theBeginningYear == sy->theEndYear)
		{
			cout << "Fault!Please re-enter" << endl;
		}
	} while (sy->theBeginningYear < 2000 || sy->theEndYear < 2000 || sy->theBeginningYear == sy->theEndYear);
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

void ouputInfoStudent(Student* st)
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

void printInfo1Class(School_year* sy, char* name)
{
	int k = 0;
	for (Node_class* temp = sy->head; temp != NULL; temp = temp->next)
	{
		if (checkName(temp->data->class_name, name) == true)
		{
			k = 1;
			cout << "\t\tThe name class: " << temp->data->class_name << endl;
			Node* temp1 = temp->data->head;
			int j = 1;
			while (temp1 != NULL)
			{
				const char* ch = checkOrder(j);
				cout << "\n\t" << j << ch << " student" << endl;
				ouputInfoStudent(temp1->data);
				temp1 = temp1->next;
				cout << endl;
				j++;
			}
		}
	}
	if (k == 0)
	{
		cout << "Can not see the list student of class to look for. Classroom does not exist!";
	}
}

void printAllClass(School_year* sy)
{
	int i = 1;
	cout << "--------------------THE INFORMATION CLASS OF THE SCHOOL YEAR--------------------\n";
	cout << "\tTHE BEGINNING YEAR: " << sy->theBeginningYear << endl;
	cout << "\tTHE ENDING YEAR: " << sy->theEndYear << endl << endl;
	for (Node_class* temp = sy->head; temp != NULL; temp = temp->next)
	{
		cout << "-----------------The class " << i << " -------------------\n";
		cout << "\t\tThe name class: " << temp->data->class_name << endl;
		Node* temp1 = temp->data->head;
		int j = 1;
		while (temp1 != NULL)
		{
			const char* ch = checkOrder(j);
			cout << "\n\t" << j << ch << " student" << endl;
			ouputInfoStudent(temp1->data);
			temp1 = temp1->next;
			cout << endl;
			j++;
		}
		i++;
	}
}

void removeHeadSchoolYear(School_year*& sy)
{
	if (sy->head == NULL)
	{
		return;
	}
	else
	{
		Node_class* p = sy->head;
		sy->head = sy->head->next;
		delete p;
	}
}

void removeTailSchoolYear(School_year*& sy)
{
	if (sy->head == NULL)
	{
		return;
	}
	if (sy->head->next == NULL)
	{
		removeHeadSchoolYear(sy);
	}
	else
	{
		for (Node_class* k = sy->head; k != NULL; k = k->next)
		{
			if (k->next == sy->tail)
			{
				delete sy->tail;
				k->next = NULL;
				sy->tail = k;
			}
		}
	}

}

bool removeClass(School_year*& sy)
{
	char* name;
	enterTheName(name);
	Node_class* temp1 = new Node_class;
	for (Node_class* temp = sy->head; temp != NULL; temp = temp->next)
	{
		if (checkName(temp->data->class_name, name))
		{
			if (temp == sy->head)
			{
				removeHeadSchoolYear(sy);
				return true;
			}
			else if (temp == sy->tail)
			{
				removeTailSchoolYear(sy);
				return true;
			}
			else
			{
				temp1->next = temp->next;
				delete temp;
				temp = temp1;
				return true;
			}
		}
		temp1 = temp;
	}
	return false;
}



//6 - 11
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
	cout << "-------------------------- CREATE YOUR SEMESTER ---------------------------" << endl;
	cout << "Let's create a semester: 1, 2, or 3: ";
	cin >> se->createASemester;

	if (1 <= se->createASemester && se->createASemester <= 3)
	{
		cout << "\nNow, your semester is " << se->createASemester << ". ";
		if (se->createASemester == 1)
		{
			cout << "Fall";
		}
		else if (se->createASemester == 2)
		{
			cout << "Summer";
		}
		else if (se->createASemester == 3)
		{
			cout << "Winter";
		}
		do
		{
			cout << "\nEnter the school year: ";
			cin >> se->schoolYear;
			if (se->schoolYear < 2021)
			{
				cout << "FAULT!!! PLEASE RE-ENTER." << endl;
			}
		} while (se->schoolYear < 2021);

		if (se->createASemester == 1)
		{
			cout << "Enter the start date semester: " << endl;
			do
			{
				cout << '\t' << "Day: ";
				cin >> se->startDay;
				cout << '\t' << "Month: ";
				cin >> se->startMonth;
				if ((checkDate(to_string(se->startDay), to_string(se->startMonth), to_string(se->schoolYear)) == false) || ((se->startMonth < 9) || (se->startMonth > 11)))
				{
					cout << "FAULT!!! PLEASE RE-ENTER." << endl;
				}
			} while ((checkDate(to_string(se->startDay), to_string(se->startMonth), to_string(se->schoolYear)) == false) || ((se->startMonth < 9) || (se->startMonth > 11)));

			cout << "Enter the end date semester: " << endl;
			do
			{
				cout << '\t' << "Day: ";
				cin >> se->endDay;
				cout << '\t' << "Month: ";
				cin >> se->endMonth;
				if ((checkDate(to_string(se->endDay), to_string(se->endMonth), to_string(se->schoolYear)) == false) || ((se->endMonth < 9) || (se->endMonth > 11)))
				{
					cout << "FAULT!!! PLEASE RE-ENTER." << endl;
				}
			} while ((checkDate(to_string(se->endDay), to_string(se->endMonth), to_string(se->schoolYear)) == false) || ((se->endMonth < 9) || (se->endMonth > 11)));
		}

		if (se->createASemester == 2)
		{
			cout << "Enter the start date semester: " << endl;
			do
			{
				cout << '\t' << "Day: ";
				cin >> se->startDay;
				cout << '\t' << "Month: ";
				cin >> se->startMonth;
				if ((checkDate(to_string(se->startDay), to_string(se->startMonth), to_string(se->schoolYear)) == false) || ((se->startMonth < 6) || (se->startMonth > 8)))
				{
					cout << "FAULT!!! PLEASE RE-ENTER." << endl;
				}
			} while ((checkDate(to_string(se->startDay), to_string(se->startMonth), to_string(se->schoolYear)) == false) || ((se->startMonth < 6) || (se->startMonth > 8)));

			cout << "Enter the end date semester: " << endl;
			do
			{
				cout << '\t' << "Day: ";
				cin >> se->endDay;
				cout << '\t' << "Month: ";
				cin >> se->endMonth;
				if ((checkDate(to_string(se->endDay), to_string(se->endMonth), to_string(se->schoolYear)) == false) || ((se->endMonth < 6) || (se->endMonth > 8)))
				{
					cout << "FAULT!!! PLEASE RE-ENTER." << endl;
				}
			} while ((checkDate(to_string(se->endDay), to_string(se->endMonth), to_string(se->schoolYear)) == false) || ((se->endMonth < 6) || (se->endMonth > 8)));
		}

		if (se->createASemester == 3)
		{
			cout << "Enter the start date semester: " << endl;
			do
			{
				cout << '\t' << "Day: ";
				cin >> se->startDay;
				cout << '\t' << "Month: ";
				cin >> se->startMonth;
				if ((checkDate(to_string(se->startDay), to_string(se->startMonth), to_string(se->schoolYear)) == false) || ((se->startMonth != 12) && (se->startMonth > 2)))
				{
					cout << "FAULT!!! PLEASE RE-ENTER." << endl;
				}
			} while ((checkDate(to_string(se->startDay), to_string(se->startMonth), to_string(se->schoolYear)) == false) || ((se->startMonth != 12) && (se->startMonth > 2)));

			cout << "Enter the end date semester: " << endl;
			do
			{
				cout << '\t' << "Day: ";
				cin >> se->endDay;
				cout << '\t' << "Month: ";
				cin >> se->endMonth;
				if ((checkDate(to_string(se->endDay), to_string(se->endMonth), to_string(se->schoolYear)) == false) || ((se->endMonth != 12) && (se->endMonth > 2)))
				{
					cout << "FAULT!!! PLEASE RE-ENTER." << endl;
				}
			} while ((checkDate(to_string(se->endDay), to_string(se->endMonth), to_string(se->schoolYear)) == false) || ((se->endMonth != 12) && (se->endMonth > 2)));
		}
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

void createACourseRegistrationSession(Semester* se, session& ss) 
{
	cout << "\n-------------------- COURSE REGISTRATION SESSION DEADLINE ----------------------" << endl;
	cout << "\t\t\t\t\t\tSEMESTER " << se->createASemester << endl;
	cout << "\t\t\t\t\t\t" << se->startDay << "/" << se->startMonth << " - " << se->endDay << "/" << se->endMonth << endl;

	cout << "Enter the start date course registration session: " << endl;
	do
	{
		cout << '\t' << "Day: ";
		cin >> ss.startDay0;
		cout << '\t' << "Month: ";
		cin >> ss.startMonth0;
		if (checkDate(to_string(ss.startDay0), to_string(ss.startMonth0), to_string(se->schoolYear)) == false)
		{
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
		else if (checkStartDateToRegistrationSession(to_string(ss.startDay0), to_string(ss.startMonth0), to_string(se->startDay), to_string(se->startMonth)) == false)
		{
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
	} while (!checkDate(to_string(ss.startDay0), to_string(ss.startMonth0), to_string(se->schoolYear)) || !checkStartDateToRegistrationSession(to_string(ss.startDay0), to_string(ss.startMonth0), to_string(se->startDay), to_string(se->startMonth)));

	cout << "Enter the end date course registration session: " << endl;
	do
	{
		cout << '\t' << "Day: ";
		cin >> ss.endDay0;
		cout << '\t' << "Month: ";
		cin >> ss.endMonth0;
		if (checkDate(to_string(ss.endDay0), to_string(ss.endMonth0), to_string(se->schoolYear)) == false)
		{
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
		else if (checkEndDateToRegistrationSession(to_string(ss.startDay0), to_string(ss.startMonth0), to_string(ss.endDay0), to_string(ss.endMonth0), to_string(se->startDay), to_string(se->startMonth)) == false)
		{
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
	} while (!checkDate(to_string(ss.endDay0), to_string(ss.endMonth0), to_string(se->schoolYear)) || !checkEndDateToRegistrationSession(to_string(ss.startDay0), to_string(ss.startMonth0), to_string(ss.endDay0), to_string(ss.endMonth0), to_string(se->startDay), to_string(se->startMonth)));
}

course* createACourse(Semester*& se, course* c)
{
	cout << "--------------------- CREATE YOUR COURSE ----------------------" << endl;

	cout << "Enter the ID of course: ";
	cin.ignore();
	char temp[100];
	cin.getline(temp, 100);
	c->courseID = new char[strlen(temp) + 1];
	strcpy(c->courseID, temp);

	char temp1[100];
	cout << "Enter the name of course: ";
	cin.getline(temp1, 100);
	c->courseName = new char[strlen(temp1) + 1];
	strcpy(c->courseName, temp1);

	cout << "Enter the name of teacher: ";
	char temp2[100];
	cin.getline(temp2, 100, '\n');
	c->teacherName = new char[strlen(temp2) + 1];
	strcpy(c->teacherName, temp2);

	cout << "Enter the number of credits: ";
	cin >> c->numberCredits;

	do
	{
		cout << "Enter the maximum number of students in the course (default 50): ";
		cin >> c->maxStudentCourse;
		if (c->maxStudentCourse > 50)
		{
			cout << "FAULT! PLEASE RE-ENTER" << endl;
		}
	} while (c->maxStudentCourse > 50);

	cout << "THE SESSION THAT THE COURSE WILL BE PERFORMED:" << endl;
	cout << "\tDAY OF WEEK:       \t" << "THE TIME SESSION:\n";
	cout << "\tchoose 2: MONDAY   \t" << "S1: 07:30\n";
	cout << "\tchoose 3: TUESDAY  \t" << "S2: 09:30\n";
	cout << "\tchoose 4: WEDNESDAY\t" << "S3: 13:30\n";
	cout << "\tchoose 5: THURSDAY \t" << "S4: 15:30\n";
	cout << "\tchoose 6: FRIDAY   \n";
	cout << "\tchoose 7: SATURDAY \n";
	do
	{
		cout << "The first day: ";
		cin >> c->firstDay;
		if (c->firstDay < 2 || c->firstDay > 7)
		{
			cout << "FAULT! PLEASE RE-ENTER" << endl;
		}
	} while (c->firstDay < 2 || c->firstDay > 7);

	do
	{
		cout << "The session: S";
		cin >> c->firstSession;
		if (c->firstSession < 1 || c->firstSession > 4)
		{
			cout << "FAULT! PLEASE RE-ENTER" << endl;
		}
	} while (c->firstSession < 1 || c->firstSession > 4);


	do
	{
		cout << "The second day: ";
		cin >> c->secondDay;
		if (c->secondDay < 2 || c->secondDay > 7)
		{
			cout << "FAULT! PLEASE RE-ENTER" << endl;
		}
	} while (c->secondDay < 2 || c->secondDay > 7);

	do
	{
		cout << "The session: S";
		cin >> c->secondSession;
		if (c->secondSession < 1 || c->secondSession > 4)
		{
			cout << "FAULT! PLEASE RE-ENTER" << endl;
		}
	} while (c->secondSession < 1 || c->secondSession > 4);

	addTail(se, c);

	return c;
}

void outputCourse(course* c)
{
	cout << "\tThe ID of course: " << c->courseID << endl;
	cout << "\tThe name of course: " << c->courseName << endl;
	cout << "\tThe name of teacher: " << c->teacherName << endl;
	cout << "\tThe number of credits: " << c->numberCredits << endl;
	cout << "\tThe maximum number of students in the course (default 50): " << c->maxStudentCourse << endl;
	cout << "\t\tThe FRIST day: " << convertDay(c->firstDay) << endl;
	cout << "\t\tThe FRIST session: " << convertSession(c->firstSession) << endl;
	cout << "\t\tThe SECOND day: " << convertDay(c->secondDay) << endl;
	cout << "\t\tThe SECOND session: " << convertSession(c->secondSession) << endl;
}

void printList(Semester*& se)
{
	cout << "\n\t---------------------- VIEW LIST OF COURSE ------------------------" << endl;
	cout << "\t\t\t\tSEMESTER " << se->createASemester << endl;
	cout << "\t\t\t\t" << se->startDay << "/" << se->startMonth << " - " << se->endDay << "/" << se->endMonth << endl;

	NODE* temp = se->pHead;
	int i = 1;
	if (temp != NULL)
	{
		for (temp = se->pHead; temp != NULL; temp = temp->pNext)
		{
			const char* ch = checkOrder(i);
			cout << "\n\t" << i << ch << " course " << endl;
			outputCourse(temp->data);
			cout << endl;
			i++;
		}
	}
	else
	{
		cout << "Empty list!\n";
	}
}

void updateInformation(Semester*& se)
{
	char* ID;
	int choice;
	cout << "--------------------- UPDATE YOUR COURSE INFORMATION -----------------------";

	cout << "\nEnter the ID of course needed to update: ";
	cin.ignore();
	char temp[100];
	cin.getline(temp, 100);
	ID = new char[strlen(temp) + 1];
	strcpy(ID, temp);

	for (NODE* temp1 = se->pHead; temp1 != NULL; temp1 = temp1->pNext)
	{
		if (checkName(ID, temp1->data->courseID))
		{
			cout << "--------------------- What would you like to have updated in the course? ---------------------\n";
			cout << "\tChoice 1: Update ID.\n";
			cout << "\tChoice 2: Update the name of the course.\n";
			cout << "\tChoice 3: Update the name of the teacher.\n";
			cout << "\tChoice 4: Update The number of credits.\n";
			cout << "\tChoice 5: The maximum number of students in the course.\n";
			cout << "\tChoice 6: Update the day of week.\n";
			cout << "\tChoice 7: Update the time session.\n";

			cout << "\nEnter yours choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				char* ID;
				cout << "\tEnter The new ID: ";
				cin.ignore();
				char temp2[100];
				cin.getline(temp2, 100);
				ID = new char[strlen(temp2) + 1];
				strcpy(ID, temp2);

				swap(ID, temp1->data->courseID);
				break;
			}
			case 2:
			{
				char* courseName;
				char temp2[100];
				cin.ignore();
				cout << "Enter the name name of course: ";
				cin.getline(temp2, 100);
				courseName = new char[strlen(temp2) + 1];
				strcpy(courseName, temp2);

				swap(courseName, temp1->data->courseName);
				break;
			}
			case 3:
			{
				char* teacherName;
				char temp2[100];
				cin.ignore();
				cout << "Enter the new name of the teacher: ";
				cin.getline(temp2, 100, '\n');
				teacherName = new char[strlen(temp2) + 1];
				strcpy(teacherName, temp2);

				swap(teacherName, temp1->data->teacherName);
				break;
			}
			case 4:
			{
				int credit;
				cout << "Enter The new number of credits:  ";
				cin >> credit;

				swap(credit, temp1->data->numberCredits);
				break;
			}
			case 5:
			{
				int max;
				cout << "Enter The new maximum number of students in the course: ";
				cin >> max;

				swap(max, temp1->data->maxStudentCourse);
				break;
			}
			case 6:
			{
				int firstDay, secondDay;
				cout << "\t****DAY OF WEEK****\n";
				cout << "\tchoose 2: MONDAY\n";
				cout << "\tchoose 3: TUESDAY\n";
				cout << "\tchoose 4: WEDNESDAY\n";
				cout << "\tchoose 5: THURSDAY\n";
				cout << "\tchoose 6: FRIDAY\n";
				cout << "\tchoose 7: SATURDAY\n";
				do {
					do
					{
						cout << "Enter The new first day: ";
						cin >> firstDay;
						if (firstDay < 2 || firstDay > 7)
							cout << "FAULT! PLEASE RE-ENTER" << endl;
					} while (firstDay < 2 || firstDay > 7);

					do
					{
						cout << "Enter The new second day: ";
						cin >> secondDay;
						if (firstDay < 2 || firstDay > 7)
							cout << "FAULT! PLEASE RE-ENTER" << endl;
					} while (firstDay < 2 || firstDay > 7);
					if (firstDay == secondDay)
					{
						cout << "***Two sessions have been scheduled at the same time.\n";
						cout << "PLEASE RE-ENTER" << endl;
					}
				} while (firstDay == secondDay);

				swap(firstDay, temp1->data->firstDay);
				swap(secondDay, temp1->data->secondDay);
				break;

			}
			case 7:
			{
				int firstSession;
				int secondSession;
				cout << "****THE TIME SESSION****\n";
				cout << "S1: 07:30\n";
				cout << "S2: 09:30\n";
				cout << "S3: 13:30\n";
				cout << "S4: 15:30\n";

				do
				{
					cout << "Enter The new session: S";
					cin >> firstSession;
					if (firstSession < 1 || firstSession > 4)
					{
						cout << "FAULT! PLEASE RE-ENTER" << endl;
					}
				} while (firstSession < 1 || firstSession >4);

				do
				{
					cout << "Enter The new session: S";
					cin >> secondSession;
					if (firstSession < 1 || firstSession > 4)
					{
						cout << "FAULT! PLEASE RE-ENTER" << endl;
					}
				} while (firstSession < 1 || firstSession > 4);
				swap(firstSession, temp1->data->firstSession);
				swap(secondSession, temp1->data->secondSession);
				break;
			}
			}
		}
	}
}

void deleteHead(Semester*& se)
{
	if (se->pHead == NULL)
	{
		return;
	}
	NODE* p = se->pHead;
	se->pHead = se->pHead->pNext;
	delete p;
}

void deleteTail(Semester*& se)
{
	for (NODE* k = se->pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == se->pTail)
		{
			delete se->pTail;
			k->pNext = NULL;
			se->pTail = k;
			return;
		}
	}
}

bool deleteCourse(Semester * &se)
{
	char* ID;
	cout << "\tEnter The ID: ";
	cin.ignore();
	char temp2[100];
	cin.getline(temp2, 100);
	ID = new char[strlen(temp2) + 1];
	strcpy(ID, temp2);

	NODE* temp1 = NULL;
	for (NODE* temp = se->pHead; temp != NULL; temp = temp->pNext)
	{
		if (checkName(ID, temp->data->courseID))
		{
			if (temp == se->pHead)
			{
				deleteHead(se);
				return true;
			}
			else if (temp == se->pTail)
			{
				deleteTail(se);
				return true;
			}
			else
			{
				temp1->pNext = temp->pNext;
				delete temp;
				temp = temp1;
				return true;
			}
		}
		temp1 = temp;
	}
	return false;
}

//12 - 20
void initListStudent(listStudent & ls)
{
	ls.pHead = NULL;
	ls.pTail = NULL;
}

void initListCourse(listCourse & lc)
{
	lc.pHead = NULL;
	lc.pTail = NULL;
}

void enrollACourse(Semester * &se, Student * &st, listStudent & ls, listCourse & lc)
{
	cout << "Available courses for this semester\n";
	printList(se);

	char* courseID = new char;
	char* courseName = new char;
	int n;

	cout << endl << "Enter the number of course you want to enroll (maxium:5): ";
	do
	{
		cin >> n;
		if (n < 1 || n>5)
		{
			cout << "Wrong! Enter again!";
		}
	} while (n < 1 || n>5);

	for (int i = 0; i < n; i++)
	{
		cout << endl << "--------------------The " << i + 1 << "course --------------------" << endl;
		cout << "	Enter the ID of course: ";
		cin >> courseID;

		cout << "	Enter the name of course: ";
		cin >> courseName;

		for (NODE* k = se->pHead; k != NULL; k = k->pNext)
		{
			if (checkName(courseName, k->data->courseName) == true && checkName(courseID, k->data->courseID) == true)
			{
				if (lc.pHead == NULL)
				{
					cout << "		Enroll successfully!";
					Node* p = createNodeStudent(st);
					addTailStudent(ls, p);
					NODE* q = createNodeCourse(k->data);
					addTailCourse(lc, q);
				}
				else
				{
					if (checkExistingCourse(lc, k->data->firstDay, k->data->firstSession, k->data->secondDay, k->data->secondSession) == true)
					{
						cout << "\n Sorry! The course has the same sessions as the course you enrolled";
						i--;
					}
					else
					{
						cout << "		Enroll successfully!";
						Node* p = createNodeStudent(st);
						addTailStudent(ls, p);
						NODE* q = createNodeCourse(k->data);
						addTailCourse(lc, q);
					}
				}
					
			}
		}
	}

}

bool checkExistingCourse(listCourse& lc,int cFirstDay, int cFirstSession, int cSecondDay, int cSecondSession)
{
	for (NODE* g = lc.pHead; g != NULL; g = g->pNext)
	{
		if (cFirstDay == g->data->firstDay && cFirstSession == g->data->firstSession && cSecondDay == g->data->secondDay && cSecondSession == g->data->secondSession)
		{
			return true;
		}
		return false;
	}
}

void addTailStudent(listStudent & ls, Node * p)
{
	if (ls.pHead == NULL)
	{
		ls.pHead = ls.pTail = p;
	}
	else
	{
		ls.pTail->next = p;
		ls.pTail = p;
	}
}

void addTailCourse(listCourse & lc, NODE * k)
{
	if (lc.pHead == NULL)
	{
		lc.pHead = lc.pTail = k;
	}
	else
	{
		lc.pTail->pNext = k;
		lc.pTail = k;
	}
}

Node* createNodeStudent(Student * data)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "Cannot allocate!";
		return NULL;
	}
	p->data = data;
	p->next = NULL;

	return p;
}

void outputListOfEnrolledCourse(listCourse lc)
{
	int i = 1;
	cout << "\t\t The course you have enrolled" << endl;
	for (NODE* p = lc.pHead; p != NULL; p = p->pNext)
	{
		cout << "\t The " << i << " course:" << endl;
		outputCourse(p->data);
		cout << endl;
		i++;
	}
}

void deleteHeadCourse(listCourse & lc)
{
	if (lc.pHead == NULL)
	{
		return;
	}
	else
	{
		NODE* p = lc.pHead;
		lc.pHead = lc.pHead->pNext;
		delete p;
	}
}

void deleteTailCourse(listCourse & lc)
{
	if (lc.pHead == NULL)
	{
		return;
	}
	if (lc.pHead->pNext == NULL)
	{
		deleteHeadCourse(lc);
	}
	for (NODE* k = lc.pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == lc.pHead)
		{
			delete lc.pTail;
			k->pNext = NULL;
			lc.pTail = k;
		}
	}
}

void removeACourseFromEnrolledList(listCourse & lc)
{
	char* courseID = new char;
	char* courseName = new char;

	cout << "	Enter the ID of course you want to remove: ";
	cin >> courseID;
	cout << "	Enter the name of course you want to remove: ";
	cin >> courseName;

	if (checkName(courseName, lc.pHead->data->courseName) == true && checkName(courseID, lc.pHead->data->courseID) == true)
	{
		deleteHeadCourse(lc);
	}
	else if (checkName(courseName, lc.pTail->data->courseName) == true && checkName(courseID, lc.pTail->data->courseID) == true)
	{
		deleteTailCourse(lc);
	}
	else
	{
		NODE* g = new NODE;
		for (NODE* k = lc.pHead; k != NULL; k = k->pNext)
		{
			if (checkName(courseName, k->data->courseName) == true && checkName(courseID, k->data->courseID) == true)
			{
				g->pNext = k->pNext;
				delete k;
				k = g;
			}
			g = k;
		}
	}
}

void outputListOfYourCourse(listCourse lc)
{
	int i = 1;
	cout << "\t\t The course you have to study in this semester" << endl;
	for (NODE* p = lc.pHead; p != NULL; p = p->pNext)
	{
		cout << "\t The " << i << " course:" << endl;
		outputCourse(p->data);
		cout << endl;
	}
}

void outputListOfClasses(School_year * sy)
{
	int i = 1;
	cout << "--------------------THE INFORMATION CLASS OF THE SCHOOL YEAR--------------------\n";
	cout << "\tTHE BEGINNING YEAR: " << sy->theBeginningYear << endl;
	cout << "\tTHE ENDING YEAR: " << sy->theEndYear << endl << endl;
	for (Node_class* temp = sy->head; temp != NULL; temp = temp->next)
	{
		cout << "-----------------The class " << i << " -------------------\n";
		cout << "\t\tThe name class: " << temp->data->class_name << endl;
		Node* temp1 = temp->data->head;
		int j = 1;
		while (temp1 != NULL)
		{
			const char* ch = checkOrder(j);
			cout << "\n\t" << j << ch << " student" << endl;
			ouputInfoStudent(temp1->data);
			temp1 = temp1->next;
			cout << endl;
			j++;
		}
		i++;
	}
}

void outputListOfStudentInAClass(School_year * sy, char* name)
{
	int k = 0;
	for (Node_class* temp = sy->head; temp != NULL; temp = temp->next)
	{
		if (checkName(temp->data->class_name, name) == true)
		{
			k = 1;
			cout << "\t\tThe name class: " << temp->data->class_name << endl;
			Node* temp1 = temp->data->head;
			int j = 1;
			while (temp1 != NULL)
			{
				const char* ch = checkOrder(j);
				cout << "\n\t" << j << ch << " student" << endl;
				ouputInfoStudent(temp1->data);
				temp1 = temp1->next;
				cout << endl;
				j++;
			}
		}
	}
	if (k == 0)
	{
		cout << "Can not see the list student of class to look for. Classroom does not exist!";
	}
}

void outputListOfCourses(Semester* se)
{
	cout << "\n\t---------- LIST OF COURSE ----------" << endl;

	NODE* temp = se->pHead;
	int i = 1;
	if (temp != NULL)
	{
		for (temp = se->pHead; temp != NULL; temp = temp->pNext)
		{
			const char* ch = checkOrder(i);
			cout << "\n\t" << i << ch << " course " << endl;
			outputCourse(temp->data);
			cout << endl;
			i++;
		}
	}
	else
	{
		cout << "Empty list!\n";
	}
}

void outputListOfStudentsInACourse(listStudent ls)
{
	int i = 1;
	cout << "\t\t List of students in this course" << endl;
	for (Node* k = ls.pHead; k != NULL; k = k->next)
	{
		cout << endl << "Student number " << i << " :";
		ouputInfoStudent(k->data);
		cout << endl;
		i++;
	}
}

//21 - 25
void outputListOfStudentsInACourseToCSVfile(Semester*& se)
{
	char* courseID = new char;
	char* courseName = new char;

	ofstream ofile("ListStudentInACourse.csv");
	ofile << "No,";
	ofile << "Student ID,";
	ofile << "First Name,";
	ofile << "Last Name,";
	ofile << "Gender,";
	ofile << "Day of birth,";
	ofile << "Month of birth,";
	ofile << "Year of birth,";
	ofile << "Social ID,";
	ofile << "Total Mark,";
	ofile << "Final Mark,";
	ofile << "Midterm Mark,";
	ofile << "Other Mark\n";

	cout << "	Enter the ID of course: ";
	cin >> courseID;

	cout << "	Enter the name of course: ";
	cin >> courseName;

	for (NODE* k = se->pHead; k != NULL; k = k->pNext)
	{
		if (checkName(courseName, k->data->courseName) == true && checkName(courseID, k->data->courseID) == true)
		{
			for (Node* q = k->data->list_student.pHead; q != NULL; q = q->next)
			{
				ofile << q->data->no << ",";
				ofile << q->data->student_id << ",";
				ofile << q->data->first_name << ",";
				ofile << q->data->last_name << ",";
				ofile << q->data->gender << ",";
				ofile << q->data->day_of_birth << ",";
				ofile << q->data->month_of_birth << ",";
				ofile << q->data->year_of_birth << ",";
				ofile << q->data->social_id << "\n";
			}
		}
	}
	ofile.close();
}

void ImportTheScoreboardOfACourse(Semester*& se)
{
	char* courseID = new char;
	char* courseName = new char;

	ifstream ifile("ListStudentInACourse.csv");

	cout << "	Enter the ID of course: ";
	cin >> courseID;

	cout << "	Enter the name of course: ";
	cin >> courseName;


	for (NODE* k = se->pHead; k != NULL; k = k->pNext)
	{
		if (checkName(courseName, k->data->courseName) == true && checkName(courseID, k->data->courseID) == true)
		{
			//skip first line
			string skip_first_line;
			getline(ifile, skip_first_line, '\n');

			//read data
			Node* temp = k->data->list_student.pHead;

			while (ifile.good())
			{
				getline(ifile, temp->data->no, ',');
				getline(ifile, temp->data->student_id, ',');
				getline(ifile, temp->data->first_name, ',');
				getline(ifile, temp->data->last_name, ',');
				getline(ifile, temp->data->gender, ',');
				getline(ifile, temp->data->day_of_birth, ',');
				getline(ifile, temp->data->month_of_birth, ',');
				getline(ifile, temp->data->year_of_birth, ',');
				getline(ifile, temp->data->social_id, ',');
				getline(ifile, temp->data->score_board.totalMark, ',');
				getline(ifile, temp->data->score_board.finalMark, ',');
				getline(ifile, temp->data->score_board.midtermMark, ',');
				getline(ifile, temp->data->score_board.otherMark, '\n');
				temp = temp->next;
			}
		}
	}
	ifile.close();
}

void ViewScoreBoardInACourse(Semester*& se)
{
	char* courseID = new char;
	char* courseName = new char;

	cout << "------------------------------------------SCOREBOARD OF A COURSE-----------------------------------------------\n";
	cout << "	Enter the ID of course: ";
	cin >> courseID;

	cout << "	Enter the name of course: ";
	cin >> courseName;

	for (NODE* k = se->pHead; k != NULL; k = k->pNext)
	{
		if (checkName(courseName, k->data->courseName) == true && checkName(courseID, k->data->courseID) == true)
		{
			for (Node* i = k->data->list_student.pHead; i != NULL; i = i->next)
			{
				cout << "No: " << i->data->no << endl;
				cout << "\tStudent ID: " << i->data->student_id << endl;
				cout << "\tName: " << i->data->first_name << " " << i->data->last_name << endl;
				cout << "\tGender: " << i->data->gender << endl;
				cout << "\tBirth: " << i->data->day_of_birth << "/" << i->data->month_of_birth << "/" << i->data->year_of_birth << endl;
				cout << "\tSocial ID: " << i->data->social_id << endl;
				cout << "\t\tTotal Mark: " << i->data->score_board.totalMark << endl;
				cout << "\t\tFinal Mark: " << i->data->score_board.finalMark << endl;
				cout << "\t\tMidterm Mark: " << i->data->score_board.midtermMark << endl;
				cout << "\t\tOther Mark: " << i->data->score_board.otherMark << endl;
			}
		}
	}
}

void UpdateAStudentResult(Semester*& se)
{
	char* courseID = new char;
	char* courseName = new char;

	cout << "	Enter the ID of course: ";
	cin >> courseID;

	cout << "	Enter the name of course: ";
	cin >> courseName;

	for (NODE* k = se->pHead; k != NULL; k = k->pNext)
	{
		if (checkName(courseName, k->data->courseName) == true && checkName(courseID, k->data->courseID) == true)
		{
			string Student_ID;
			cout << "\tEnter the Student ID: "; cin >> Student_ID;
			for (Node* i = k->data->list_student.pHead; i != NULL; i = i->next)
			{
				if (Student_ID == i->data->student_id)
				{
					cout << "\t\tTotal Mark: "; cin >> i->data->score_board.totalMark;
					cout << "\t\tFinal Mark: "; cin >> i->data->score_board.finalMark;
					cout << "\t\tMidterm Mark: "; cin >> i->data->score_board.midtermMark;
					cout << "\t\tOther Mark: "; cin >> i->data->score_board.otherMark;
				}
				else if (Student_ID != i->data->student_id && i->next == NULL)
				{
					cout << "No Student ID matching\n";
				}
			}
		}
	}
}

void ViewTheScoreboardOfAClass(School_year* school, Semester*& se)
{
	int no = 0;

	float total_credits;
	float total_score;
	float overall_gpa = 0;

	char* class_name = new char;
	cout << "\tEnter the name of class: ";
	cin >> class_name;

	for (Node_class* i = school->head; i != NULL; i = i->next)
	{
		if (checkName(class_name, i->data->class_name) == true)
		{
			cout << "------------------------------------SCOREBOARD OF CLASS " << class_name << " ----------------------------------------\n";
			for (Node* k = i->data->head; i != NULL; i++)
			{
				cout << "No: " << no++ << endl;
				cout << "\tStudent ID: " << k->data->student_id << endl;
				cout << "\tFullname: " << k->data->first_name << " " << k->data->last_name << endl;

				total_credits = 0;
				total_score = 0;

				for (NODE* c = se->pHead; c != NULL; c = c->pNext)
				{
					for (Node* l = c->data->list_student.pHead; l != NULL; l = l->next)
					{
						if (l->data->student_id == k->data->student_id)
						{
							cout << "\t\tCourse: " << c->data->courseName << endl;
							cout << "\t\t\Total Mark: " << l->data->score_board.totalMark << endl;
							total_credits += c->data->numberCredits;
							total_score += (c->data->numberCredits * atof(l->data->score_board.totalMark.c_str()));
						}
					}
				}
				cout << endl;
				overall_gpa += total_score / total_credits;
				cout << "\tGPA in semester " << se->createASemester << ": " << total_score / total_credits << endl;
			}
			overall_gpa = overall_gpa / (no + 1);

			cout << "---------------------------------------------------------" << endl;
			cout << "  OVERALL GPA OF " << class_name << ": " << overall_gpa << endl;
			cout << "---------------------------------------------------------" << endl;
		}
	}
}

void ViewScoreboardOfAStudent(Semester*& se, Student*& st)
{
	float total_credits = 0;
	float total_score = 0;
	cout << "Scoreboard of " << st->last_name << " in this semester\n";

	for (NODE* c = se->pHead; c != NULL; c = c->pNext)
	{
		for (Node* l = c->data->list_student.pHead; l != NULL; l = l->next)
		{
			if (l->data->student_id == st->student_id)
			{
				cout << "\tCourse: " << c->data->courseName << endl;
				cout << "\t\tTotal Mark: " << l->data->score_board.totalMark << endl;
				cout << "\t\tFinal Mark: " << l->data->score_board.finalMark << endl;
				cout << "\t\tMidterm Mark: " << l->data->score_board.midtermMark << endl;
				cout << "\t\tOther Mark: " << l->data->score_board.otherMark << endl;
				total_credits += c->data->numberCredits;
				total_score += (c->data->numberCredits * atof(l->data->score_board.totalMark.c_str()));
			}
			cout << endl;
			cout << "GPA in semester " << se->createASemester << ": " << total_score / total_credits << endl;
		}
	}
}

void menu(School_year* school, Semester* se, course* c, Student* st, listStudent ls, listCourse lc)
{
	int type;
	cout << "Choose 1 if you are staff members\n";
	cout << "Choose 2 if you are student\n";
	cout << "Choose 3 if you want to exit\n";
	cout << "Your choice: ";
	cin >> type;

	int choice1;
	int choice2;

	if (type == 1)
	{
		system("cls");
		cout << "----------Staff Member----------\n";
		cout << "1.  Create a school year (2020-2021, for example)\n";
		cout << "2.  Create several classes for 1st year students. For example: class 20APCS1, class 20APCS2, class 20CLC1..., class 20CLC11, class 20VP...\n";
		cout << "3.  Add new 1st year students to 1st-year classes\n";
		cout << "4.  He/she want to import a CSV file containing all students in a specific class to the system.\n";
		cout << "5.  He/she want to see list student.\n";
		cout << "51. He/she want to see all classes\n";
		cout << "52. He/she want to remove the class.\n";
		cout << "6.  Create a semester.\n";
		cout << "7.  Create a course registration session.\n";
		cout << "8.  Add a course to this semester.\n";
		cout << "9.  View list of courses.\n";
		cout << "10. Update course information.\n";
		cout << "11. Delete a course.\n";
		cout << "21. Export list of students in a course to a CSV file\n";
		cout << "22. Import CSV file to the scoreboard of a course.\n";
		cout << "23. View the scoreboard of a course.\n";
		cout << "24. Update a student result.\n";
		cout << "25. View the scoreboard of a class.\n";
		cout << "0.  Log out.\n";

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
			case 52:
			{
				removeClass(school);
				break;
			}
			case 6:
			{
				createSemester(se);
				break;
			}
			case 7:
			{
				session ss;
				createACourseRegistrationSession(se, ss);
				break;
			}
			case 8:
			{
				c = new course;
				c = createACourse(se, c);
				break;
			}
			case 9:
			{
				printList(se);
				break;
			}
			case 10:
			{
				updateInformation(se);
				break;
			}
			case 11:
			{
				deleteCourse(se);
				break;
			}
			case 21:
			{
				outputListOfStudentsInACourseToCSVfile(se);
				break;
			}
			case 22:
			{
				ImportTheScoreboardOfACourse(se);
				break;
			}
			case 23:
			{
				ViewScoreBoardInACourse(se);
				break;
			}
			case 24:
				UpdateAStudentResult(se);
				break;
			case 25:
			{
				ViewTheScoreboardOfAClass(school, se);
				break;
			}
			case 0:
			{
				menu(school, se, c, st, ls, lc);
			}
			}
		} while (choice1 != 0);
	}

	if (type == 2)
	{
		system("cls");
		cout << "----------Student----------\n";
		cout << "0. Exit\n";
		cout << "1.  Register\n";
		cout << "2.  Log in\n";
		cout << "3.  Change password\n";
		cout << "4.  Logout\n";
		cout << "13. Enroll in a course.\n";
		cout << "14. View list of enrolled courses.\n";
		cout << "15. Remove a course from the enrolled list.\n";
		cout << "16. View list of his/her courses. He/she will study these courses in this semester.\n";
		cout << "17. View list of classes.\n";
		cout << "18. View list of students in a class (for example, 20APCS1...)\n";
		cout << "19. View list of courses.\n";
		cout << "20. View list of students in a course.\n";
		cout << "26. View your scoreboard.\n";

		do
		{
			cout << "\nYour choice: ";
			cin >> choice2;

			switch (choice2)
			{
			case 0:
			{
				menu(school, se, c, st, ls, lc);
			}
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
			case 26:
			{
				ViewScoreboardOfAStudent(se, st);
				break;
			}
			}
		} while (choice2 != 4);
	}

	if (type == 3)
	{
		return;
	}
}