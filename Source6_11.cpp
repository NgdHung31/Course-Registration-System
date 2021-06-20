#include "Header6_11.h"

bool checkDate(int day, int month, int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // nam nhuan
	{
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 0 && day < 31))
		{
			return true;
		}
		if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 0 && day < 30))
		{
			return true;
		}
		if (month == 2 && (day > 0 || day < 29))
		{
			return true;
		}
		return false;
	}
	else // khong phai nam nhuan
	{
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 0 && day < 32))
		{
			return true;
		}
		if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 0 && day < 31))
		{
			return true;
		}
		if (month == 2 && (day > 0 && day < 30))
		{
			return true;
		}
		return false;
	}
}

void createList(LIST*& l)
{
	l = new LIST;
	l->pHead = l->pTail = NULL;
}


NODE* createNODE(course* data)
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

semester* createSemester()
{
	cout << "------------------------------------------------CREATE YOUR SEMESTER:---------------------------------------------------" << endl;
	semester* s = new semester;
	cout << "Let's create a semester: 1, 2, or 3: ";
	cin >> s->createASemester;

	if (1 <= s->createASemester && s->createASemester <= 3)
	{
		cout << "\nNow, your semester is " << s->createASemester << ".";
		do
		{
			cout << "\nEnter the school year: ";
			cin >> s->schoolYear;
			if (s->schoolYear < 2021)
			{
				cout << "FAULT!!! PLEASE RE-ENTER." << endl;
			}
		} while (s->schoolYear < 2021);

		cout << "Enter the start date semester: " << endl;
		do
		{
			cout << '\t' << "Day: ";
			cin >> s->startDay;
			cout << '\t' << "Month: ";
			cin >> s->startMonth;
			if (checkDate(s->startDay, s->startMonth, s->schoolYear) == false)
			{
				cout << "FAULT!!! PLEASE RE-ENTER." << endl;
			}
		} while (checkDate(s->startDay, s->startMonth, s->schoolYear) == false);

		cout << "Enter the end date semester: " << endl;
		do
		{
			cout << '\t' << "Day: ";
			cin >> s->endDay;
			cout << '\t' << "Month: ";
			cin >> s->endMonth;
			if (checkDate(s->endDay, s->endMonth, s->schoolYear) == false)
			{
				cout << "FAULT!!! PLEASE RE-ENTER." << endl;
			}
		} while (checkDate(s->endDay, s->endMonth, s->schoolYear) == false);
	}
	else
	{
		cout << "FAULT! PLEASE RE-ENTER: ";
		cin >> s->createASemester;
	}

	createList(s->listCourses);

	return s;
}
bool check_start_date_in_course(int day_course, int month_course, int day_semester, int month_semester)
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

bool check_end_date_in_course(int day_course, int month_course, int day_semester, int month_semester)
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

