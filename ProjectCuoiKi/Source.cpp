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

bool checkStartDateInCourse(int day_course, int month_course, int day_semester, int month_semester)
{
	if (month_course < month_semester)
	{
		return false;
	}
	else if (month_course = month_semester)
	{
		if (day_course < day_semester)
		{
			return false;
		}
	}
	return true;
}

bool checkEndDateInCourse(int day_course, int month_course, int day_semester, int month_semester)
{
	if (month_course > month_semester) {
		return false;
	}
	else if (month_course = month_semester)
	{
		if (day_course > day_semester)
		{
			return false;
		}
	}
	return true;
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

// 1 - 5
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
	cout << "\tTHE BEGINNING YEAR: " << sy->the_beginning_year << endl;
	cout << "\tTHE ENDING YEAR: " << sy->the_end_year << endl << endl;
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

void removeHeadClass(Class*& cl)
{
	if (cl->head == NULL)
	{
		return;
	}
	else
	{
		Node* p = cl->head;
		cl->head = cl->head->next;
		delete p;
	}
}

void removeTailClass(Class*& cl)
{
	if (cl->head == NULL)
	{
		return;
	}
	if (cl->head->next == NULL)
	{
		removeHeadClass(cl);
	}
	else
	{
		for (Node* k = cl->head; k != NULL; k = k->next)
		{
			if (k->next == cl->tail)
			{
				delete cl->tail;
				k->next = NULL;
				cl->tail = k;
			}
		}
	}

}

bool removeStudent(School_year*& sy)
{
	char* name;
	enterTheName(name);
	for (Node_class* temp = sy->head; temp != NULL; temp = temp->next)
	{
		if (checkName(temp->data->class_name, name))
		{
			Class* cl = temp->data;
			Node* temp2 = new Node;
			char* firstname;
			cout << "The first name_";
			enterTheName(firstname);
			char* lastname;
			cout << "The last name_";
			enterTheName(lastname);
			for (Node* temp1 = cl->head; temp1 != NULL; temp1 = temp1->next)
			{
				if (temp1->data->first_name.compare(firstname) == 0)
				{
					if (temp1->data->last_name.compare(lastname) == 0)
					{
						if (temp1 == cl->head)
						{
							removeHeadClass(cl);
							return true;
						}
						else if (temp1 == cl->tail)
						{
							removeTailClass(cl);
							return true;
						}
						else
						{
							temp2->next = temp1->next;
							delete temp1;
							temp1 = temp2;
							return true;
						}
					}
				}
					temp2 = temp1;
			}
			return false;
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

course* createACourseRegistrationSession(Semester* se, course* c)
{
	cout << "\n-------------------------------------------COURSE REGISTRATION DEADLINE:-----------------------------------------------" << endl;
	cout << "\t\t\t\t\t\tSEMESTER " << se->createASemester << endl;
	cout << "\t\t\t\t\t\t" << se->startDay << "/" << se->startMonth << " - " << se->endDay << "/" << se->endMonth << endl;
	cout << "\nLet's create a course registration session." << endl;

	cout << "Enter the start date course registration session: " << endl;
	do
	{
		cout << '\t' << "Day: ";
		cin >> c->startDay0;
		cout << '\t' << "Month: ";
		cin >> c->startMonth0;
		if (checkDate(to_string(c->startDay0), to_string(c->startMonth0), to_string(se->schoolYear)) == false)
		{
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
		else if (checkStartDateInCourse(c->startDay0, c->startMonth0, se->startDay, se->startMonth) == false) {
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
	} while (checkDate(to_string(c->startDay0), to_string(c->startMonth0), to_string(se->schoolYear)) == false || checkStartDateInCourse(c->startDay0, c->startMonth0, se->startDay, se->startMonth) == false);
	cout << "Enter the end date course registration session: " << endl;
	do
	{
		cout << '\t' << "Day: ";
		cin >> c->endDay0;
		cout << '\t' << "Month: ";
		cin >> c->endMonth0;
		if (checkDate(to_string(c->endDay0), to_string(c->endMonth0), to_string(se->schoolYear)) == false)
		{
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
		else if (checkEndDateInCourse(c->endDay0, c->endMonth0, se->endDay, se->endMonth) == false) {
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
	} while (checkDate(to_string(c->endDay0), to_string(c->endMonth0), to_string(se->schoolYear)) == false || checkEndDateInCourse(c->endDay0, c->endMonth0, se->endDay, se->endMonth) == false);
	return c;
}
 
void addACourseToThisSemester(Semester*& se, course* c)
{
	cout << "------------------------------------------------CREATE YOUR COURSE:----------------------------------------------------" << endl;

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
}

void outputCourse(course* c)
{
	cout << "\tThe ID of course: " << c->courseID << endl;
	cout << "\tThe name of course: " << c->courseName << endl;
	cout << "\tThe name of teacher: " << c->teacherName << endl;
	cout << "\tThe number of credits: " << c->numberCredits << endl;
	cout << "\tThe maximum number of students in the course (default 50): " << c->maxStudentCourse << endl;
	cout << "\ta course registration session: " << c->startDay0 << "/" << c->startMonth0 << " - " << c->endDay0 << "/" << c->endMonth0 << endl;
	cout << "\t\tThe FRIST day: " << convertDay(c->firstDay) << endl;
	cout << "\t\tThe FRIST session: " << convertSession(c->firstSession) << endl;
	cout << "\t\tThe SECOND day: " << convertDay(c->secondDay) << endl;
	cout << "\t\tThe SECOND session: " << convertSession(c->secondSession) << endl;
}

void printList(Semester*& se)
{
	cout << "\n\t********************VIEW LIST OF COURSE************************" << endl;
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

//**
void updateInformation(Semester*& se)
{
	char* ID;
	int choice;
	cout << "--------------------------------------------------UPDATE YOUR COURSE INFORMATION:---------------------------------------------------";

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
			cout << "--------------------------------------------------What would you like to have updated in the course?--------------------------------------------------\n";
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
			}
		}
	}
}

//12-20
void initListStudent(listStudent& ls)
{
	ls.pHead = NULL;
	ls.pTail = NULL;
}

void initListCourse(listCourse& lc)
{
	lc.pHead = NULL;
	lc.pTail = NULL;
}

void enrollACourse(Semester*& se, Student *&st,listStudent &ls, listCourse& lc)
{
	char* courseID = new char;
	char* courseName=new char;
	int n;

	cout <<endl<< "Enter the number of course you want to enroll (maxium:5): ";
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
				for (NODE* i = lc.pHead; i != NULL; i = i->pNext)
				{
					//Xét trường hợp đã đăng ký rồi
					if (checkName(courseName, i->data->courseName) == false && checkName(courseID, i->data->courseID) == false)
					{
						cout << "		Enroll successfully !";
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

void addTailStudent(listStudent& ls, Node* p)
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

void addTailCourse(listCourse& lc, NODE* k)
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

Node* createNodeStudent(Student* data)
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
	}
}

void deleteHeadCourse(listCourse& lc)
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

void deleteTailCourse(listCourse& lc)
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

void removeACourseFromEnrolledList(listCourse& lc)
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

void outputListOfClasses(School_year* sy)
{
	int i = 1;
	cout << "---------------THE INFORMATION CLASS OF THE SCHOOL YEAR---------------\n";
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

void outputListOfStudentInAClass(School_year* sy, char* name)
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