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

void enrollACourse(Semester*& se, Student*& st, listStudent& ls, listCourse& lc)
{
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
				cout << "		Enroll successfully!";
				Node* p = createNodeStudent(st);
				addTailStudent(ls, p);
				NODE* q = createNodeCourse(k->data);
				addTailCourse(lc, q);
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