course* registrationSession(semester*& se, int year)
{
	cout << "\n-------------------------------------------COURSE REGISTRATION DEADLINE:-----------------------------------------------" << endl;
	course* rs = new course;

	cout << "Let's create a course registration session." << endl;

	cout << "Enter the start date course registration session: " << endl;
	do
	{
		cout << '\t' << "Day: ";
		cin >> rs->startDay0;
		cout << '\t' << "Month: ";
		cin >> rs->startMonth0;
		if (checkDate(rs->startDay0, rs->startMonth0, year) == false)
		{
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
		else if (check_start_date_in_course(rs->startDay0, rs->startMonth0, se->startDay, se->startMonth) == false) {
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
	} while (checkDate(rs->startDay0, rs->startMonth0, year) == false || check_start_date_in_course(rs->startDay0, rs->startMonth0, se->startDay, se->startMonth) == false);
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
		else if (check_end_date_in_course(rs->endDay0, rs->endMonth0, se->endDay, se->endMonth) == false) {
			cout << "FAULT!!! PLEASE RE-ENTER." << endl;
		}
	} while (checkDate(rs->endDay0, rs->endMonth0, rs->endYear0) == false || check_end_date_in_course(rs->endDay0, rs->endMonth0, se->endDay, se->endMonth) == false);

	return rs;
}

course* createCourse()
{
	cout << "------------------------------------------------CREATE YOUR COURSE:----------------------------------------------------" << endl;
	course* c = new course;

	cout << "Enter the ID of course: ";
	cin >> c->courseID;

	cin.ignore();
	char temp[100];
	cout << "Enter the name of course: ";
	cin.getline(temp, 100);
	c->courseName = new char[strlen(temp) + 1];
	strcpy(c->courseName, temp);

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

	cin.ignore();
	do
	{
		cout << "The second day: ";
		cin >> c->secondDay;
		if (c->firstDay < 2 || c->firstDay > 7)
		{
			cout << "FAULT! PLEASE RE-ENTER" << endl;
		}
	} while (c->firstDay < 2 || c->firstDay > 7);

	do 
	{
		cout << "The session: S";
		cin >> c->secondSession;
		if (c->firstSession < 1 || c->firstSession > 4)
		{
			cout << "FAULT! PLEASE RE-ENTER" << endl;
		}
	} while (c->firstSession < 1 || c->firstSession > 4);

	return c;
}

void addTail(course* c, LIST*& l)
{
	NODE* newnode = createNODE(c);
	if (l->pHead == NULL)
		l->pHead = l->pTail = newnode;
	else
	{
		NODE* temp = l->pHead;
		while (temp->pNext != NULL)
		{
			temp = temp->pNext;		
		}
		temp->pNext = newnode;
	}
}

const char* convert_day(int day)
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

const char* convert_session(int session)
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

void printList(LIST* l)
{
	cout << "\n\t********************YOUR COURSE:************************" << endl;
	NODE* temp = l->pHead;
	if (temp != NULL)
	{
		for (/*temp = l->pHead*/; temp != NULL; temp = temp->pNext)
		{
			cout << "The ID of course: " << temp->data->courseID << endl;
			cout << "The name of course: " << temp->data->courseName << endl;
			cout << "The name of teacher: " << temp->data->teacherName << endl;
			cout << "The number of credits: " << temp->data->numberCredits << endl;
			cout << "The maximum number of students in the course (default 50): " << temp->data->maxStudentCourse << endl;
			cout << '\t' << "The FRIST day: " << convert_day(temp->data->firstDay) << endl;
			cout << '\t' << "The FRIST session: " << convert_session(temp->data->firstSession) << endl;
			cout << '\t' << "The SECOND day: " << convert_day(temp->data->secondDay) << endl;
			cout << '\t' << "The SECOND session: " << convert_session(temp->data->secondSession) << endl;
			cout << endl;
		}
	}
	else
	{
		cout << "Empty list!\n";
	}
}

void addNode_p_AfterNode_q(course* c, LIST*& l, int& x, NODE* p)
{
	c = new course;
	c = createCourse();
	p = createNODE(c);
	for (NODE* k = l->pHead; k != NULL; k = k->pNext)
	{
		if (k->data->courseID == x)
		{
			NODE* g = p;
			g->pNext = k->pNext; 
			k->pNext = g; 
		}
	}
}

void deleteHead(LIST*& l)
{
	if (l->pHead == NULL)
	{
		return;
	}
	NODE* p = l->pHead;
	l->pHead = l->pHead->pNext;
	delete p;
}

void deleteTail(LIST*& l)
{
	if (l->pHead == NULL)
	{
		return;
	}
	if (l->pHead->pNext == NULL)
	{
		deleteHead(l);
		return;
	}
	for (NODE* k = l->pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == l->pTail)
		{
			delete l->pTail;
			k->pNext = NULL;
			l->pTail = k;
			return;
		}
	}
}

void deleteCourse(LIST*& l, int& x)
{	
	/*for (NODE* h = l->pHead; h != NULL; h = h->pNext)
	{
		if (h->data->courseID != x)
		{
			cout << "ERROR, PLEASE RE-ENTER YOUR ID-COURSE EXACTLY!!!";
			return;
		}
	}*/
	
	if (l->pHead == NULL)
	{
		cout << "Nothing to delete!!!";
	}
	else
	{
		if (l->pHead->data->courseID == x)
		{
			deleteHead(l);
			return;
		}
		if (l->pTail->data->courseID == x)
		{
			deleteTail(l);
			return;
		}

		NODE* g = new NODE;
		for (NODE* k = l->pHead; k != NULL; k = k->pNext)
		{
			if (k->data->courseID == x)
			{
				g->pNext = k->pNext;
				delete k;
				return;
			}
			g = k;
		}
	}
}


